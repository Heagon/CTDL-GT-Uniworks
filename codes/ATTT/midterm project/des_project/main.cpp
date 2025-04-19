#include <iostream>
#include "des/des_core.h"
#include "utils/file_io.h"
#include "utils/padding.h"

int main() {
    try {
        // Đọc dữ liệu
        auto input = readFile("input.txt");
        auto key = readFile("key.txt");
        
        addPadding(input, 8);
        
        // Mã hóa
        std::vector<unsigned char> encrypted;
        DES::Encrypt(input, key, encrypted);
        writeFile("encrypted.bin", encrypted);
        
        // Giải mã
        std::vector<unsigned char> decrypted;
        DES::Decrypt(encrypted, key, decrypted);
        removePadding(decrypted);
        writeFile("decrypted.txt", decrypted);
        
    } catch (const std::exception& e) {
        std::cerr << "Loi: " << e.what() << '\n';
        return 1;
    }
    return 0;
}