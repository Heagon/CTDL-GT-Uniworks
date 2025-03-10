#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Ham khoi tao S-box
void KSA(vector<unsigned char>& sBox, const vector<unsigned char>& khoa) {
    int doDaiKhoa = khoa.size();
    for (int i = 0; i < 256; ++i) {
        sBox[i] = i;
    }

    int j = 0;
    for (int i = 0; i < 256; ++i) {
        j = (j + sBox[i] + khoa[i % doDaiKhoa]) % 256;
        swap(sBox[i], sBox[j]);
    }
}

// Ham tao dong khoa PRGA
unsigned char PRGA(vector<unsigned char>& sBox, int& i, int& j) {
    i = (i + 1) % 256;
    j = (j + sBox[i]) % 256;
    swap(sBox[i], sBox[j]);
    return sBox[(sBox[i] + sBox[j]) % 256];
}

// Ham ma hoa RC4
vector<unsigned char> RC4(const vector<unsigned char>& banRo, const vector<unsigned char>& khoa, vector<unsigned char>& dongKhoa) {
    vector<unsigned char> sBox(256);
    KSA(sBox, khoa);

    int i = 0;
    int j = 0;
    vector<unsigned char> banMa(banRo.size());

    for (size_t k = 0; k < banRo.size(); ++k) {
        unsigned char byteKhoa = PRGA(sBox, i, j);
        dongKhoa.push_back(byteKhoa); // Luu tru dong khoa
        banMa[k] = banRo[k] ^ byteKhoa;
    }

    return banMa;
}

int main() {
    // Khoa mat (co the tuy chinh)
    string chuoiKhoa = "MySecretKey";  // Thay doi khoa tai day
    vector<unsigned char> khoa(chuoiKhoa.begin(), chuoiKhoa.end());

    // Ban ro
    string chuoiBanRo = "Hanoi University of Science and Technology";
    vector<unsigned char> banRo(chuoiBanRo.begin(), chuoiBanRo.end());

    // Vector de luu dong khoa
    vector<unsigned char> dongKhoa;

    // Ma hoa
    vector<unsigned char> banMa = RC4(banRo, khoa, dongKhoa);

    // In ban ro
    cout << "Ban ro: " << chuoiBanRo << endl;

    // In dong khoa
    cout << "Dong khoa: ";
    for (unsigned char byte : dongKhoa) {
        printf("%02X ", byte);
    }
    cout << endl;

    // In ban ma
    cout << "Ban ma: ";
    for (unsigned char byte : banMa) {
        printf("%02X ", byte);
    }
    cout << endl;

    return 0;
}