#include <stdio.h>

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
    printf("Nhập số: ");5
    scanf("%d", &num);

    // Kiểm tra
    if (num < 0) {
        printf("Số nhập vào phải là số nguyên dương.");
    } else {
        unsigned long long result = factorial(num);
        printf("Giai thừa của số %d là: %llu", num, result);
    }

    return 0;
}
