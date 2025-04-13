#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

inline std::vector<unsigned char> readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file) throw std::runtime_error("Khong the mo file " + filename);
    
    const auto size = file.tellg();
    file.seekg(0, std::ios::beg);
    
    std::vector<unsigned char> buffer(size);
    if (!file.read(reinterpret_cast<char*>(buffer.data()), size)) {
        throw std::runtime_error("Loi doc file " + filename);
    }
    return buffer;
}

inline void writeFile(const std::string& filename, const std::vector<unsigned char>& data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) throw std::runtime_error("Khong the ghi file " + filename);
    file.write(reinterpret_cast<const char*>(data.data()), data.size());
}