#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>

class KhoanThu {
public:
    std::string moTa;
    double soTien;

    KhoanThu(const std::string &moTa, double soTien) : moTa(moTa), soTien(soTien) {}
};

class KhoanChi {
public:
    std::string moTa;
    double soTien;

    KhoanChi(const std::string &moTa, double soTien) : moTa(moTa), soTien(soTien) {}
};

class QuanLyTaiChinh {
private:
    std::vector<KhoanThu> cacKhoanThu;
    std::vector<KhoanChi> cacKhoanChi;

public:
    void khoiTao() {
        cacKhoanThu.clear();
        cacKhoanChi.clear();
    }

    void themKhoanThu(const std::string &moTa, double soTien) {
        cacKhoanThu.emplace_back(moTa, soTien);
    }

    void lietKeKhoanThu() const {
        std::cout << "=== Sao Ke Khoan thu ===\n";
        std::cout << "+---------------------------------------------------+------------+\n";
        std::cout << "| " << std::setw(50) << std::left << "Mo ta" << " | " << std::setw(10) << "So tien" << " |\n";
        std::cout << "+---------------------------------------------------+------------+\n";
        for (const auto &kt : cacKhoanThu) {
            std::cout << "| " << std::setw(50) << std::left << kt.moTa << " | " << std::setw(10) << std::fixed << std::setprecision(2) << kt.soTien << " |\n";
        }
        std::cout << "+---------------------------------------------------+------------+\n";
    }

    void themKhoanChi(const std::string &moTa, double soTien) {
        cacKhoanChi.emplace_back(moTa, soTien);
    }

    void lietKeKhoanChi() const {
        std::cout << "=== Sao Ke Khoan chi ===\n";
        std::cout << "+---------------------------------------------------+------------+\n";
        std::cout << "| " << std::setw(50) << std::left << "Mo ta" << " | " << std::setw(10) << "So tien" << " |\n";
        std::cout << "+---------------------------------------------------+------------+\n";
        for (const auto &kc : cacKhoanChi) {
            std::cout << "| " << std::setw(50) << std::left << kc.moTa << " | " << std::setw(10) << std::fixed << std::setprecision(2) << kc.soTien << " |\n";
        }
        std::cout << "+---------------------------------------------------+------------+\n";
    }
};

class SanPham {
public:
    std::string maSanPham;
    std::string tenSanPham;
    int soLuongMua;
    int soLuongBan;
    std::string xuatXu;
    int donGia;

    SanPham(const std::string &maSanPham, const std::string &tenSanPham, const std::string &xuatXu, int soLuongMua, int soLuongBan, int donGia)
        : maSanPham(maSanPham), tenSanPham(tenSanPham), soLuongMua(soLuongMua), soLuongBan(soLuongBan), xuatXu(xuatXu), donGia(donGia) {}
};

class QuanLySanPham {
private:
    std::vector<SanPham> danhSachSanPham;

public:
    void themSanPham(const std::string &maSanPham, const std::string &tenSanPham, const std::string &xuatXu, int soLuongMua, int soLuongBan, int donGia) {
        for (auto &sp : danhSachSanPham) {
            if (sp.maSanPham == maSanPham) {
                sp.soLuongMua += soLuongMua;
                sp.soLuongBan += soLuongBan;
                return;
            }
        }
        danhSachSanPham.emplace_back(maSanPham, tenSanPham, xuatXu, soLuongMua, soLuongBan, donGia);
    }

    void kiemTraSanPham() const {
        std::cout << "Danh sach thong ke san pham:\n";
        std::cout << std::setw(20) << "Ma san pham" << std::setw(20) << "Ten san pham" << std::setw(20) << "Xuat xu" 
                  << std::setw(20) << "So luong mua" << std::setw(20) << "So luong ban" << std::setw(20) << "Don gia" << "\n";
        for (const auto &sp : danhSachSanPham) {
            std::cout << std::setw(20) << sp.maSanPham << std::setw(20) << sp.tenSanPham << std::setw(20) << sp.xuatXu 
                      << std::setw(20) << sp.soLuongMua << std::setw(20) << sp.soLuongBan << std::setw(20) << sp.donGia << "\n";
        }
    }

    void chuyenDoiSanPhamThanhThuChi(QuanLyTaiChinh &ql) const {
        for (const auto &sp : danhSachSanPham) {
            double doanhThu = sp.soLuongBan * sp.donGia;
            std::string moTaThu = "Doanh thu ban san pham: " + sp.tenSanPham;
            ql.themKhoanThu(moTaThu, doanhThu);

            double chiPhi = sp.soLuongMua * sp.donGia;
            std::string moTaChi = "Chi phi mua san pham: " + sp.tenSanPham;
            ql.themKhoanChi(moTaChi, chiPhi);
        }
    }
};

int main() {
    QuanLyTaiChinh ql;
    ql.khoiTao();
    QuanLySanPham qlsp;
    int luaChonChinh;
    int luaChonTaiChinh;
    std::string moTa;
    double soTien;

    while (true) {
        std::cout << "Chuong Trinh Quan Ly\n";
        std::cout << "1. Chuyen doi san pham thanh thu chi\n";
        std::cout << "2. Quan ly tai chinh\n";
        std::cout << "3. Thoat\n";
        std::cout << "Chon chuc nang: ";
        std::cin >> luaChonChinh;
        std::cin.ignore();

        switch (luaChonChinh) {
            case 1:
                qlsp.chuyenDoiSanPhamThanhThuChi(ql);
                std::cout << "Da chuyen doi san pham thanh cac khoan thu va chi.\n";
                break;
            case 2: {
                do {
                    std::cout << "Quan Ly tai chinh\n";
                    std::cout << "1. Nhap khoan thu\n";
                    std::cout << "2. Sao ke khoan thu\n";
                    std::cout << "3. Nhap khoan chi\n";
                    std::cout << "4. Sao ke khoan chi\n";
                    std::cout << "5. Quay lai\n";
                    std::cout << "Chon chuc nang: ";
                    std::cin >> luaChonTaiChinh;
                    std::cin.ignore();
                    switch (luaChonTaiChinh) {
                        case 1:
                            std::cout << "Nhap mo ta khoan thu: ";
                            std::getline(std::cin, moTa);
                            std::cout << "Nhap so tien: ";
                            std::cin >> soTien;
                            std::cin.ignore();
                            ql.themKhoanThu(moTa, soTien);
                            break;
                        case 2:
                            ql.lietKeKhoanThu();
                            break;
                        case 3:
                            std::cout << "Nhap mo ta khoan chi: ";
                            std::getline(std::cin, moTa);
                            std::cout << "Nhap so tien: ";
                            std::cin >> soTien;
                            std::cin.ignore();
                            ql.themKhoanChi(moTa, soTien);
                            break;
                        case 4:
                            ql.lietKeKhoanChi();
                            break;
                        case 5:
                            break;
                        default:
                            std::cout << "Lua chon khong hop le, vui long thu lai.\n";
                    }
                } while (luaChonTaiChinh != 5);
                break;
            }
            case 3:
                std::cout << "Thoat chuong trinh.\n";
                return 0;
            default:
                std::cout << "Lua chon khong hop le, vui long thu lai.\n";
        }
    }
    return 0;
}
