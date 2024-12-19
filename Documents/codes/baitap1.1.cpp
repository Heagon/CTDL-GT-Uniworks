#include <iostream>

// Hàm tính
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
// ip
int main() {
    int num;
    std::cout << "Nhập số: ";
    std::cin >> num;

// Kiểm tra
if (num < 0) {
        std::cout << "Số nhập vào phải là số nguyên dương.";
    } else {
        unsigned long long result = factorial(num);
        std::cout << "Giai thừa của số " << num << " là: " << result;
    }

    return 0;
}
