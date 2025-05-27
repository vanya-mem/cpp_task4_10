#pragma once
#include <unordered_set>
#include <string>
#include "pch.h"


class HashSet {
public:
    using Iterator = std::unordered_set<std::string>::iterator;

private:
    std::unordered_set<std::string> set;

public:
    void add(const std::string& word) { set.insert(word); }
    bool contains(const std::string& word) const { return set.count(word) > 0; }

    Iterator begin() { return set.begin(); }
    Iterator end() { return set.end(); }
};
