#include <stdio.h>
using namespace std;

void tronMang(int a[], int n, int b[], int m, int c[]) {
    int i;
    for (i = 0; i < n; i++) {
        c[i] = a[i];
    }
    for (int j = 0; j < m; j++) {
        c[i++] = b[j];
    }
}
int main() {
    int a[] = {15, 30, 201, 303};
    int b[] = {5, 7, 10, 27, 98, 121, 204, 308};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int c[n + m];
    tronMang(a, n, b, m, c);
    for (int i = 0; i < n + m; i++) {
        printf("%d ", c[i]);
    }
    return 0;
}
