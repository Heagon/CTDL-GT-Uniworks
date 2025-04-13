#pragma once
#include <vector>
#include <string>
#include <bitset>
#include <stdexcept>

namespace Converters {

    // Chuyển vector<unsigned char> sang chuỗi bit (mỗi byte thành 8 bit)
    inline std::string BytesToBits(const std::vector<unsigned char>& data) {
        std::string bits;
        for (unsigned char byte : data) {
            bits += std::bitset<8>(byte).to_string(); // Chuyển mỗi byte thành 8 bit
        }
        return bits;
    }

    // Chuyển chuỗi bit sang vector<unsigned char> (8 bit = 1 byte)
    inline std::vector<unsigned char> BitsToBytes(const std::string& bits) {
        // Kiểm tra độ dài chuỗi bit có chia hết cho 8
        if (bits.size() % 8 != 0) {
            throw std::runtime_error("Chuoi bit khong hop le (do dai khong chia het cho 8)");
        }

        std::vector<unsigned char> bytes;
        for (size_t i = 0; i < bits.size(); i += 8) {
            // Lấy 8 bit liên tiếp
            std::string byte_str = bits.substr(i, 8);
            
            // Chuyển chuỗi 8 bit thành byte
            unsigned char byte = static_cast<unsigned char>(
                std::bitset<8>(byte_str).to_ulong()
            );
            
            bytes.push_back(byte);
        }
        return bytes;
    }
}