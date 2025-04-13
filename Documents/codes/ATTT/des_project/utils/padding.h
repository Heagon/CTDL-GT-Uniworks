#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

inline void addPadding(std::vector<unsigned char>& data, size_t blockSize = 8) {
    size_t padLen = blockSize - (data.size() % blockSize);
    if (padLen == 0) padLen = blockSize;
    for (size_t i = 0; i < padLen; ++i) {
        data.push_back(static_cast<unsigned char>(padLen));
    }
}

inline void removePadding(std::vector<unsigned char>& data) {
    if (data.empty()) return;
    size_t padLen = data.back();
    if (padLen > data.size()) {
        throw std::runtime_error("Loi padding");
    }
    data.resize(data.size() - padLen);
}