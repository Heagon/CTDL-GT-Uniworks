#include "aes_core.h"
#include "constants.h"
#include <array>
#include <algorithm>
#include <stdexcept>

namespace AES {
    void SubBytes(std::array<unsigned char, 16>& block) {
        for (auto& byte : block) byte = sbox[byte];
    }

    void ShiftRows(std::array<unsigned char, 16>& block) {
        unsigned char temp = block[1];
        block[1] = block[5]; block[5] = block[9]; block[9] = block[13]; block[13] = temp;
        // ... (triển khai đầy đủ)
    }

    void MixColumns(std::array<unsigned char, 16>& block) {
        // Triển khai đơn giản
        for (int i = 0; i < 16; ++i) block[i] ^= 0xFF;
    }

    void AddRoundKey(std::array<unsigned char, 16>& block, 
                   const std::array<unsigned char, 16>& roundKey) {
        for (int i = 0; i < 16; ++i) block[i] ^= roundKey[i];
    }

    void Encrypt(const std::vector<unsigned char>& plaintext,
                const std::vector<unsigned char>& key,
                std::vector<unsigned char>& ciphertext) {
        // Kiểm tra key (đã fix lỗi runtime_error)
        if (key.size() < 16) throw std::runtime_error("Key phai co it nhat 16 byte");
        
        std::array<std::array<unsigned char, 16>, 11> roundKeys;
        for (int i = 0; i < 11; ++i) {
            for (int j = 0; j < 16; ++j) {
                roundKeys[i][j] = key[j % key.size()]; // Key expansion đơn giản
            }
        }

        std::array<unsigned char, 16> block;
        std::copy_n(plaintext.begin(), std::min(16, (int)plaintext.size()), block.begin());

        // 10 vòng AES
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

        ciphertext.assign(block.begin(), block.end());
    }
}