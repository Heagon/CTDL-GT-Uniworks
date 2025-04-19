#include "des_core.h"
#include "des_const.h"
#include "../utils/converters.h"
#include <algorithm>
#include <bitset>
#include <stdexcept>
#include <string>

using namespace std;

namespace DES {
    // TEMPLATE HÀM HOÁN VỊ (HỖ TRỢ MỌI KÍCH THƯỚC BẢNG)
    template <size_t N>
    string Permute(const string& bits, const array<int, N>& table) {
        string result;
        for (size_t i = 0; i < N; i++) {
            // Chuyển từ chỉ số 1-based (DES) sang 0-based (C++)
            int pos = table[i] - 1;
            
            // Kiểm tra phạm vi
            if (pos < 0 || static_cast<size_t>(pos) >= bits.size()) {
                throw out_of_range("Loi hoan vi: Chi so " + to_string(pos) + " vuot pham vi");
            }
            
            result += bits[pos];
        }
        return result;
    }
    // HÀM DỊCH TRÁI CHO KHÓA
    string ShiftLeft(const string& keyPart, int shifts) {
        if (shifts < 0 || static_cast<size_t>(shifts) > keyPart.size()) {
            throw invalid_argument("So luong dich khong hop le");
        }
        return keyPart.substr(shifts) + keyPart.substr(0, shifts);
    }
    // TẠO 16 SUBKEY TỪ KHÓA CHÍNH (ĐÃ SỬA DÙNG TEMPLATE)
    void GenerateSubKeys(const string& key, vector<string>& subkeys) {
        // Bước 1: Hoán vị PC1 (56 phần tử)
        string permKey = Permute(key, PC1);
        
        // Chia thành 2 nửa
        string C = permKey.substr(0, 28);
        string D = permKey.substr(28, 28);
        
        // Bước 2: Tạo 16 subkey
        subkeys.clear();
        for (int i = 0; i < 16; i++) {
            C = ShiftLeft(C, SHIFT_BITS[i]);
            D = ShiftLeft(D, SHIFT_BITS[i]);
            
            // Kết hợp và hoán vị PC2 (48 phần tử)
            string combined = C + D;
            subkeys.push_back(Permute(combined, PC2));
        }
    }
    // HÀM FEISTEL (VÒNG MÃ HÓA - ĐÃ SỬA DÙNG TEMPLATE)
    string Feistel(const string& R, const string& subkey) {
        // Bước 1: Mở rộng từ 32-bit lên 48-bit (E - 48 phần tử)
        string expanded = Permute(R, E);
        
        // Bước 2: XOR với subkey
        string xored;
        for (size_t i = 0; i < expanded.size(); i++) {
            xored += (expanded[i] == subkey[i]) ? '0' : '1';
        }
        
        // Bước 3: Thay thế bằng S-box
        string substituted;
        for (int i = 0; i < 8; i++) {
            // Lấy 6 bit cho S-box hiện tại
            string group = xored.substr(i * 6, 6);
            
            // Tính hàng và cột
            int row = bitset<2>(string{group[0], group[5]}).to_ulong();
            int col = bitset<4>(group.substr(1, 4)).to_ulong();
            
            // Lấy giá trị từ S-box và chuyển sang 4 bit
            substituted += bitset<4>(S[i][row][col]).to_string();
        }
        
        // Bước 4: Hoán vị P (32 phần tử)
        return Permute(substituted, P);
    }
    // XỬ LÝ 1 BLOCK 64-BIT (ĐÃ SỬA DÙNG TEMPLATE)
    string ProcessBlock(const string& block, const vector<string>& subkeys, bool isEncrypt) {
        // Bước 1: Hoán vị đầu vào (IP - 64 phần tử)
        string permBlock = Permute(block, IP);
        
        // Chia thành 2 nửa
        string L = permBlock.substr(0, 32);
        string R = permBlock.substr(32, 32);
        
        // Bước 2: 16 vòng Feistel
        for (int round = 0; round < 16; round++) {
            string F = Feistel(R, subkeys[isEncrypt ? round : 15 - round]);
            
            // XOR L với F
            string newR;
            for (size_t i = 0; i < L.size(); i++) {
                newR += (L[i] == F[i]) ? '0' : '1';
            }
            
            // Đổi chỗ L và R
            L = R;
            R = newR;
        }
        
        // Bước 3: Hoán vị cuối (FP - 64 phần tử)
        string combined = R + L;
        return Permute(combined, FP);
    }
    // HÀM MÃ HÓA CHÍNH
    void Encrypt(const vector<unsigned char>& plaintext, 
                const vector<unsigned char>& key,
                vector<unsigned char>& ciphertext) {
        // Chuyển đổi dữ liệu sang bit
        string plainBits = Converters::BytesToBits(plaintext);
        string keyBits = Converters::BytesToBits(key);
        
        // Tạo subkey
        vector<string> subkeys;
        GenerateSubKeys(keyBits, subkeys);
        
        // Xử lý từng block 64-bit
        ciphertext.clear();
        for (size_t i = 0; i < plainBits.size(); i += 64) {
            string block = plainBits.substr(i, 64);
            
            // Thêm padding nếu cần
            if (block.size() < 64) {
                block += string(64 - block.size(), '0');
            }
            
            // Mã hóa và thêm vào kết quả
            string encryptedBlock = ProcessBlock(block, subkeys, true);
            vector<unsigned char> bytes = Converters::BitsToBytes(encryptedBlock);
            ciphertext.insert(ciphertext.end(), bytes.begin(), bytes.end());
        }
    }
    // HÀM GIẢI MÃ CHÍNH
    void Decrypt(const vector<unsigned char>& ciphertext,
                const vector<unsigned char>& key,
                vector<unsigned char>& plaintext) {
        // Chuyển đổi dữ liệu sang bit
        string cipherBits = Converters::BytesToBits(ciphertext);
        string keyBits = Converters::BytesToBits(key);
        
        // Tạo subkey
        vector<string> subkeys;
        GenerateSubKeys(keyBits, subkeys);
        
        // Xử lý từng block 64-bit
        plaintext.clear();
        for (size_t i = 0; i < cipherBits.size(); i += 64) {
            string block = cipherBits.substr(i, 64);
            
            // Giải mã và thêm vào kết quả
            string decryptedBlock = ProcessBlock(block, subkeys, false);
            vector<unsigned char> bytes = Converters::BitsToBytes(decryptedBlock);
            plaintext.insert(plaintext.end(), bytes.begin(), bytes.end());
        }
    }

}
// HIỆN THỰC HÓA TEMPLATE CHO CÁC KÍCH THƯỚC BẢNG
template string DES::Permute<64>(const string&, const array<int, 64>&);
template string DES::Permute<56>(const string&, const array<int, 56>&);
template string DES::Permute<48>(const string&, const array<int, 48>&);
template string DES::Permute<32>(const string&, const array<int, 32>&);