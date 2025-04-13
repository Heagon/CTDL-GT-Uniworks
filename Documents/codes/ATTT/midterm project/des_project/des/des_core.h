#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <bitset>

namespace DES {
    void GenerateSubKeys(const std::string& key, std::vector<std::string>& subkeys);
    
    std::string ProcessBlock(const std::string& block, const std::vector<std::string>& subkeys, bool isEncrypt);
    std::string Feistel(const std::string& R, const std::string& subkey);
    std::string Permute(const std::string& bits, const int* table, int n);
    
    void Encrypt(const std::vector<unsigned char>& plaintext, 
                const std::vector<unsigned char>& key,
                std::vector<unsigned char>& ciphertext);
                
    void Decrypt(const std::vector<unsigned char>& ciphertext,
                const std::vector<unsigned char>& key,
                std::vector<unsigned char>& plaintext);
}