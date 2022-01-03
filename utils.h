#pragma once

#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>


template<typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& v) {
    for (unsigned i = 0; i < v.size(); ++i) {
        if (i != 0) {
            out << ", ";
        }
        out << v[i];
    }
    return out;
}


template<typename T>
std::ostream& operator << (std::ostream& out, const std::set<T>& v) {
    bool first = true;
    for (const T& element: v) {
        if (!first) {
            out << ", ";
        }
        first = false;
        out << element;
    }
    return out;
}


template<typename T>
std::ostream& operator << (std::ostream& out, const std::unordered_set<T>& v) {
    bool first = true;
    for (const T& element: v) {
        if (!first) {
            out << ", ";
        }
        first = false;
        out << element;
    }
    return out;
}


void writeIntoFile(const std::string& file_name, const std::string& s);
void removeFile(const std::string& file_name);

