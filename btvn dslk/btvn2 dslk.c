#include <stdio.h>

// Khai bao cau truc luu thong tin ve file
struct File {
    char ten[50];
    int dung_luong;
    int thoi_gian_luu;
};

// Ham doi cho 2 file
void doi_cho(struct File* a, struct File* b) {
    struct File tam = *a;
    *a = *b;
    *b = tam;
}

// Ham sap xep file theo dung luong tang dan (Bubble Sort)
void sap_xep_files(struct File* danh_sach, int so_luong) {
    for (int i = 0; i < so_luong - 1; i++) {
        for (int j = 0; j < so_luong - i - 1; j++) {
            if (danh_sach[j].dung_luong > danh_sach[j + 1].dung_luong) {
                doi_cho(&danh_sach[j], &danh_sach[j + 1]);
            }
        }
    }
}

// Ham xoa file co dung luong be nhat va thoi gian luu lau nhat
void xoa_files_nho_nhat(struct File* danh_sach, int* so_luong) {
    if (*so_luong == 0) {
        printf("Khong co file de xoa\n");
        return;
    }

    // Tim dung luong nho nhat
    int dung_luong_min = danh_sach[0].dung_luong;
    for (int i = 1; i < *so_luong; i++) {
        if (danh_sach[i].dung_luong < dung_luong_min) {
            dung_luong_min = danh_sach[i].dung_luong;
        }
    }

    // Xoa file co dung luong min va thoi gian luu lau nhat
    int chi_so_xoa = -1;
    int thoi_gian_luu_max = -1;
    for (int i = 0; i < *so_luong; i++) {
        if (danh_sach[i].dung_luong == dung_luong_min && danh_sach[i].thoi_gian_luu > thoi_gian_luu_max) {
            thoi_gian_luu_max = danh_sach[i].thoi_gian_luu;
            chi_so_xoa = i;
        }
    }

    if (chi_so_xoa != -1) {
        for (int i = chi_so_xoa; i < *so_luong - 1; i++) {
            danh_sach[i] = danh_sach[i + 1];
        }
        (*so_luong)--;
    }
}

// Ham in thong tin file
void in_danh_sach_files(struct File* danh_sach, int so_luong) {
    for (int i = 0; i < so_luong; i++) {
        printf("Ten: %s, Dung luong: %d, Thoi gian luu: %d\n", danh_sach[i].ten, danh_sach[i].dung_luong, danh_sach[i].thoi_gian_luu);
    }
}

int main() {
    int so_luong_files = 5;
    struct File danh_sach_files[5] = {
        {"file1.txt", 100, 10},
        {"file2.txt", 50, 20},
        {"file3.txt", 150, 5},
        {"file4.txt", 50, 30},
        {"file5.txt", 200, 15}
    };

    printf("Danh sach truoc khi sap xep:\n");
    in_danh_sach_files(danh_sach_files, so_luong_files);

    // Sap xep file theo dung luong tang dan
    sap_xep_files(danh_sach_files, so_luong_files);
    printf("\nDanh sach sau khi sap xep theo dung luong tang dan:\n");
    in_danh_sach_files(danh_sach_files, so_luong_files);

    // Xoa file co dung luong nho nhat va thoi gian luu lau nhat
    xoa_files_nho_nhat(danh_sach_files, &so_luong_files);
    printf("\nDanh sach sau khi xoa file co dung luong be nhat va thoi gian luu lau nhat:\n");
    in_danh_sach_files(danh_sach_files, so_luong_files);

    return 0;
}
