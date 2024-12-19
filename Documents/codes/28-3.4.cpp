#include <iostream>

using namespace std;

void timMinMax(int arr[], int size, int& min, int& max) {
    if (size == 0) {
        cout << "Mang rong." << endl;
        return;
    }

    min = max = arr[0]; 

    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i]; 
        }
        if (arr[i] > max) {
            max = arr[i]; 
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 2, 7, 10, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    timMinMax(arr, size, min, max);

    cout << "Gia tri nho nhat trong mang la: " << min << endl;
    cout << "Gia tri lon nhat trong mang la: " << max << endl;

    return 0;
}
