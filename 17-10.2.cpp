#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

bool kiemTraNguyenTo(int so) {
    if (so < 2) return false;
    for (int i = 2; i * i <= so; i++) {
        if (so % i == 0) return false;
    }
    return true;
}

void taoDaySoBlum(int N, int blum[], int *soLuongBlum) {
    int nguyenTo[MAX], soLuongNguyenTo = 0;

    for (int i = 2; i < N; i++) {
        if (kiemTraNguyenTo(i)) {
            nguyenTo[soLuongNguyenTo++] = i;
        }
    }

    *soLuongBlum = 0;
    for (int i = 0; i < soLuongNguyenTo; i++) {
        for (int j = i + 1; j < soLuongNguyenTo; j++) {
            int soBlum = nguyenTo[i] * nguyenTo[j];
            if (soBlum < N) {
                blum[(*soLuongBlum)++] = soBlum;
            }
        }
    }
}

bool kiemTraBlum(int so, int blum[], int soLuongBlum) {
    for (int i = 0; i < soLuongBlum; i++) {
        if (blum[i] == so) return true;
    }
    return false;
}

void timCapSoBlum(int blum[], int soLuongBlum, int N) {
    printf("Cac cap so Blum co tong la so Blum:\n");
    for (int i = 0; i < soLuongBlum; i++) {
        for (int j = i + 1; j < soLuongBlum; j++) {
            int tong = blum[i] + blum[j];
            if (tong < N && kiemTraBlum(tong, blum, soLuongBlum)) {
                printf("(%d, %d)\n", blum[i], blum[j]);
            }
        }
    }
}

int main() {
    int N, M;
    int blum[MAX], soLuongBlum;

    printf("Nhap N: ");
    scanf("%d", &N);

    taoDaySoBlum(N, blum, &soLuongBlum);

    printf("Nhap so Blum M can kiem tra: ");
    scanf("%d", &M);

    if (kiemTraBlum(M, blum, soLuongBlum)) {
        printf("So %d la so Blum\n", M);
    } else {
        printf("So %d khong la so Blum\n", M);
    }

    timCapSoBlum(blum, soLuongBlum, N);

    return 0;
}
