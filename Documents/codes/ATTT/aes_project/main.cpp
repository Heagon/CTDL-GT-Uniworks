#include <iostream>
#include "lib/file_io.h"
#include "lib/aes_core.h"

int main() {
    try {
        // Đọc dữ liệu
        auto input = readFile("input.txt");
        auto key = readFile("key.txt");

        // Xử lý
        std::vector<unsigned char> encrypted;
        AES::Encrypt(input, key, encrypted);

        // Ghi kết quả
        writeFile("encrypted.bin", encrypted);
        
    } catch (const std::exception& e) {
        std::cerr << "Loi: " << e.what() << '\n';
        return 1;
    }
    return 0;
}