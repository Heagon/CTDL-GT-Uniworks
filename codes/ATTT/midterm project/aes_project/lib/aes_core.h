#pragma once
#include <vector>
#include <array>

namespace AES {
    // Main functions
    void Encrypt(
        const std::vector<unsigned char>& plaintext,
        const std::vector<unsigned char>& key,
        std::vector<unsigned char>& ciphertext
    );

    void Decrypt(
        const std::vector<unsigned char>& ciphertext,
        const std::vector<unsigned char>& key,
        std::vector<unsigned char>& plaintext
    );

    // Core transformations
    void SubBytes(std::array<unsigned char, 16>& block);
    void ShiftRows(std::array<unsigned char, 16>& block);
    void MixColumns(std::array<unsigned char, 16>& block);
    void AddRoundKey(std::array<unsigned char, 16>& block, const std::array<unsigned char, 16>& roundKey);

    // Inverse transformations
    void InvSubBytes(std::array<unsigned char, 16>& block);
    void InvShiftRows(std::array<unsigned char, 16>& block);
    void InvMixColumns(std::array<unsigned char, 16>& block);

    // Key expansion
    void KeyExpansion(
        const std::vector<unsigned char>& key,
        std::array<std::array<unsigned char, 16>, 11>& roundKeys
    );

    // Padding
    void PaddingPKCS7(std::vector<unsigned char>& data);
}