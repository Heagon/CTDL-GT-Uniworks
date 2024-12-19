#include <stdio.h>
#include <stdlib.h>

typedef struct NodeFile {
    char tenFile[100];
    int kichThuoc;
    char ngayTao[11];
    struct NodeFile* next;
} NodeFile;

NodeFile* taoNodeFile(const char* tenFile, int kichThuoc, const char* ngayTao) {
    NodeFile* nodeMoi = (NodeFile*)malloc(sizeof(NodeFile));
    if (nodeMoi == NULL) {
        printf("Khong du bo nho\n");
        exit(1);
    }
    snprintf(nodeMoi->tenFile, 100, "%s", tenFile);
    nodeMoi->kichThuoc = kichThuoc;
    snprintf(nodeMoi->ngayTao, 11, "%s", ngayTao);
    nodeMoi->next = NULL;
    return nodeMoi;
}

void chenNodeCuoi(NodeFile** dau, const char* tenFile, int kichThuoc, const char* ngayTao) {
    NodeFile* nodeMoi = taoNodeFile(tenFile, kichThuoc, ngayTao);
    if (*dau == NULL) {
        *dau = nodeMoi;
    } else {
        NodeFile* hienTai = *dau;
        while (hienTai->next != NULL) {
            hienTai = hienTai->next;
        }
        hienTai->next = nodeMoi;
    }
}

void hoanViNode(NodeFile* a, NodeFile* b) {
    char tenFileTemp[100];
    int kichThuocTemp;
    char ngayTaoTemp[11];

    snprintf(tenFileTemp, 100, "%s", a->tenFile);
    snprintf(a->tenFile, 100, "%s", b->tenFile);
    snprintf(b->tenFile, 100, "%s", tenFileTemp);

    kichThuocTemp = a->kichThuoc;
    a->kichThuoc = b->kichThuoc;
    b->kichThuoc = kichThuocTemp;

    snprintf(ngayTaoTemp, 11, "%s", a->ngayTao);
    snprintf(a->ngayTao, 11, "%s", b->ngayTao);
    snprintf(b->ngayTao, 11, "%s", ngayTaoTemp);
}

void sapXepDanhSach(NodeFile* dau) {
    if (dau == NULL) return;
    NodeFile* i;
    NodeFile* j;
    for (i = dau; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->kichThuoc > j->kichThuoc) {
                hoanViNode(i, j);
            }
        }
    }
}

void inDanhSach(NodeFile* dau) {
    NodeFile* hienTai = dau;
    while (hienTai != NULL) {
        printf("Ten file: %s, Kich thuoc: %d bytes, Ngay tao: %s\n", hienTai->tenFile, hienTai->kichThuoc, hienTai->ngayTao);
        hienTai = hienTai->next;
    }
}

int main() {
    NodeFile* danhSachFile = NULL;

    chenNodeCuoi(&danhSachFile, "file1.txt", 500, "10/11/2024");
    chenNodeCuoi(&danhSachFile, "file2.txt", 200, "08/11/2024");
    chenNodeCuoi(&danhSachFile, "file3.txt", 750, "12/11/2024");
    chenNodeCuoi(&danhSachFile, "file4.txt", 300, "09/11/2024");
    chenNodeCuoi(&danhSachFile, "file5.txt", 600, "07/11/2024");

    printf("Danh sach truoc khi sap xep:\n");
    inDanhSach(danhSachFile);

    sapXepDanhSach(danhSachFile);

    printf("\nDanh sach sau khi sap xep tang dan theo kich thuoc:\n");
    inDanhSach(danhSachFile);

    return 0;
}
