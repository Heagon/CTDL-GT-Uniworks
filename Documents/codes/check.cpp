#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <limits>
using namespace std;
//code cua Tung
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
friend class QuanLySanPham;
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

//code cua Long
class Sanpham {
friend class QuanLySanPham;
public:
    char maSanPham[10];
    char tenSanPham[50];
    int soLuongMua;
    int soLuongBan;
    char xuatxu[50];
    int donGia;
public:
    Sanpham(const char* maSanPham, const char* tenSanPham, const char* xuatxu, int soLuongMua, int soLuongBan, int donGia) {
        strcpy(this->maSanPham, maSanPham);
        strcpy(this->tenSanPham, tenSanPham);
        strcpy(this->xuatxu, xuatxu);
        this->soLuongMua = soLuongMua;
        this->soLuongBan = soLuongBan;
        this->donGia = donGia;
    }
    const char* getmaSanPham() const {
        return maSanPham;
    }
    void updateSanpham(int soLuongMua, int soLuongBan) {
        this->soLuongMua += soLuongMua;
        this->soLuongBan += soLuongBan;
    }
    void display() const {
        cout << left << setw(20) << maSanPham
             << setw(20) << tenSanPham
             << setw(20) << xuatxu
             << setw(20) << soLuongMua
             << setw(20) << soLuongBan
             << setw(20) << donGia
             << endl;
    }
	};
class QuanLySanpham {
private:
    vector<Sanpham> danhSachSanPham;
public:
    void themSanpham(const char* maSanPham, const char* tenSanPham, const char* xuatxu, int soLuongMua, int soLuongBan, int donGia) {
        for (auto& sp : danhSachSanPham) {
            if (strcmp(sp.getmaSanPham(), maSanPham) == 0) {
                sp.updateSanpham(soLuongMua, soLuongBan);
                return;
            }
        }
        danhSachSanPham.emplace_back(maSanPham, tenSanPham, xuatxu, soLuongMua, soLuongBan, donGia);
    }
    void kiemtraSanpham() const {
        cout << "Danh sach thong ke san pham:\n";
        cout << left << setw(20) << "Ma san pham"
             << setw(20) << "Ten san pham"
             << setw(20) << "Xuatxu"
             << setw(20) << "So luong mua"
             << setw(20) << "So luong ban"
             << setw(20) << "Don gia"
             << endl;
        for (const auto& sp : danhSachSanPham) {
            sp.display();
        }
    }
    void chuyenDoiSanPhamThanhThuChi(QuanLyTaiChinh &ql) const {
        for (const auto &sp : danhSachSanPham) {
            double doanhThu = sp.soLuongBan * sp.donGia;
            std::string moTaThu = std::string("Doanh thu: ") + sp.tenSanPham;
            ql.themKhoanThu(moTaThu, doanhThu);

            double chiPhi = sp.soLuongMua * sp.donGia;
			std::string moTaChi = std::string("Chi phi: ") + sp.tenSanPham;
            ql.themKhoanChi(moTaChi, chiPhi);
        }
    }
	};
//code cua Cuong
class XinViec {
public:
    float so_thu_tu;
    std::string ten;
    std::string gioi_tinh;
    std::string ngay_sinh;
    std::string dia_chi;
    std::string hoc_van;
    std::string trang_thai_cong_tac;
    std::string cong_viec_ung_tuyen;
    std::string noi_lam_viec;
    double luong_co_ban;
	};
class NhanVienChinhThuc {
public:
    std::string ten;
    std::string ma_dinh_danh;
    std::string gioi_tinh;
    std::string dia_chi;
    std::string hoc_van;
    std::string trang_thai_cong_tac;
    std::string so_dien_thoai_lien_he;
	};
class NghiViec {
public:
    std::string ma_dinh_danh;
    std::string ly_do;
	};
class LichTruc {
public:
    std::string ma_dinh_danh;
    std::string thoi_gian;
    std::string ten_nhan_vien_truc;
	};
