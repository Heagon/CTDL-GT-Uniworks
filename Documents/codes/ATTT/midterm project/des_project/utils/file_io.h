#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iterator>

inline std::vector<unsigned char> readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) throw std::runtime_error("Khong the mo file " + filename);
    return {std::istreambuf_iterator<char>(file), {}};
}

inline void writeFile(const std::string& filename, const std::vector<unsigned char>& data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) throw std::runtime_error("Khong the ghi file " + filename);
    file.write(reinterpret_cast<const char*>(data.data()), data.size());
}