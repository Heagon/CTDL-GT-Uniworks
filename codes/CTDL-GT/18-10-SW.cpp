#include <stdio.h>
using namespace std;
void tronMang(int a[], int n, int b[], int m, int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {if (k % 2 == 0) {c[k++] = a[i++];} else {c[k++] = b[j++];}}
    while (i < n) {c[k++] = a[i++];}
    while (j < m) {c[k++] = b[j++];} }
void sapXepMang(int c[], int size) {for (int i = 0; i < size - 1; i++) {for (int j = i + 1; j < size; j++) {
            if (c[i] > c[j]) {int temp = c[i]; c[i] = c[j]; c[j] = temp;}}} }
int main() {
    int a[] = {15, 30, 201, 303};
    int b[] = {5, 7, 10, 27, 98, 121, 204, 308};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int c[n + m];
    tronMang(a, n, b, m, c);
    sapXepMang(c, n + m);
    for (int i = 0; i < n + m; i++) {printf("%d ", c[i]);}
    return 0;}