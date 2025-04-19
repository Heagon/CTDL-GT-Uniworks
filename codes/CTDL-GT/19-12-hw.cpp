#include <iostream>
using namespace std;

bool soSanhChuoi(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

struct Node {
    char tieuDe[100];
    int soTrang;
    Node* mucCon[10];
    int soLuongMucCon;

    Node(const char* t, int p) : soTrang(p), soLuongMucCon(0) {
        int i = 0;
        while (t[i] != '\0' && i < 100) {
            tieuDe[i] = t[i];
            i++;
        }
        tieuDe[i] = '\0';
        for (int j = 0; j < 10; ++j) {
            mucCon[j] = nullptr;
        }
    }
};

int demSoChuong(Node* goc) {
    if (!goc) return 0;
    int dem = 0;
    for (int i = 0; i < goc->soLuongMucCon; ++i) {
        if (soSanhChuoi(goc->mucCon[i]->tieuDe, "Chuong 1") || soSanhChuoi(goc->mucCon[i]->tieuDe, "Chuong 2")) {
            dem++;
        }
    }
    return dem;
}

void inChuongVaSoTrang(Node* goc) {
    if (!goc) return;
    cout << "- " << goc->tieuDe << " : " << goc->soTrang << " trang" << endl;
    for (int i = 0; i < goc->soLuongMucCon; ++i) {
        inChuongVaSoTrang(goc->mucCon[i]);
    }
}

Node* timChuongDaiNhat(Node* goc) {
    Node* chuongDaiNhat = nullptr;
    if (!goc) return nullptr;

    for (int i = 0; i < goc->soLuongMucCon; ++i) {
        Node* current = goc->mucCon[i];
        if (current->soLuongMucCon > 0) {
            if (!chuongDaiNhat || current->soTrang > chuongDaiNhat->soTrang) {
                chuongDaiNhat = current;
            }
        }
    }

    return chuongDaiNhat;
}

bool xoaMuc(Node* goc, const char* tieuDeCanXoa, int& capNhatSoTrang) {
    if (!goc) return false;

    for (int i = 0; i < goc->soLuongMucCon; ++i) {
        if (soSanhChuoi(goc->mucCon[i]->tieuDe, tieuDeCanXoa)) {
            capNhatSoTrang -= goc->mucCon[i]->soTrang;
            goc->soTrang -= goc->mucCon[i]->soTrang;
            delete goc->mucCon[i];
            for (int j = i; j < goc->soLuongMucCon - 1; ++j) {
                goc->mucCon[j] = goc->mucCon[j + 1];
            }
            goc->soLuongMucCon--;
            return true;
        }
        if (xoaMuc(goc->mucCon[i], tieuDeCanXoa, capNhatSoTrang)) {
            goc->soTrang = 0;
            for (int k = 0; k < goc->soLuongMucCon; ++k) {
                goc->soTrang += goc->mucCon[k]->soTrang;
            }
            return true;
        }
    }
    return false;
}

int main() {
    Node* sach = new Node("Sach", 0);

    Node* chuong1 = new Node("Chuong 1", 0);
    Node* chuong2 = new Node("Chuong 2", 0);

    Node* muc1_1 = new Node("Muc 1.1", 10);
    Node* muc1_2 = new Node("Muc 1.2", 20);
    Node* muc1_3 = new Node("Muc 1.3", 15);

    Node* muc2_1 = new Node("Muc 2.1", 25);
    Node* muc2_2 = new Node("Muc 2.2", 10);
    Node* muc2_3 = new Node("Muc 2.3", 30);

    chuong1->mucCon[chuong1->soLuongMucCon++] = muc1_1;
    chuong1->mucCon[chuong1->soLuongMucCon++] = muc1_2;
    chuong1->mucCon[chuong1->soLuongMucCon++] = muc1_3;
    chuong1->soTrang = muc1_1->soTrang + muc1_2->soTrang + muc1_3->soTrang;

    chuong2->mucCon[chuong2->soLuongMucCon++] = muc2_1;
    chuong2->mucCon[chuong2->soLuongMucCon++] = muc2_2;
    chuong2->mucCon[chuong2->soLuongMucCon++] = muc2_3;
    chuong2->soTrang = muc2_1->soTrang + muc2_2->soTrang + muc2_3->soTrang;

    sach->mucCon[sach->soLuongMucCon++] = chuong1;
    sach->mucCon[sach->soLuongMucCon++] = chuong2;
    sach->soTrang = chuong1->soTrang + chuong2->soTrang;

    int tongSoChuong = demSoChuong(sach);
    cout << "Tong so chuong: " << tongSoChuong << endl;
    inChuongVaSoTrang(sach);

    Node* chuongDaiNhat = timChuongDaiNhat(sach);
    if (chuongDaiNhat) {
        cout << "Chuong dai nhat: " << chuongDaiNhat->tieuDe 
             << " voi " << chuongDaiNhat->soTrang << " trang." << endl;
    }

    const char* mucCanXoa = "Muc 1.2";
    int capNhatSoTrang = sach->soTrang;
    if (xoaMuc(sach, mucCanXoa, capNhatSoTrang)) {
        sach->soTrang = chuong1->soTrang + chuong2->soTrang;
        cout << mucCanXoa << " da duoc xoa thanh cong." << endl;
        cout << "Cap nhat sau khi xoa muc:" << endl;
        inChuongVaSoTrang(sach);
    } else {
        cout << mucCanXoa << " khong ton tai." << endl;
    }

    delete sach;

    return 0;
}