class QuanLyNhanVien {
public:
	    std::vector<XinViec> danh_sach_nhan_vien_xin_viec;
	    std::vector<NghiViec> danh_sach_nghi_viec;
	    std::vector<LichTruc> danh_sach_lich_truc;
	    std::vector<NhanVienChinhThuc> danh_sach_nhan_vien_chinh_thuc;
	
	    void initQuanLyNhanVien();
	    void themUngVienXinViec(const XinViec& xv);
	    void themNghiViec(const NghiViec& nv);
	    void nhapThongTinNhanVien(NhanVienChinhThuc& nvct);
	    void themNhanVienChinhThuc();
	    void xuatDanhSachNhanVienChinhThuc();
	    void themLichTruc();
	    void xuatDanhSachLichTruc();
	};
	void QuanLyNhanVien::initQuanLyNhanVien() {
	    danh_sach_nhan_vien_xin_viec.clear();
	    danh_sach_nhan_vien_chinh_thuc.clear();
	    danh_sach_nghi_viec.clear();
	    danh_sach_lich_truc.clear();
	}
	void QuanLyNhanVien::themUngVienXinViec(const XinViec& xv) {
	    danh_sach_nhan_vien_xin_viec.push_back(xv);
	    std::cout << "Ung cu vien xin viec " << danh_sach_nhan_vien_xin_viec.size() << ":\n";
	    std::cout << "  So thu tu: " << xv.so_thu_tu << "\n";
	    std::cout << "  Ten: " << xv.ten << "\n";
	    std::cout << "  Gioi tinh: " << xv.gioi_tinh << "\n";
	    std::cout << "  Ngay sinh: " << xv.ngay_sinh << "\n";
	    std::cout << "  Dia chi: " << xv.dia_chi << "\n";
	    std::cout << "  Hoc van: " << xv.hoc_van << "\n";
	    std::cout << "  Trang thai cong tac: " << xv.trang_thai_cong_tac << "\n";
	    std::cout << "  Cong viec ung tuyen: " << xv.cong_viec_ung_tuyen << "\n";
	    std::cout << "  Noi lam viec: " << xv.noi_lam_viec << "\n";
	    std::cout << "  Muc luong yeu cau co ban: " << xv.luong_co_ban << "\n";
	}
	void QuanLyNhanVien::themNghiViec(const NghiViec& nv) {
	    danh_sach_nghi_viec.push_back(nv);
	    bool found = false;
	    for (auto it = danh_sach_nhan_vien_chinh_thuc.begin(); it != danh_sach_nhan_vien_chinh_thuc.end(); ++it) {
	        if (it->ma_dinh_danh == nv.ma_dinh_danh) {
	            danh_sach_nhan_vien_chinh_thuc.erase(it);
	            found = true;
	            break;
	        }
	    }
	    if (!found) {
	        std::cout << "Khong tim thay nhan vien voi ma dinh danh tuong ung.\n";
	    }
	}
	void QuanLyNhanVien::nhapThongTinNhanVien(NhanVienChinhThuc& nvct) {
	    std::cout << "Nhap ten nhan vien: ";
	    std::getline(std::cin, nvct.ten);
	    std::cout << "Nhap ma dinh danh: ";
	    std::getline(std::cin, nvct.ma_dinh_danh);
	    std::cout << "Nhap gioi tinh: ";
	    std::getline(std::cin, nvct.gioi_tinh);
	    std::cout << "Nhap dia chi: ";
	    std::getline(std::cin, nvct.dia_chi);
	    std::cout << "Nhap hoc van: ";
	    std::getline(std::cin, nvct.hoc_van);
	    std::cout << "Nhap trang thai cong tac: ";
	    std::getline(std::cin, nvct.trang_thai_cong_tac);
	    std::cout << "Nhap so dien thoai lien he: ";
	    std::getline(std::cin, nvct.so_dien_thoai_lien_he);
	}
	void QuanLyNhanVien::themNhanVienChinhThuc() {
	    NhanVienChinhThuc nvct;
	    nhapThongTinNhanVien(nvct);
	    danh_sach_nhan_vien_chinh_thuc.push_back(nvct);
	}
	void QuanLyNhanVien::xuatDanhSachNhanVienChinhThuc() {
	    std::cout << "Danh sach nhan vien chinh thuc hom nay la:\n";
	    std::cout << "+--------------------------------+------------------------------------------------------------------------+\n";
	    for (const auto& nvct : danh_sach_nhan_vien_chinh_thuc) {
	        std::cout << "| " << std::left << std::setw(30) << "Ten" << " | " << nvct.ten << "\n";
	        std::cout << "| " << std::left << std::setw(30) << "Ma dinh danh" << " | " << nvct.ma_dinh_danh << "\n";
	        std::cout << "| " << std::left << std::setw(30) << "Gioi tinh" << " | " << nvct.gioi_tinh << "\n";
	        std::cout << "| " << std::left << std::setw(30) << "Dia chi" << " | " << nvct.dia_chi << "\n";
	        std::cout << "| " << std::left << std::setw(30) << "Hoc van" << " | " << nvct.hoc_van << "\n";
	        std::cout << "| " << std::left << std::setw(30) << "Trang thai cong tac" << " | " << nvct.trang_thai_cong_tac << "\n";
	        std::cout << "| " << std::left << std::setw(30) << "So dien thoai lien he" << " | " << nvct.so_dien_thoai_lien_he << "\n";
	    }
	    std::cout << "+--------------------------------+------------------------------------------------------------------------+\n";
	}
	void QuanLyNhanVien::themLichTruc() {
	    LichTruc lt;
	    std::cout << "Nhap ma dinh danh: ";
	    std::getline(std::cin, lt.ma_dinh_danh);
	    std::cout << "Nhap thoi gian: ";
	    std::getline(std::cin, lt.thoi_gian);
	    std::cout << "Nhap ten nhan vien truc: ";
	    std::getline(std::cin, lt.ten_nhan_vien_truc);
	    danh_sach_lich_truc.push_back(lt);
	}
	void QuanLyNhanVien::xuatDanhSachLichTruc() {
	    std::cout << "Danh sach lich truc:\n";
	    std::cout << "+----------------------+----------------------------------------------------+--------------------------------+\n";
	    std::cout << "| " << std::left << std::setw(20) << "Ma dinh danh" << " | " << std::left << std::setw(50) << "Thoi gian" << " | " << std::left << std::setw(30) << "Ten nhan vien truc" << "\n";
	    std::cout << "+----------------------+----------------------------------------------------+--------------------------------+\n";
	    for (const auto& lt : danh_sach_lich_truc) {
	        std::cout << "| " << std::left << std::setw(20) << lt.ma_dinh_danh << " | " << std::left << std::setw(50) << lt.thoi_gian << " | " << std::left << std::setw(30) << lt.ten_nhan_vien_truc << "\n";
	    }
	    std::cout << "+----------------------+----------------------------------------------------+--------------------------------+\n";
	}
