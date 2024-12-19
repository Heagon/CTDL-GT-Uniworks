#include <iostream>

using namespace std;

int** capPhatMaTran(int rows, int cols) {
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    return arr;
}

void thuHoiMaTran(int** arr, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

void nhapDuLieu(int** arr, int rows, int cols) {
    cout << "Nhap du lieu cho ma tran:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Nhap phan tu thu [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

void hienThiMaTran(int** arr, int rows, int cols) {
    cout << "Ma tran:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int tinhTong(int** arr, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int tinhTongHangChanLe(int** arr, int rows, int cols, bool even) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        if ((i % 2 == 0 && even) || (i % 2 != 0 && !even)) {
            for (int j = 0; j < cols; ++j) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

int timMax(int** arr, int rows, int cols) {
    int maxVal = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}

int timMin(int** arr, int rows, int cols) {
    int minVal = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] < minVal) {
                minVal = arr[i][j];
            }
        }
    }
    return minVal;
}

int timMaxCot(int** arr, int rows, int colIndex) {
    int maxVal = arr[0][colIndex];
    for (int i = 1; i < rows; ++i) {
        if (arr[i][colIndex] > maxVal) {
            maxVal = arr[i][colIndex];
        }
    }
    return maxVal;
}

int main() {
    int staticArr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "Ma tran dau vao tinh:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << staticArr[i][j] << " ";
        }
        cout << endl;
    }

    int rows, cols;
    cout << "\nNhap so hang cua ma tran dong: ";
    cin >> rows;
    cout << "Nhap so cot cua ma tran dong: ";
    cin >> cols;

    int** dynamicArr = capPhatMaTran(rows, cols);
    nhapDuLieu(dynamicArr, rows, cols);

    cout << "\nMa tran dau vao dong:\n";
    hienThiMaTran(dynamicArr, rows, cols);

    int sum = tinhTong(dynamicArr, rows, cols);
    cout << "\nTong cac phan tu cua mang dong: " << sum << endl;

    int sumEven = tinhTongHangChanLe(dynamicArr, rows, cols, true);
    int sumOdd = tinhTongHangChanLe(dynamicArr, rows, cols, false);
    cout << "Tong cac phan tu tren hang chan cua mang dong: " << sumEven << endl;
    cout << "Tong cac phan tu tren hang le cua mang dong: " << sumOdd << endl;

    int maxVal = timMax(dynamicArr, rows, cols);
    int minVal = timMin(dynamicArr, rows, cols);
    cout << "Gia tri lon nhat cua mang dong: " << maxVal << endl;
    cout << "Gia tri nho nhat cua mang dong: " << minVal << endl;

    int colIndex;
    cout << "Nhap chi so cot muon tim gia tri lon nhat: ";
    cin >> colIndex;
    if (colIndex >= 0 && colIndex < cols) {
        int maxColVal = timMaxCot(dynamicArr, rows, colIndex);
        cout << "Gia tri lon nhat tren cot thu " << colIndex << " cua mang dong: " << maxColVal << endl;
    } else {
        cout << "Chi so cot khong hop le!" << endl;
    }

    thuHoiMaTran(dynamicArr, rows);

    return 0;
}

     