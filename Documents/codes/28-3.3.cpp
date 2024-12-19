#include <iostream>

using namespace std;

void timPhanTuLonNhatVaViTri(int arr[], int size, int& max, int& viTri) {
    if (size == 0) {
        cout << "Mang rong." << endl;
        return;
    }

    max = arr[0]; 
    viTri = 0; 

    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i]; 
            viTri = i; 
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 2, 7, 10, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max, viTri;

    timPhanTuLonNhatVaViTri(arr, size, max, viTri);

    if (size > 0) {
        cout << "Phan tu lon nhat trong mang la: " << max << endl;
        cout << "Vi tri cua phan tu lon nhat trong mang la: " << viTri << endl;
    }

    return 0;
}
