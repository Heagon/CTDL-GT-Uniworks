#include <iostream>
#include <vector>

// Khai báo cấu trúc thu nhập
struct ThuNhap {
    float khamChuaBenh;
    float thanhToanBaoHiem;
    float banSanPham;
};

// Khai báo cấu trúc chi phí
struct ChiPhi {
    float luongNhanVien;
    float muaThietBi;
    float thueMatBang;
    float chiPhiVanHanh;
};

// Hàm nhập thu nhập
void nhapThuNhap(ThuNhap &thu) {
    std::cout << "Nhap vao so tien kham chua benh: ";
    std::cin >> thu.khamChuaBenh;
    std::cout << "Nhap vao so tien thanh toan tu bao hiem: ";
    std::cin >> thu.thanhToanBaoHiem;
    std::cout << "Nhap vao so tien ban san pham: ";
    std::cin >> thu.banSanPham;
}

// Hàm nhập chi phí
void nhapChiPhi(ChiPhi &chi) {
    std::cout << "Nhap vao so tien luong nhan vien: ";
    std::cin >> chi.luongNhanVien;
    std::cout << "Nhap vao so tien mua thiet bi: ";
    std::cin >> chi.muaThietBi;
    std::cout << "Nhap vao so tien thue mat bang: ";
    std::cin >> chi.thueMatBang;
    std::cout << "Nhap vao so tien chi phi van hanh: ";
    std::cin >> chi.chiPhiVanHanh;
}

// Hàm hiển thị thu nhập
void hienThiThuNhap(const ThuNhap &thu) {
    std::cout << "So tien kham chua benh: " << thu.khamChuaBenh << std::endl;
    std::cout << "So tien thanh toan tu bao hiem: " << thu.thanhToanBaoHiem << std::endl;
    std::cout << "So tien ban san pham: " << thu.banSanPham << std::endl;
    std::cout << "Tong thu nhap: " << thu.khamChuaBenh + thu.thanhToanBaoHiem + thu.banSanPham << std::endl;
}

// Hàm hiển thị chi phí
void hienThiChiPhi(const ChiPhi &chi) {
    std::cout << "So tien luong nhan vien: " << chi.luongNhanVien << std::endl;
    std::cout << "So tien mua thiet bi: " << chi.muaThietBi << std::endl;
    std::cout << "So tien thue mat bang: " << chi.thueMatBang << std::endl;
    std::cout << "So tien chi phi van hanh: " << chi.chiPhiVanHanh << std::endl;
    std::cout << "Tong chi phi: " << chi.luongNhanVien + chi.muaThietBi + chi.thueMatBang + chi.chiPhiVanHanh << std::endl;
}

int main() {
    ThuNhap thu;
    ChiPhi chi;

    int luaChon;
    do {
        std::cout << "1. Thu nhap\n";
        std::cout << "2. Chi phi\n";
        std::cout << "3. Thoat\n";
        std::cout << "Vui long nhap lua chon cua ban: ";
        std::cin >> luaChon;

        switch (luaChon) {
            case 1: {
                nhapThuNhap(thu);
                hienThiThuNhap(thu);
                break;
            }
            case 2: {
                nhapChiPhi(chi);
                hienThiChiPhi(chi);
                break;
            }
            case 3:
                break;
            default:
                std::cout << "Lua chon khong hop le!\n";
        }
    } while (luaChon != 3);

    return 0;
}
