#include <iostream>
#include <string>
#include <vector>

struct Date {
    int day;
    int month;
    int year;
};

enum Status {
    FIRST_YEAR,
    SECOND_YEAR,
    THIRD_YEAR,
    FOURTH_YEAR
};

struct SinhVien {
    long mssv;
    std::string hoTen;
    Date ngaySinh;
    float diemGPA;
    Status trangThai;
};

void nhapSinhVien(SinhVien& sv) {
    std::cout << "Nhập MSSV: ";
    std::cin >> sv.mssv;
    std::cin.ignore(); 
    std::cout << "Nhập Họ và Tên: ";
    std::getline(std::cin, sv.hoTen);
    std::cout << "Nhập ngày sinh (ngày tháng năm): ";
    std::cin >> sv.ngaySinh.day >> sv.ngaySinh.month >> sv.ngaySinh.year;
    std::cout << "Nhập điểm GPA: ";
    std::cin >> sv.diemGPA;
    std::cout << "Nhập trạng thái (0: Năm thứ nhất, 1: Năm thứ hai, 2: Năm thứ ba, 3: Năm thứ tư): ";
    int status;
    std::cin >> status;
    sv.trangThai = static_cast<Status>(status);
}

void hienThiSinhVien(const SinhVien& sv) {
    std::cout << "MSSV: " << sv.mssv << std::endl;
    std::cout << "Họ và Tên: " << sv.hoTen << std::endl;
    std::cout << "Ngày sinh: " << sv.ngaySinh.day << "/" << sv.ngaySinh.month << "/" << sv.ngaySinh.year << std::endl;
    std::cout << "Điểm GPA: " << sv.diemGPA << std::endl;
    std::cout << "Trạng thái: ";
    switch (sv.trangThai) {
        case FIRST_YEAR:
            std::cout << "Năm thứ nhất" << std::endl;
            break;
        case SECOND_YEAR:
            std::cout << "Năm thứ hai" << std::endl;
            break;
        case THIRD_YEAR:
            std::cout << "Năm thứ ba" << std::endl;
            break;
        case FOURTH_YEAR:
            std::cout << "Năm thứ tư" << std::endl;
            break;
    }
    std::cout << std::endl;
}

float diemGPATrungBinh(const std::vector<SinhVien>& dsSinhVien) {
    if (dsSinhVien.empty()) return 0.0f; 
    float tongDiem = 0;
    for (const auto& sv : dsSinhVien) {
        tongDiem += sv.diemGPA;
    }
    return tongDiem / dsSinhVien.size();
}

int main() {
    int N;

    // a
    SinhVien sv1 = {123456, "Nguyen Van A", {1, 1, 2000}, 3.5, SECOND_YEAR};
    std::cout << "Thông tin sinh viên 1:" << std::endl;
    hienThiSinhVien(sv1);

    // b
    SinhVien sv2;
    std::cout << "Nhập thông tin sinh viên 2:" << std::endl;
    nhapSinhVien(sv2);
    std::cout << std::endl;

    // c
    std::cout << "Nhập số lượng sinh viên: ";
    std::cin >> N;
    std::vector<SinhVien>
    dsSinhVien(N);

    // d
    for (int i = 0; i < N; ++i) {
        std::cout << "Nhập thông tin sinh viên " << i + 1 << ":" << std::endl;
        SinhVien sv;
        nhapSinhVien(sv);
        dsSinhVien[i] = sv;
    }

    // e
    std::cout << "Danh sách sinh viên:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "Thông tin sinh viên " << i + 1 << ":" << std::endl;
        hienThiSinhVien(dsSinhVien[i]);
    }

    // f
    std::cout << "Điểm GPA trung bình của tất cả sinh viên: " << diemGPATrungBinh(dsSinhVien) << std::endl;

    // g
    SinhVien* ptrDS = dsSinhVien.data();
    std::cout << "Danh sách sinh viên (sử dụng con trỏ):" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "Thông tin sinh viên " << i + 1 << ":" << std::endl;
        hienThiSinhVien(*(ptrDS + i));
    }
    std::cout << "Điểm GPA trung bình của tất cả sinh viên (sử dụng con trỏ): " << diemGPATrungBinh(dsSinhVien) << std::endl;

    return 0;
}