//code cua Lam
class NgaySinh {
public:
    int ngay;
    int thang;
    int nam;
    NgaySinh(int ngay = 0, int thang = 0, int nam = 0)
        : ngay(ngay), thang(thang), nam(nam) {}
	};
class BenhNhanNhapVien {
public:
    std::string hoVaTen;
    std::string maDinhDanh;
    NgaySinh ngaySinh;
    std::string gioiTinh;
    std::string diaChi;
    std::string soDienThoai;
    std::string lichSuBenhAn;
    std::string lichSuNhaKhoa;
    std::string tinhTrangHienTai;
	}; 
class LichKham {
public:
    std::string hoVaTen;
    std::string maDinhDanh;
    std::string thoiGianKham;
    std::string lyDoKham;
	};
std::vector<BenhNhanNhapVien> benhNhanNhapVien;
std::vector<LichKham> lichKham;
void removeNewline(std::string &str) {
    if (!str.empty() && str.back() == '\n') {
        str.pop_back();
    }
	}
void nhapVien() {
    if (benhNhanNhapVien.size() >= 100) {
        std::cout << "So luong benh nhan da dat toi da.\n";
        return;
    }
    BenhNhanNhapVien bn;
    std::cout << "Nhap ten benh nhan: ";
    std::getline(std::cin, bn.hoVaTen);
    std::cout << "Nhap ma dinh danh: ";
    std::getline(std::cin, bn.maDinhDanh);
    std::cout << "Nhap ngay sinh (dd mm yyyy): ";
    std::cin >> bn.ngaySinh.ngay >> bn.ngaySinh.thang >> bn.ngaySinh.nam;
    std::cin.ignore(); 
    std::cout << "Nhap gioi tinh: ";
    std::getline(std::cin, bn.gioiTinh);
    std::cout << "Nhap noi o cua benh nhan: ";
    std::getline(std::cin, bn.diaChi);
    std::cout << "Nhap so dien thoai cua benh nhan: ";
    std::getline(std::cin, bn.soDienThoai);
    std::cout << "Nhap lich su benh an: ";
    std::getline(std::cin, bn.lichSuBenhAn);
    std::cout << "Nhap lich su nha khoa: ";
    std::getline(std::cin, bn.lichSuNhaKhoa);
    std::cout << "Nhap tinh trang hien tai: ";
    std::getline(std::cin, bn.tinhTrangHienTai);
    benhNhanNhapVien.push_back(bn);
    std::cout << "Benh nhan da duoc nhap vien.\n";
	}
