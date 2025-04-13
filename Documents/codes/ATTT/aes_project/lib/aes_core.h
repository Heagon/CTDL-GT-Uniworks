#pragma once
#include <vector>

namespace AES {
    void Encrypt(
        const std::vector<unsigned char>& plaintext,
        const std::vector<unsigned char>& key,
        std::vector<unsigned char>& ciphertext
    );

    // Các hàm phụ trợ
    void SubBytes(std::array<unsigned char, 16>& block);
    void ShiftRows(std::array<unsigned char, 16>& block);
    void MixColumns(std::array<unsigned char, 16>& block);
    void AddRoundKey(std::array<unsigned char, 16>& block, const std::array<unsigned char, 16>& roundKey);
}