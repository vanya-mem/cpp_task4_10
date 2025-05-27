#pragma once
#include <fstream>
#include <mutex>
#include <string>

enum class LogLevel { INFO, WARNING, ERR };  // ERR גלוסעמ ERROR

class Logger {
private:
    static std::ofstream logFile;
    static std::mutex logMutex;

    static std::string getTimestamp();
    static std::string levelToStr(LogLevel level);

public:
    static bool init(const std::string& filename);
    static void log(const std::string& message, LogLevel level);
    static void close();
};