void xuatVien() {
    if (benhNhanNhapVien.empty()) {
        std::cout << "Khong co benh nhan nao de xuat vien.\n";
        return;
    }
    std::cout << "Danh sach benh nhan nhap vien:\n";
    for (size_t i = 0; i < benhNhanNhapVien.size(); ++i) {
        std::cout << i + 1 << ". " << benhNhanNhapVien[i].hoVaTen << " (Ma dinh danh: " << benhNhanNhapVien[i].maDinhDanh << ")\n";
    }
    std::cout << "Chon benh nhan de xuat vien (1-" << benhNhanNhapVien.size() << "): ";
    int chon;
    std::cin >> chon;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    if (chon < 1 || static_cast<size_t>(chon) > benhNhanNhapVien.size()) {
        std::cout << "Lua chon khong hop le.\n";
        return;
    }
    size_t indexXoa = static_cast<size_t>(chon) - 1;
    std::cout << "Benh nhan " << benhNhanNhapVien[indexXoa].hoVaTen << " (Ma dinh danh: " << benhNhanNhapVien[indexXoa].maDinhDanh << ") da duoc xuat vien.\n";
    benhNhanNhapVien.erase(benhNhanNhapVien.begin() + indexXoa);
}
void datLichKham() {
    if (lichKham.size() >= 100) {
        std::cout << "So luong lich kham da dat toi da.\n";
        return;
    }
    LichKham lk;
    std::cout << "Nhap ten benh nhan: ";
    std::getline(std::cin, lk.hoVaTen);
    std::cout << "Nhap ma dinh danh: ";
    std::getline(std::cin, lk.maDinhDanh);
    std::cout << "Nhap thoi gian kham (aa:bb DD/MM/YYYY): ";
    std::getline(std::cin, lk.thoiGianKham);
    std::cout << "Nhap ly do kham: ";
    std::getline(std::cin, lk.lyDoKham);
    lichKham.push_back(lk);
    std::cout << "Lich kham da duoc dat.\n";
	}
void kiemTraLichKham() {
    if (lichKham.empty()) {
        std::cout << "Khong co lich kham.\n";
        return;
    }
    std::cout << "Danh sach lich kham:\n";
    std::cout << "+--------------------------------------------------------------------------------------------------------------------+\n";
    std::cout << "| " << std::setw(20) << "Ho va ten" << " | " << std::setw(15) << "Ma dinh danh" << " | " << std::setw(20) << "Thoi gian" << " | " << std::setw(50) << "Ly do" << " |\n";
    std::cout << "+--------------------------------------------------------------------------------------------------------------------+\n";
    for (const auto& lk : lichKham) {
        std::cout << "| " << std::setw(20) << lk.hoVaTen << " | " << std::setw(15) << lk.maDinhDanh << " | " << std::setw(20) << lk.thoiGianKham << " | " << std::setw(50) << lk.lyDoKham << " |\n";
    }
    std::cout << "+--------------------------------------------------------------------------------------------------------------------+\n";
	}

