#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char mota[100];
    double sotien;
} khoanthu;
typedef struct {
    char mota[100];
    double sotien;
} khoanchi;
typedef struct {
    khoanthu *cackhoanthu;
    int soluongthu;
    khoanchi *cackhoanchi;
    int soluongchi;
} QuanLyTaiChinh;
void khoiTaoQuanLyTaiChinh(QuanLyTaiChinh *ql) {
    ql->cackhoanthu = NULL;
    ql->soluongthu = 0;
    ql->cackhoanchi = NULL;
    ql->soluongchi = 0;
}
void themkhoanthu(QuanLyTaiChinh *ql, const char *mota, double sotien) {
    ql->cackhoanthu = (khoanthu *)realloc(ql->cackhoanthu, (ql->soluongthu + 1) * sizeof(khoanthu));
    strncpy(ql->cackhoanthu[ql->soluongthu].mota, mota, 100);
    ql->cackhoanthu[ql->soluongthu].sotien = sotien;
    ql->soluongthu++;
}
void lietKekhoanthu(const QuanLyTaiChinh *ql) {
    printf("=== Sao Ke Khoan Thu ===\n");
    printf("+---------------------------------------------------+------------+\n");
    printf("| %-50s | %-10s |\n", "Mo ta", "So tien");
    printf("+---------------------------------------------------+------------+\n");
    for (int i = 0; i < ql->soluongthu; i++) {
        printf("| %-50s | %-10.2f |\n", ql->cackhoanthu[i].mota, ql->cackhoanthu[i].sotien);
    }
    printf("+---------------------------------------------------+------------+\n");
}
void themkhoanchi(QuanLyTaiChinh *ql, const char *mota, double sotien) {
    ql->cackhoanchi = (khoanchi *)realloc(ql->cackhoanchi, (ql->soluongchi + 1) * sizeof(khoanchi));
    strncpy(ql->cackhoanchi[ql->soluongchi].mota, mota, 100);
    ql->cackhoanchi[ql->soluongchi].sotien = sotien;
    ql->soluongchi++;
}
void lietKekhoanchi(const QuanLyTaiChinh *ql) {
    printf("=== Sao Ke Khoan Chi ===\n");
    printf("+---------------------------------------------------+------------+\n");
    printf("| %-50s | %-10s |\n", "Mo ta", "So tien");
    printf("+---------------------------------------------------+------------+\n");
    for (int i = 0; i < ql->soluongchi; i++) {
        printf("| %-50s | %-10.2f |\n", ql->cackhoanchi[i].mota, ql->cackhoanchi[i].sotien);
    }
    printf("+---------------------------------------------------+------------+\n");
}
// code cua Long
typedef struct {
    char masanpham[10];
    char tensanpham[50];
    int soluongmua;
    int soluongban;
    char xuatxu[50];
    int dongia;
} sanpham;
sanpham danhsachsanpham[100];
int sothutusanpham = 0;
void themsanpham(char masanpham[], char tensanpham[], char xuatxu[], int muavao, int banra, int dongia) {
    for (int i = 0; i < sothutusanpham; i++) {
        if (strcmp(danhsachsanpham[i].masanpham, masanpham) == 0) {
            danhsachsanpham[i].soluongmua += muavao;
            danhsachsanpham[i].soluongban += banra;
            return;
        }
    }
    strcpy(danhsachsanpham[sothutusanpham].masanpham, masanpham);
    strcpy(danhsachsanpham[sothutusanpham].tensanpham, tensanpham);
    strcpy(danhsachsanpham[sothutusanpham].xuatxu, xuatxu);
    danhsachsanpham[sothutusanpham].soluongmua = muavao;
    danhsachsanpham[sothutusanpham].soluongban = banra;
    danhsachsanpham[sothutusanpham].dongia = dongia;
    sothutusanpham++;
}
void kiemtrasanpham() {
    printf("Danh sach thong ke san pham:\n");
    printf("%-20s %-20s %-20s %-20s %-20s %-20s\n", "Ma san pham", "Ten san pham", "Xuat xu", "So luong mua", "So luong ban", "Don gia");
    for (int i = 0; i < sothutusanpham; i++) {
        printf("%-20s %-20s %-20s %-20d %-20d %-20d\n", danhsachsanpham[i].masanpham, danhsachsanpham[i].tensanpham, danhsachsanpham[i].xuatxu, danhsachsanpham[i].soluongmua, danhsachsanpham[i].soluongban, danhsachsanpham[i].dongia);
    }
}
// .
// Chuyển đổi sản phẩm thành thu chi
void chuyenDoiSanPhamThanhThuChi(QuanLyTaiChinh *ql) {
    for (int i = 0; i < sothutusanpham; i++) {
        double doanhThu = danhsachsanpham[i].soluongban * danhsachsanpham[i].dongia;
        char motaThu[150];
        snprintf(motaThu, sizeof(motaThu), "Doanh thu ban san pham: %s", danhsachsanpham[i].tensanpham);
        themkhoanthu(ql, motaThu, doanhThu);
        double chiPhi = danhsachsanpham[i].soluongmua * danhsachsanpham[i].dongia;
        char motaChi[150];
        snprintf(motaChi, sizeof(motaChi), "Chi phi mua san pham: %s", danhsachsanpham[i].tensanpham);
        themkhoanchi(ql, motaChi, chiPhi);
    }
}
int main() {
    QuanLyTaiChinh ql;
    khoiTaoQuanLyTaiChinh(&ql);
    int luaChonChinh;
    int luaChonTaiChinh;
    char mota[100];
    double sotien;
    while (1) {
        printf("Chuong Trinh Quan Ly\n");
        printf("1. Chuyen doi san pham thanh thu chi\n");
        printf("2. Quan ly tai chinh\n");
        printf("3. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChonChinh);
        getchar();
        switch (luaChonChinh) {
            case 1:
                chuyenDoiSanPhamThanhThuChi(&ql);
                printf("Da chuyen doi san pham thanh cac khoan thu va chi.\n");
                break;
            case 2: {
                do {
                    printf("Quan Ly Tai Chinh\n");
                    printf("1. Nhap khoan thu\n");
                    printf("2. Sao ke khoan thu\n");
                    printf("3. Nhap khoan chi\n");
                    printf("4. Sao ke khoan chi\n");
                    printf("5. Quay lai\n");
                    printf("Chon chuc nang: ");
                    scanf("%d", &luaChonTaiChinh);
                    getchar();
                    switch (luaChonTaiChinh) {
                        case 1:
                            printf("Nhap mo ta khoan thu: ");
                            fgets(mota, sizeof(mota), stdin);
                            mota[strcspn(mota, "\n")] = 0;
                            printf("Nhap so tien: ");
                            scanf("%lf", &sotien);
                            themkhoanthu(&ql, mota, sotien);
                            break;
                        case 2:
                            lietKekhoanthu(&ql);
                            break;
                        case 3:
                            printf("Nhap mo ta khoan chi: ");
                            fgets(mota, sizeof(mota), stdin);
                            mota[strcspn(mota, "\n")] = 0;
                            printf("Nhap so tien: ");
                            scanf("%lf", &sotien);
                            themkhoanchi(&ql, mota, sotien);
                            break;
                        case 4:
                            lietKekhoanchi(&ql);
                            break;
                        case 5:
                            break;
                        default:
                            printf("Lua chon khong hop le, vui long thu lai.\n");
                    }
                } while (luaChonTaiChinh != 5);
                break;
            }
            case 3:
                free(ql.cackhoanthu);
                free(ql.cackhoanchi);
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le, vui long thu lai.\n");
        }
    }
    return 0;
}
