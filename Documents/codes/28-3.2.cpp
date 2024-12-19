#include <iostream>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

enum Status {
    FIRST_YEAR,
    SECOND_YEAR,
    THIRD_YEAR,
    FOURTH_YEAR,
    GRADUATED
};

struct SinhVien {
    long mssv;
    string hoTen;
    Date ngaySinh;
    float diemGPA;
    Status status;
};

void nhapSinhVien(SinhVien& sv) {
    cout << "Nhap MSSV: ";
    cin >> sv.mssv;
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, sv.hoTen);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    cin >> sv.ngaySinh.day >> sv.ngaySinh.month >> sv.ngaySinh.year;
    cout << "Nhap diem GPA: ";
    cin >> sv.diemGPA;
    cout << "Nhap trang thai (0 - Nam thu nhat, 1 - Nam thu hai, 2 - Nam thu ba, 3 - Nam thu tu, 4 - Da tot nghiep): ";
    int status;
    cin >> status;
    sv.status = static_cast<Status>(status);
}

void hienThiSinhVien(const SinhVien& sv) {
    cout << "MSSV: " << sv.mssv << endl;
    cout << "Ho ten: " << sv.hoTen << endl;
    cout << "Ngay sinh: " << sv.ngaySinh.day << "/" << sv.ngaySinh.month << "/" << sv.ngaySinh.year << endl;
    cout << "Diem GPA: " << sv.diemGPA << endl;
    cout << "Trang thai: ";
    switch (sv.status) {
        case FIRST_YEAR:
            cout << "Nam thu nhat" << endl;
            break;
        case SECOND_YEAR:
            cout << "Nam thu hai" << endl;
            break;
        case THIRD_YEAR:
            cout << "Nam thu ba" << endl;
            break;
        case FOURTH_YEAR:
            cout << "Nam thu tu" << endl;
            break;
        case GRADUATED:
            cout << "Da tot nghiep" << endl;
            break;
        default:
            cout << "Trang thai khong xac dinh" << endl;
            break;
    }
}

float diemGPATrungBinh(const SinhVien arr[], int size) {
    float tongDiem = 0;
    for (int i = 0; i < size; ++i) {
        tongDiem += arr[i].diemGPA;
    }
    return (size > 0) ? (tongDiem / size) : 0;
}

int main() {
    int N;
    cout << "Nhap so luong sinh vien: ";
    cin >> N;

    SinhVien danhSachSV[N];

    for (int i = 0; i < N; ++i) {
        cout << "\nNhap thong tin cho sinh vien thu " << i + 1 << ":" << endl;
        nhapSinhVien(danhSachSV[i]);
    }

    cout << "\nThong tin cua cac sinh vien:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "\nSinh vien thu " << i + 1 << ":" << endl;
        hienThiSinhVien(danhSachSV[i]);
    }

    cout << "\nDiem GPA trung binh cua mang sinh vien la: " << diemGPATrungBinh(danhSachSV, N) << endl;

    return 0;
}