int main() {
QuanLySanpham qlsp;
    main_menu:
    int luachonchinh;
    while (true) {
        cout << "He thong quan ly phong kham nha khoa\n";
        cout << "1. Quan ly thiet bi, vat lieu y te\n";
        cout << "2. Quan ly nhan vien\n";
        cout << "3. Quan ly benh nhan\n";
        cout << "4. Quan ly tai chinh phong kham\n";
        cout << "5. Thoat chuong trinh\n";
        cout << "Lua chon cua ban la: ";
        cin >> luachonchinh;
        cin.ignore();
        switch (luachonchinh) {
            case 1: {

                int choice;
                char tenSanPham[50], xuatxu[50], maSanPham[10];
                int soLuongMua, soLuongBan, donGia;
                while (true) {
                    cout << "1. Nhap thong tin san pham\n";
                    cout << "2. Kiem tra danh sach san pham\n";
                    cout << "3. Quay lai\n";
                    cout << "Lua chon cua ban la: ";
                    cin >> choice;
                    cin.ignore();
                    switch (choice) {
                        case 1:
                            cout << "Ma san pham(chi nhap toi da 10 chu so): ";
                            cin.getline(maSanPham, sizeof(maSanPham));
                            cout << "Ten san pham: ";
                            cin.getline(tenSanPham, sizeof(tenSanPham));
                            cout << "Xuat xu san pham: ";
                            cin.getline(xuatxu, sizeof(xuatxu));
                            cout << "So luong san pham mua: ";
                            cin >> soLuongMua;
                            cout << "So luong san pham ban: ";
                            cin >> soLuongBan;
                            cout << "Don gia san pham: ";
                            cin >> donGia;
                            cin.ignore();
                            qlsp.themSanpham(maSanPham, tenSanPham, xuatxu, soLuongMua, soLuongBan, donGia);
                            break;
                        case 2:
                            qlsp.kiemtraSanpham();
                            break;
                        case 3:
                            goto main_menu;
                        default:
                            cout << "Lua chon khong hop le, vui long thu lai.\n";
                    }
                }
                break;
            	}
            case 2: {
				QuanLyNhanVien qlnv;
			    qlnv.initQuanLyNhanVien();
			    int lua_chon;
			    do {
			        std::cout << "==== Quan Ly Nhan Vien ====\n";
			        std::cout << "1. Them ung vien xin viec\n";
			        std::cout << "2. Them nghi viec\n";
			        std::cout << "3. Them nhan vien chinh thuc\n";
			        std::cout << "4. Xuat danh sach nhan vien chinh thuc\n";
			        std::cout << "5. Them lich truc\n";
			        std::cout << "6. Xuat danh sach lich truc\n";
			        std::cout << "7. Quay lai\n";
			        std::cout << "Lua chon cua ban la: ";
			        std::cin >> lua_chon;
			        std::cin.ignore(); 
			        switch (lua_chon) {
			            case 1: {
			                XinViec xv;
			                std::cout << "Nhap so thu tu: ";
			                std::cin >> xv.so_thu_tu;
			                std::cin.ignore();
			                std::cout << "Nhap ten: ";
			                std::getline(std::cin, xv.ten);
			                std::cout << "Nhap gioi tinh: ";
			                std::getline(std::cin, xv.gioi_tinh);
			                std::cout << "Nhap ngay sinh: ";
			                std::getline(std::cin, xv.ngay_sinh);
			                std::cout << "Nhap dia chi: ";
			                std::getline(std::cin, xv.dia_chi);
			                std::cout << "Nhap hoc van: ";
			                std::getline(std::cin, xv.hoc_van);
			                std::cout << "Nhap trang thai cong tac: ";
			                std::getline(std::cin, xv.trang_thai_cong_tac);
			                std::getline(std::cin, xv.cong_viec_ung_tuyen);
			                std::cout << "Nhap noi lam viec: ";
			                std::getline(std::cin, xv.noi_lam_viec);
			                std::cout << "Nhap muc luong yeu cau co ban: ";
			                std::cin >> xv.luong_co_ban;
			                std::cin.ignore(); 
                            std::cout << std::fixed << std::setprecision(2) << "Muc luong yeu cau co ban: " << xv.luong_co_ban << std::endl;
			                qlnv.themUngVienXinViec(xv);
			                break;
			            }
			            case 2: {
			                NghiViec nv;
			                std::cout << "Nhap ma dinh danh nhan vien nghi viec: ";
			                std::getline(std::cin, nv.ma_dinh_danh);
			                std::cout << "Nhap ly do nghi viec: ";
			                std::getline(std::cin, nv.ly_do);
			                qlnv.themNghiViec(nv);
			                break;
			            }
			            case 3:
			                qlnv.themNhanVienChinhThuc();
			                break;
			            case 4:
			                qlnv.xuatDanhSachNhanVienChinhThuc();
			                break;
			            case 5:
			                qlnv.themLichTruc();
			                break;
			            case 6:
			                qlnv.xuatDanhSachLichTruc();
			                break;
			            case 7:
			                goto main_menu;
			            default:
			                std::cout << "Lua chon khong hop le. Vui long chon lai.\n";
			        }
			    } while (lua_chon != 0);
			    return 0;
				break;  
				}
        	case 3: {
                int luaChon;
    			do {
			        std::cout << "\nChuong trinh quan ly benh nhan:\n";
			        std::cout << "1. Nhap vien\n";
			        std::cout << "2. Xuat vien\n";
			        std::cout << "3. Dat lich kham\n";
			        std::cout << "4. Kiem tra lich kham\n";
			        std::cout << "5. Quay lai\n";
			        std::cout << "Lua chon cua ban la: ";
			        std::cin >> luaChon;
			        std::cin.ignore();
			        switch (luaChon) {
			            case 1:
			                nhapVien();
			                break;
			            case 2:
			                xuatVien();
			                break;
			            case 3:
			                datLichKham();
			                break;
			            case 4:
			                kiemTraLichKham();
			                break;
			            case 5:
			                goto main_menu;
			            default:
			                std::cout << "Lua chon khong hop le.\n";
			        }
			    } while (luaChon != 5);
			    return 0;
			    break;
			    }
            case 4: {
                QuanLyTaiChinh ql;
                ql.khoiTao();
                qlsp.chuyenDoiSanPhamThanhThuChi(ql);

                int luachontaichinh;
                std::string mota;
                double sotien;

                do {
                    std::cout << "Quan Ly tai chinh\n";
                    std::cout << "1. Nhap khoan thu\n";
                    std::cout << "2. Sao ke khoan thu\n";
                    std::cout << "3. Nhap khoan chi\n";
                    std::cout << "4. Sao ke khoan chi\n";
                    std::cout << "5. Quay lai\n";
                    std::cout << "Lua chon cua ban la: ";
                    std::cin >> luachontaichinh;
                    std::cin.ignore();

                    switch (luachontaichinh) {
                        case 1:
                            std::cout << "Nhap mo ta khoan thu: ";
                            std::getline(std::cin, mota);
                            std::cout << "Nhap so tien: ";
                            std::cin >> sotien;
                            std::cin.ignore();
                            ql.themKhoanThu(mota, sotien);
                            break;
                        case 2:
                            ql.lietKeKhoanThu();
                            break;
                        case 3:
                            std::cout << "Nhap mo ta khoan chi: ";
                            std::getline(std::cin, mota);
                            std::cout << "Nhap so tien: ";
                            std::cin >> sotien;
                            std::cin.ignore();
                            ql.themKhoanChi(mota, sotien);
                            break;
                        case 4:
                            ql.lietKeKhoanChi();
                            break;
                        case 5:
                            goto main_menu;
                        default:
                            std::cout << "Lua chon khong hop le, vui long thu lai.\n";
                    }
                } while (luachontaichinh != 5);

                break;
            }
            case 5:
                return 0;
            default:
                cout << "Lua chon khong hop le, vui long thu lai.\n";
        }
    }
    return 0;
}