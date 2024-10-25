#include <stdio.h>

void sapXepMau(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

int main() {
    int arr[] = {2, 0, 2, 0, 0, 1, 0, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    sapXepMau(arr, n);
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            printf("do ");
        } else if (arr[i] == 1) {
            printf("trang ");
        } else {
            printf("xanh ");
        }
    }
    
    return 0;
}
