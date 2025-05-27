#pragma once
#include <string>
#include <algorithm>
#include "pch.h"


inline bool isPalindrome(const std::string& s) {
    return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

inline bool shorterThanFive(const std::string& s) {
    return s.length() < 5;
}
