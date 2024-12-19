#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct hang_hoa {
    char ten_hang[50];
    int so_luong;
    float don_gia;
    struct hang_hoa* tiep;
} HangHoa;

typedef struct node {
    char ten_khach_hang[50];
    HangHoa* danh_sach_hang;
    struct node* tiep;
} Node;

typedef struct queue {
    Node* dau;
    Node* cuoi;
} Queue;

void khoi_tao_hang_cho(Queue* q) {
    q->dau = NULL;
    q->cuoi = NULL;
}

HangHoa* tao_hang_hoa(char* ten_hang, int so_luong, float don_gia) {
    HangHoa* moi = (HangHoa*)malloc(sizeof(HangHoa));
    strcpy(moi->ten_hang, ten_hang);
    moi->so_luong = so_luong;
    moi->don_gia = don_gia;
    moi->tiep = NULL;
    return moi;
}

Node* tao_node(char* ten_khach_hang, HangHoa* danh_sach_hang) {
    Node* moi = (Node*)malloc(sizeof(Node));
    strcpy(moi->ten_khach_hang, ten_khach_hang);
    moi->danh_sach_hang = danh_sach_hang;
    moi->tiep = NULL;
    return moi;
}

void them_gio_hang(Queue* q) {
    char ten_khach_hang[50];
    printf("Nhap ten khach hang: ");
    getchar();
    fgets(ten_khach_hang, sizeof(ten_khach_hang), stdin);
    ten_khach_hang[strcspn(ten_khach_hang, "\n")] = '\0';

    HangHoa* danh_sach_hang = NULL;
    HangHoa* cuoi_hang = NULL;
    char ten_hang[50];
    int so_luong;
    float don_gia;

    while (1) {
        printf("Nhap ten hang hoa (nhap 'thoat' de ket thuc): ");
        fgets(ten_hang, sizeof(ten_hang), stdin);
        ten_hang[strcspn(ten_hang, "\n")] = '\0';
        if (strcmp(ten_hang, "thoat") == 0) {
            break;
        }
        printf("Nhap so luong: ");
        scanf("%d", &so_luong);
        printf("Nhap don gia: ");
        scanf("%f", &don_gia);
        getchar();

        HangHoa* hang_moi = tao_hang_hoa(ten_hang, so_luong, don_gia);
        if (danh_sach_hang == NULL) {
            danh_sach_hang = hang_moi;
            cuoi_hang = hang_moi;
        } else {
            cuoi_hang->tiep = hang_moi;
            cuoi_hang = hang_moi;
        }
    }

    Node* moi = tao_node(ten_khach_hang, danh_sach_hang);
    if (q->dau == NULL) {
        q->dau = moi;
        q->cuoi = moi;
    } else {
        q->cuoi->tiep = moi;
        q->cuoi = moi;
    }
    printf("Da them gio hang cua %s vao hang cho.\n", ten_khach_hang);
}

void thanh_toan(Queue* q) {
    if (q->dau == NULL) {
        printf("Hang doi dang trong, khong co ai de thanh toan.\n");
        return;
    }
    Node* xoa = q->dau;
    q->dau = q->dau->tiep;
    if (q->dau == NULL) {
        q->cuoi = NULL;
    }
    HangHoa* hang_hien_tai = xoa->danh_sach_hang;
    float tong_tien = 0;
    printf("Khach hang %s da thanh toan voi cac mat hang:\n", xoa->ten_khach_hang);
    while (hang_hien_tai != NULL) {
        float thanh_tien = hang_hien_tai->so_luong * hang_hien_tai->don_gia;
        printf("- %s: %d x %.2f = %.2f\n", hang_hien_tai->ten_hang, hang_hien_tai->so_luong, hang_hien_tai->don_gia, thanh_tien);
        tong_tien += thanh_tien;
        HangHoa* xoa_hang = hang_hien_tai;
        hang_hien_tai = hang_hien_tai->tiep;
        free(xoa_hang);
    }
    printf("Tong tien: %.2f\n", tong_tien);
    free(xoa);
}

void hien_thi_hang_cho(Queue* q) {
    if (q->dau == NULL) {
        printf("Hang doi trong.\n");
        return;
    }
    Node* hien_tai = q->dau;
    printf("Danh sach khach hang trong hang doi:\n");
    while (hien_tai != NULL) {
        printf("Khach hang: %s\n", hien_tai->ten_khach_hang);
        HangHoa* hang_hien_tai = hien_tai->danh_sach_hang;
        float tong_tien = 0;
        while (hang_hien_tai != NULL) {
            float thanh_tien = hang_hien_tai->so_luong * hang_hien_tai->don_gia;
            printf("  - %s: %d x %.2f = %.2f\n", hang_hien_tai->ten_hang, hang_hien_tai->so_luong, hang_hien_tai->don_gia, thanh_tien);
            tong_tien += thanh_tien;
            hang_hien_tai = hang_hien_tai->tiep;
        }
        printf("  Tong tien: %.2f\n", tong_tien);
        hien_tai = hien_tai->tiep;
    }
}

int main() {
    Queue hang_cho;
    khoi_tao_hang_cho(&hang_cho);

    int lua_chon;
    do {
        printf("\n--- Quan ly hang doi thanh toan ---\n");
        printf("1. Them gio hang\n");
        printf("2. Thanh toan\n");
        printf("3. Hien thi danh sach dang doi\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &lua_chon);

        if (lua_chon == 1) {
            them_gio_hang(&hang_cho);
        } else if (lua_chon == 2) {
            thanh_toan(&hang_cho);
        } else if (lua_chon == 3) {
            hien_thi_hang_cho(&hang_cho);
        }
    } while (lua_chon != 4);

    printf("Chuong trinh ket thuc.\n");
    return 0;
}
