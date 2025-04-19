#include <iostream>
using namespace std;

struct Node {
    int duLieu;
    Node* trai;
    Node* phai;
    int chieuCao;
};

int chieuCaoNode(Node* n) {
    if (n == nullptr)
        return 0;
    return n->chieuCao;
}

void capNhatChieuCao(Node* n) {
    if (n != nullptr) {
        int chieuCaoTrai = chieuCaoNode(n->trai);
        int chieuCaoPhai = chieuCaoNode(n->phai);
        n->chieuCao = (chieuCaoTrai > chieuCaoPhai ? chieuCaoTrai : chieuCaoPhai) + 1;
    }
}

int bacBang(Node* n) {
    if (n == nullptr)
        return 0;
    return chieuCaoNode(n->trai) - chieuCaoNode(n->phai);
}

Node* xoayPhai(Node* y) {
    Node* x = y->trai;
    Node* T2 = x->phai;

    x->phai = y;
    y->trai = T2;

    capNhatChieuCao(y);
    capNhatChieuCao(x);

    return x;
}

Node* xoayTrai(Node* x) {
    Node* y = x->phai;
    Node* T2 = y->trai;

    y->trai = x;
    x->phai = T2;

    capNhatChieuCao(x);
    capNhatChieuCao(y);

    return y;
}

Node* themNode(Node* goc, int duLieu) {
    if (goc == nullptr) {
        Node* node = new Node();
        node->duLieu = duLieu;
        node->trai = nullptr;
        node->phai = nullptr;
        node->chieuCao = 1;
        return node;
    }

    if (duLieu < goc->duLieu) {
        goc->trai = themNode(goc->trai, duLieu);
    } else if (duLieu > goc->duLieu) {
        goc->phai = themNode(goc->phai, duLieu);
    } else {
        return goc;
    }

    capNhatChieuCao(goc);

    int bb = bacBang(goc);

    if (bb > 1 && duLieu < goc->trai->duLieu) {
        return xoayPhai(goc);
    }

    if (bb < -1 && duLieu > goc->phai->duLieu) {
        return xoayTrai(goc);
    }

    if (bb > 1 && duLieu > goc->trai->duLieu) {
        goc->trai = xoayTrai(goc->trai);
        return xoayPhai(goc);
    }

    if (bb < -1 && duLieu < goc->phai->duLieu) {
        goc->phai = xoayPhai(goc->phai);
        return xoayTrai(goc);
    }

    return goc;
}

void duyetTrungTu(Node* goc) {
    if (goc != nullptr) {
        duyetTrungTu(goc->trai);
        std::cout << goc->duLieu << " ";
        duyetTrungTu(goc->phai);
    }
}

void duyetTienTu(Node* goc) {
    if (goc != nullptr) {
        std::cout << goc->duLieu << " ";
        duyetTienTu(goc->trai);
        duyetTienTu(goc->phai);
    }
}

void duyetHauTu(Node* goc) {
    if (goc != nullptr) {
        duyetHauTu(goc->trai);
        duyetHauTu(goc->phai);
        std::cout << goc->duLieu << " ";
    }
}

int main() {
    Node* goc = nullptr;
    int mang[] = {240, 73, 101, 21, 13, 25, 11, 37, 89, 30, 15, 51};
    int n = sizeof(mang) / sizeof(mang[0]);

    for (int i = 0; i < n; ++i) {
        goc = themNode(goc, mang[i]);
        std::cout << "Cay AVL sau khi them " << mang[i] << ":\n";
        std::cout << "Trung tu: ";
        duyetTrungTu(goc);
        std::cout << std::endl;
        std::cout << "Tien tu: ";
        duyetTienTu(goc);
        std::cout << std::endl;
        std::cout << "Hau tu: ";
        duyetHauTu(goc);
        std::cout << std::endl << std::endl;
    }

    return 0;
}