#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
    char name[50];  
    int day, month, year;  
    char hometown[100];  

public:
    void nhapThongTin() {
        cout << "Nhap ten (toi da 50 ky tu): ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Nhap ngay sinh (dd mm yyyy): ";
        cin >> day >> month >> year;

        cout << "Nhap que quan (toi da 100 ky tu): ";
        cin.ignore();
        cin.getline(hometown, 100);
    }

    void hienThiThongTin() {
        cout << "Ten: " << name << endl;
        cout << "Ngay sinh: " << day << "/" << month << "/" << year << endl;
        cout << "Que quan: " << hometown << endl;
    }

    const char* layTen() {
        return name;
    }

    void ganTen(const char* newName) {
        strncpy(name, newName, 49);  
        name[49] = '\0';  
    }

    const char* layQueQuan() {
        return hometown;
    }

    void ganQueQuan(const char* newHometown) {
        strncpy(hometown, newHometown, 99);  
        hometown[99] = '\0';  
    }

    void layNgaySinh(int& d, int& m, int& y) {
        d = day;
        m = month;
        y = year;
    }

    void ganNgaySinh(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
};

int main() {
    Person p1;

    p1.nhapThongTin();

    cout << "\nThong tin cua nguoi vua nhap:\n";
    p1.hienThiThongTin();

    cout << "\nTen cua nguoi: " << p1.layTen() << endl;

    p1.ganTen("Tran Van Tam");
    cout << "Sau khi gan ten moi: ";
    p1.hienThiThongTin();

    cout << "\nQue quan cua nguoi: " << p1.layQueQuan() << endl;

    p1.ganQueQuan("Hue");
    cout << "Sau khi gan que quan moi: ";
    p1.hienThiThongTin();

    int day, month, year;
    p1.layNgaySinh(day, month, year);
    cout << "\nNgay sinh cua nguoi: " << day << "/" << month << "/" << year << endl;

    p1.ganNgaySinh(15, 5, 1995);
    cout << "Sau khi gan ngay sinh moi: ";
    p1.hienThiThongTin();

    return 0;
}
