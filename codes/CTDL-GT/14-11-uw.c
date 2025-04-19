#include <stdio.h>

// Định nghĩa một cấu trúc cho một node tập tin
typedef struct NodeTapTin {
    char ten[100];
    long kich_thuoc;
    char thoi_gian[20];
    struct NodeTapTin* tiep_theo;
} NodeTapTin;

// Hàm tạo một node tập tin mới
NodeTapTin* tao_node_tap_tin(const char* ten, long kich_thuoc, const char* thoi_gian) {
    static NodeTapTin node_pool[100];
    static int node_index = 0;
    
    if (node_index >= 100) {
        printf("Bộ nhớ cho node đã đầy!\n");
        return NULL;
    }
    
    NodeTapTin* node_moi = &node_pool[node_index++];
    
    // Sao chép thủ công chuỗi tên
    int i = 0;
    while (ten[i] != '\0' && i < 99) {
        node_moi->ten[i] = ten[i];
        i++;
    }
    node_moi->ten[i] = '\0';

    node_moi->kich_thuoc = kich_thuoc;

    // Sao chép thủ công chuỗi thời gian
    i = 0;
    while (thoi_gian[i] != '\0' && i < 19) {
        node_moi->thoi_gian[i] = thoi_gian[i];
        i++;
    }
    node_moi->thoi_gian[i] = '\0';

    node_moi->tiep_theo = NULL;
    return node_moi;
}

// Hàm so sánh chuỗi thời gian theo thứ tự từ điển
int so_sanh_thoi_gian(const char* tg1, const char* tg2) {
    int i = 0;
    while (tg1[i] != '\0' && tg2[i] != '\0') {
        if (tg1[i] != tg2[i]) {
            return tg1[i] - tg2[i];
        }
        i++;
    }
    return tg1[i] - tg2[i];
}

// Hàm chèn tập tin vào danh sách liên kết theo thứ tự thời gian
void chen_tap_tin(NodeTapTin** dau, const char* ten, long kich_thuoc, const char* thoi_gian) {
    NodeTapTin* node_moi = tao_node_tap_tin(ten, kich_thuoc, thoi_gian);
    if (node_moi == NULL) {
        return;
    }

    if (*dau == NULL || so_sanh_thoi_gian((*dau)->thoi_gian, thoi_gian) > 0) {
        node_moi->tiep_theo = *dau;
        *dau = node_moi;
    } else {
        NodeTapTin* hien_tai = *dau;
        while (hien_tai->tiep_theo != NULL && so_sanh_thoi_gian(hien_tai->tiep_theo->thoi_gian, thoi_gian) <= 0) {
            hien_tai = hien_tai->tiep_theo;
        }
        node_moi->tiep_theo = hien_tai->tiep_theo;
        hien_tai->tiep_theo = node_moi;
    }
}

// Hàm tính tổng kích thước của tất cả các tập tin trong danh sách liên kết
long tinh_tong_kich_thuoc(NodeTapTin* dau) {
    long tong_kich_thuoc = 0;
    NodeTapTin* hien_tai = dau;
    while (hien_tai != NULL) {
        tong_kich_thuoc += hien_tai->kich_thuoc;
        hien_tai = hien_tai->tiep_theo;
    }
    return tong_kich_thuoc;
}

// Hàm in ra các tập tin trong danh sách liên kết
void in_tap_tin(NodeTapTin* dau) {
    NodeTapTin* hien_tai = dau;
    while (hien_tai != NULL) {
        printf("Tap tin: %s, Kich thuoc: %ld bytes, Thoi gian: %s\n", hien_tai->ten, hien_tai->kich_thuoc, hien_tai->thoi_gian);
        hien_tai = hien_tai->tiep_theo;
    }
}

int main() {
    NodeTapTin* thu_muc = NULL;

    chen_tap_tin(&thu_muc, "file1.txt", 10485760, "2024-11-01 12:00:00");
    chen_tap_tin(&thu_muc, "file2.txt", 20971520, "2024-11-03 15:30:00");
    chen_tap_tin(&thu_muc, "file3.txt", 5242880, "2024-11-02 09:45:00");

    in_tap_tin(thu_muc);
    printf("Tong kich thuoc: %ld bytes\n", tinh_tong_kich_thuoc(thu_muc));

    return 0;
}
