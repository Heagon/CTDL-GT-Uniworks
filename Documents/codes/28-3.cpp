
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int findFrequency(const string& str, char ch) {
    int frequency = 0;
    for (char c : str) {
        if (c == ch) {
            frequency++;
        }
    }
    return frequency;
}

string toUpperCase(const string& str) {
    string result = str;
    for (char& c : result) {
        if (islower(c)) {
            c = toupper(c);
        }
    }
    return result;
}

int calculateSumOfSquares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int sumOfOddIntegers(int N) {
    int sum = 0;
    for (int i = 1; i < N; i += 2) {
        sum += i;
    }
    return sum;
}

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string inputString;
    char character;
    int n;

    cout << "Nhap mot xau ky tu: ";
    getline(cin, inputString);
    cout << "Nhap ky tu muon tim tan suat xuat hien: ";
    cin >> character;
    cout << "Tan suat xuat hien cua ky tu '" << character << "' trong xau la: " << findFrequency(inputString, character) << endl;

    cout << "Xau ky tu sau khi chuyen thanh chu hoa: " << toUpperCase(inputString) << endl;

    cout << "Nhap so nguyen n: ";
    cin >> n;
    cout << "Gia tri cua bieu thuc S(" << n << ") la: " << calculateSumOfSquares(n) << endl;

    cout << "Nhap so nguyen N: ";
    cin >> n;
    cout << "Tong cac so le nho hon " << n << " la: " << sumOfOddIntegers(n) << endl;

    cout << "Nhap mot so nguyen: ";
    cin >> n;
    if (isPrime(n)) {
        cout << n << " la so nguyen to." << endl;
    } else {
        cout << n << " khong phai la so nguyen to." << endl;
    }

    return 0;
}
