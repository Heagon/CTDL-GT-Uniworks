#include <stdio.h>

// Khai báo cấu trúc ngày sinh
struct Ngay {
    int ngay, thang, nam;
};

// Khai báo cấu trúc sinh viên
struct SinhVien {
    int stt;              // Số thứ tự của sinh viên
    char maSV[8];         // Mã sinh viên
    char hoTen[50];       // Họ và tên
    int gioiTinh;         // Giới tính (0: nữ, 1: nam)
    struct Ngay ngaySinh; // Ngày sinh
    char diaChi[100];     // Địa chỉ
    char lop[12];         // Lớp
    char khoa[7];         // Khoa
};

// Khai báo cấu trúc Node trong DSLK
struct Node {
    struct SinhVien data; // Dữ liệu sinh viên
    struct Node *link;    // Liên kết đến nút tiếp theo
};

// Khai báo cấu trúc danh sách
struct List {
    struct Node *first; // Con trỏ đến nút đầu tiên
    struct Node *last;  // Con trỏ đến nút cuối cùng
};

// Hàm khởi tạo danh sách rỗng
void khoiTaoDanhSach(struct List *list) {
    list->first = NULL;
    list->last = NULL;
}

// Hàm so sánh chuỗi ký tự (thay thế strcmp)
int soSanhChuoi(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') return 0;
    if (s1[i] == '\0') return -1;
    return 1;
}

// Hàm nhập thông tin sinh viên
struct SinhVien nhapSinhVien(int stt) {
    struct SinhVien sv;
    sv.stt = stt; // Gán số thứ tự cho sinh viên
    
    printf("Nhap ma sinh vien: ");
    scanf("%s", sv.maSV);
    getchar(); // Đọc ký tự '\n' còn lại sau scanf
    
    printf("Nhap ho ten: ");
    fgets(sv.hoTen, sizeof(sv.hoTen), stdin);
    
    printf("Nhap gioi tinh (0: nu, 1: nam): ");
    scanf("%d", &sv.gioiTinh);
    
    printf("Nhap ngay sinh (dd mm yyyy): ");
    scanf("%d %d %d", &sv.ngaySinh.ngay, &sv.ngaySinh.thang, &sv.ngaySinh.nam);
    getchar();
    
    printf("Nhap dia chi: ");
    fgets(sv.diaChi, sizeof(sv.diaChi), stdin);
    
    printf("Nhap lop: ");
    fgets(sv.lop, sizeof(sv.lop), stdin);
    
    printf("Nhap khoa: ");
    fgets(sv.khoa, sizeof(sv.khoa), stdin);
    
    return sv;
}

// Hàm thêm sinh viên vào danh sách đã sắp xếp theo mã sinh viên
void themSinhVien(struct List *list, struct SinhVien sv) {
    struct Node *newNode;
    static struct Node nodes[100];
    static int index = 0;
    
    newNode = &nodes[index++];
    newNode->data = sv;
    newNode->link = NULL;
    
    if (list->first == NULL) {
        list->first = newNode;
        list->last = newNode;
    } else {
        struct Node *prev = NULL;
        struct Node *curr = list->first;
        
        while (curr != NULL && soSanhChuoi(curr->data.maSV, sv.maSV) < 0) {
            prev = curr;
            curr = curr->link;
        }
        
        if (prev == NULL) {
            newNode->link = list->first;
            list->first = newNode;
        } else if (curr == NULL) {
            prev->link = newNode;
            list->last = newNode;
        } else {
            prev->link = newNode;
            newNode->link = curr;
        }
    }
}

// Hàm in danh sách sinh viên kèm số thứ tự
void inDanhSach(struct List list) {
    struct Node *curr = list.first;
    
    while (curr != NULL) {
        printf("%d %s %s %d/%d/%d %s %s %s\n",
            curr->data.stt,
            curr->data.maSV,
            curr->data.hoTen,
            curr->data.ngaySinh.ngay, curr->data.ngaySinh.thang, curr->data.ngaySinh.nam,
            curr->data.diaChi,
            curr->data.lop,
            curr->data.khoa);
        
        curr = curr->link;
    }
}

