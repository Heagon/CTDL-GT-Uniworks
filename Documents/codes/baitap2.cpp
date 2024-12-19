#include <iostream>

int main() {
    int a, b, c;

    std::cout << "Nhập a: ";
    std::cin >> a;

    std::cout << "Nhập b: ";
    std::cin >> b;

    // gán
    c = a + b;
    std::cout << "a + b = " << c << std::endl;

    // so sánh
    if (a < b) {
        std::cout << "a nhỏ hơn b" << std::endl;
    } else {
        std::cout << "a lớn hơn hoặc bằng b" << std::endl;
    }

    // logic
    bool condition1 = (a < b);
    bool condition2 = (b == 10);

    if (condition1 && condition2) {
        std::cout << "a nhỏ hơn b và b bằng 10" << std::endl;
    } else if (condition1 || condition2) {
        std::cout << "a nhỏ hơn b hoặc b bằng 10" << std::endl;
    } else {
        std::cout << "Không thỏa mãn điều kiện" << std::endl;
    }

    return 0;
}
