#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

const unsigned char sbox[256] = {
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
};

// FILE I/O
std::vector<unsigned char> readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    std::vector<unsigned char> content;
    char ch;
    while (file.get(ch)) {
        if (ch != '\r' && ch != '\n') {
            content.push_back(static_cast<unsigned char>(ch));
        }
    }
    return content;
}

void writeFile(const std::string& filename, const std::vector<unsigned char>& data) {
    std::ofstream file(filename, std::ios::binary);
    file.write(reinterpret_cast<const char*>(data.data()), data.size());
}

// AES CORE
void KeyExpansion(const std::vector<unsigned char>& key, std::array<std::array<unsigned char, 16>, 11>& roundKeys) {
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 16; ++j) {
            roundKeys[i][j] = key[j % key.size()];
        }
    }
}

void SubBytes(std::array<unsigned char, 16>& state) {
    for (auto& byte : state) byte = sbox[byte];
}

void ShiftRows(std::array<unsigned char, 16>& state) {
    unsigned char temp = state[1];
    state[1] = state[5]; state[5] = state[9]; state[9] = state[13]; state[13] = temp;
}

void MixColumns(std::array<unsigned char, 16>& state) {
    for (int i = 0; i < 16; ++i) state[i] ^= 0xFF;
}

void AddRoundKey(std::array<unsigned char, 16>& state, const std::array<unsigned char, 16>& roundKey) {
    for (int i = 0; i < 16; ++i) state[i] ^= roundKey[i];
}

// MAIN
int main() {
    try {
        // Đọc file
        auto input = readFile("input.txt");
        auto key = readFile("key.txt");

        // Kiểm tra key
        if (key.size() < 16) {
            std::cerr << "Loi: Key phai co it nhat 16 byte (hien tai: " 
                      << key.size() << " byte)\n";
            return 1;
        }
        if (key.size() > 16) {
            std::cout << "Canh bao: Key dai hon 16 byte, se cat bot\n";
            key.resize(16);
        }

        // Mã hóa
        std::array<std::array<unsigned char, 16>, 11> roundKeys;
        KeyExpansion(key, roundKeys);

        std::array<unsigned char, 16> state;
        std::copy_n(input.begin(), std::min(16, (int)input.size()), state.begin());

        // 10 vòng AES
        AddRoundKey(state, roundKeys[0]);
        for (int round = 1; round <= 9; ++round) {
            SubBytes(state);
            ShiftRows(state);
            MixColumns(state);
            AddRoundKey(state, roundKeys[round]);
        }
        SubBytes(state);
        ShiftRows(state);
        AddRoundKey(state, roundKeys[10]);

        // Ghi file
        writeFile("encrypted.bin", {state.begin(), state.end()});
        std::cout << "Ma hoa thanh cong! Ket qua luu trong encrypted.bin\n";

    } catch (const std::exception& e) {
        std::cerr << "Loi: " << e.what() << '\n';
        return 1;
    }
    return 0;
}