// Hàm in sinh viên có cùng ngày sinh
void inSinhVienCungNgaySinh(struct List list, struct Ngay ngay) {
    struct Node *curr = list.first;
    int timThay = 0;
    
    while (curr != NULL) {
        if (curr->data.ngaySinh.ngay == ngay.ngay &&
            curr->data.ngaySinh.thang == ngay.thang &&
            curr->data.ngaySinh.nam == ngay.nam) {
            printf("%d %s %s %d/%d/%d %s %s %s\n",
                curr->data.stt,
                curr->data.maSV,
                curr->data.hoTen,
                curr->data.ngaySinh.ngay, curr->data.ngaySinh.thang, curr->data.ngaySinh.nam,
                curr->data.diaChi,
                curr->data.lop,
                curr->data.khoa);
            timThay = 1;
        }
        curr = curr->link;
    }
    
    if (!timThay) {
        printf("Khong tim thay sinh vien cung ngay sinh\n");
    }
}

// Hàm xóa sinh viên có cùng ngày sinh và in ra những sinh viên bị xóa
void xoaSinhVienCungNgaySinh(struct List *list, struct Ngay ngay) {
    struct Node *curr = list->first;
    struct Node *prev = NULL;
    int timThay = 0;

    printf("Nhung sinh vien sau da bi xoa:\n");
    
    while (curr != NULL) {
        if (curr->data.ngaySinh.ngay == ngay.ngay &&
            curr->data.ngaySinh.thang == ngay.thang &&
            curr->data.ngaySinh.nam == ngay.nam) {
            
            printf("%d %s %s %d/%d/%d %s %s %s\n",
                curr->data.stt,
                curr->data.maSV,
                curr->data.hoTen,
                curr->data.ngaySinh.ngay, curr->data.ngaySinh.thang, curr->data.ngaySinh.nam,
                curr->data.diaChi,
                curr->data.lop,
                curr->data.khoa);
                
            if (prev == NULL) {
                list->first = curr->link;
            } else {
                prev->link = curr->link;
            }
            timThay = 1;
        } else {
            prev = curr;
        }
        curr = curr->link;
    }
    
    if (!timThay) {
        printf("Khong co sinh vien nao bi xoa\n");
    }
}

// Hàm menu
void menu() {
    printf("\n1. Them sinh vien\n");
    printf("2. In danh sach sinh vien\n");
    printf("3. In sinh vien cung ngay sinh\n");
    printf("4. Xoa sinh vien cung ngay sinh\n");
    printf("0. Thoat\n");
}

int main() {
    struct List listSV;
    khoiTaoDanhSach(&listSV);
    int luaChon;
    struct Ngay ngay;
    int stt = 1; // Số thứ tự ban đầu của sinh viên
    
    do {
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        
        switch (luaChon) {
            case 1: {
                int soLuong;
                printf("Nhap so luong sinh vien muon them: ");
                scanf("%d", &soLuong);
                
                for (int i = 0; i < soLuong; i++) {
                    struct SinhVien sv = nhapSinhVien(stt++);
                    themSinhVien(&listSV, sv);
                }
                break;
            }
            case 2:
                inDanhSach(listSV);
                break;
            case 3:
                printf("Nhap ngay sinh (dd mm yyyy): ");
                scanf("%d %d %d", &ngay.ngay, &ngay.thang, &ngay.nam);
                inSinhVienCungNgaySinh(listSV, ngay);
                break;
            case 4:
                printf("Nhap ngay sinh (dd mm yyyy): ");
                scanf("%d %d %d", &ngay.ngay, &ngay.thang, &ngay.nam);
                xoaSinhVienCungNgaySinh(&listSV, ngay);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (luaChon != 0);

    return 0;
}
