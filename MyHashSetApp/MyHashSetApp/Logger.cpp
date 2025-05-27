#include "pch.h"
#include "Logger.h"
#include <ctime>
#include <fstream>
#include <mutex>

std::ofstream Logger::logFile;
std::mutex Logger::logMutex;

bool Logger::init(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    return logFile.is_open();
}

std::string Logger::getTimestamp() {
    time_t now = time(nullptr);
    char buf[64];
    tm timeStruct;
    localtime_s(&timeStruct, &now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timeStruct);
    return buf;
}

std::string Logger::levelToStr(LogLevel level) {
    switch (level) {
    case LogLevel::INFO: return "INFO";
    case LogLevel::WARNING: return "WARNING";
    case LogLevel::ERR: return "ERROR";
    }
    return "UNKNOWN";
}

void Logger::log(const std::string& message, LogLevel level) {
    std::lock_guard<std::mutex> guard(logMutex);
    if (!logFile.is_open()) return;
    logFile << getTimestamp() << " [" << levelToStr(level) << "] " << message << "\n";
    logFile.flush();
}

void Logger::close() {
    if (logFile.is_open()) logFile.close();
}