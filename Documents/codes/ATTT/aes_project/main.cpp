#include <iostream>
#include "lib/file_io.h"
#include "lib/aes_core.h"

int main() {
    try {
        // Đọc dữ liệu
        auto input = readFile("input.txt");
        auto key = readFile("key.txt");

        // Mã hóa
        std::vector<unsigned char> encrypted;
        AES::Encrypt(input, key, encrypted);
        writeFile("encrypted.bin", encrypted);

        // Giải mã
        std::vector<unsigned char> decrypted;
        AES::Decrypt(encrypted, key, decrypted);
        writeFile("decrypted.bin", decrypted);

        std::cout << "Da tao 2 file:\n"
                  << "- encrypted.bin (da ma hoa)\n"
                  << "- decrypted.bin (da giai ma)\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Loi: " << e.what() << '\n';
        return 1;
    }
    return 0;
}