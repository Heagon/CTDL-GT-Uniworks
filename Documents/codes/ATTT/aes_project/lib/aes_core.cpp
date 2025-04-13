#include "aes_core.h"
#include "constants.h"
#include <array>
#include <algorithm>
#include <stdexcept>

namespace AES {
    // Padding
    void PaddingPKCS7(std::vector<unsigned char>& data) {
        size_t padding = 16 - (data.size() % 16);
        data.insert(data.end(), padding, static_cast<unsigned char>(padding));
    }

    // Key Expansion
    void KeyExpansion(const std::vector<unsigned char>& key, 
                    std::array<std::array<unsigned char, 16>, 11>& roundKeys) {
        if (key.size() < 16) throw std::runtime_error("Key phai it nhat 16 byte");
        std::copy_n(key.begin(), 16, roundKeys[0].begin());

        for (int i = 1; i <= 10; ++i) {
            auto& prev = roundKeys[i-1];
            auto& curr = roundKeys[i];

            unsigned char temp[4] = {
                sbox[prev[13]],
                sbox[prev[14]],
                sbox[prev[15]],
                sbox[prev[12]]
            };
            temp[0] ^= rcon[i-1];

            for (int j = 0; j < 4; ++j) {
                curr[j] = prev[j] ^ temp[j];
                curr[j+4] = prev[j+4] ^ curr[j];
                curr[j+8] = prev[j+8] ^ curr[j+4];
                curr[j+12] = prev[j+12] ^ curr[j+8];
            }
        }
    }

    // Core Transformations (Encrypt)
    void SubBytes(std::array<unsigned char, 16>& block) {
        for (auto& byte : block) byte = sbox[byte];
    }

    void ShiftRows(std::array<unsigned char, 16>& block) {
        unsigned char temp = block[1];
        block[1] = block[5];
        block[5] = block[9];
        block[9] = block[13];
        block[13] = temp;

        std::swap(block[2], block[10]);
        std::swap(block[6], block[14]);

        temp = block[15];
        block[15] = block[11];
        block[11] = block[7];
        block[7] = block[3];
        block[3] = temp;
    }

    void MixColumns(std::array<unsigned char, 16>& block) {
        for (int i = 0; i < 4; ++i) {
            unsigned char s0 = block[4*i];
            unsigned char s1 = block[4*i+1];
            unsigned char s2 = block[4*i+2];
            unsigned char s3 = block[4*i+3];
            
            block[4*i]   = mul2(s0) ^ mul3(s1) ^ s2 ^ s3;
            block[4*i+1] = s0 ^ mul2(s1) ^ mul3(s2) ^ s3;
            block[4*i+2] = s0 ^ s1 ^ mul2(s2) ^ mul3(s3);
            block[4*i+3] = mul3(s0) ^ s1 ^ s2 ^ mul2(s3);
        }
    }

    void AddRoundKey(std::array<unsigned char, 16>& block, 
                   const std::array<unsigned char, 16>& roundKey) {
        for (int i = 0; i < 16; ++i) block[i] ^= roundKey[i];
    }

    // Inverse Transformations (Decrypt)
    void InvSubBytes(std::array<unsigned char, 16>& block) {
        for (auto& byte : block) byte = inv_sbox[byte];
    }

    void InvShiftRows(std::array<unsigned char, 16>& block) {
        // Reverse ShiftRows
        unsigned char temp = block[13];
        block[13] = block[9];
        block[9] = block[5];
        block[5] = block[1];
        block[1] = temp;

        std::swap(block[2], block[10]);
        std::swap(block[6], block[14]);

        temp = block[3];
        block[3] = block[7];
        block[7] = block[11];
        block[11] = block[15];
        block[15] = temp;
    }

    void InvMixColumns(std::array<unsigned char, 16>& block) {
        for (int i = 0; i < 4; ++i) {
            unsigned char s0 = block[4*i];
            unsigned char s1 = block[4*i+1];
            unsigned char s2 = block[4*i+2];
            unsigned char s3 = block[4*i+3];
            
            block[4*i]   = mul14(s0) ^ mul11(s1) ^ mul13(s2) ^ mul9(s3);
            block[4*i+1] = mul9(s0) ^ mul14(s1) ^ mul11(s2) ^ mul13(s3);
            block[4*i+2] = mul13(s0) ^ mul9(s1) ^ mul14(s2) ^ mul11(s3);
            block[4*i+3] = mul11(s0) ^ mul13(s1) ^ mul9(s2) ^ mul14(s3);
        }
    }
    // Main Encryption/Decryption
    void Encrypt(const std::vector<unsigned char>& plaintext,
                const std::vector<unsigned char>& key,
                std::vector<unsigned char>& ciphertext) {
        if (key.size() < 16) throw std::runtime_error("Key phai co it nhat 16 byte");
        
        // Thêm padding
        std::vector<unsigned char> padded = plaintext;
        PaddingPKCS7(padded);

        // Tạo round keys
        std::array<std::array<unsigned char, 16>, 11> roundKeys;
        KeyExpansion(key, roundKeys);

        ciphertext.clear();
        
        // Mã hóa từng block
        for (size_t i = 0; i < padded.size(); i += 16) {
            std::array<unsigned char, 16> block;
            std::copy_n(padded.begin() + i, 16, block.begin());

            AddRoundKey(block, roundKeys[0]);
            for (int round = 1; round <= 9; ++round) {
                SubBytes(block);
                ShiftRows(block);
                MixColumns(block);
                AddRoundKey(block, roundKeys[round]);
            }
            SubBytes(block);
            ShiftRows(block);
            AddRoundKey(block, roundKeys[10]);

            ciphertext.insert(ciphertext.end(), block.begin(), block.end());
        }
    }

    void Decrypt(const std::vector<unsigned char>& ciphertext,
                const std::vector<unsigned char>& key,
                std::vector<unsigned char>& plaintext) {
        if (key.size() < 16) throw std::runtime_error("Key phai co it nhat 16 byte");
        
        // Tạo round keys
        std::array<std::array<unsigned char, 16>, 11> roundKeys;
        KeyExpansion(key, roundKeys);

        plaintext.clear();
        
        // Giải mã từng block
        for (size_t i = 0; i < ciphertext.size(); i += 16) {
            std::array<unsigned char, 16> block;
            std::copy_n(ciphertext.begin() + i, 16, block.begin());

            AddRoundKey(block, roundKeys[10]);
            InvShiftRows(block);
            InvSubBytes(block);

            for (int round = 9; round >= 1; --round) {
                AddRoundKey(block, roundKeys[round]);
                InvMixColumns(block);
                InvShiftRows(block);
                InvSubBytes(block);
            }
            AddRoundKey(block, roundKeys[0]);

            plaintext.insert(plaintext.end(), block.begin(), block.end());
        }

        // Xóa padding
        size_t padding = plaintext.back();
        plaintext.resize(plaintext.size() - padding);
    }
}