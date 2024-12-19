#include <iostream>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

class Person {
private:
    string name;  
    Date birthdate;  
    string hometown;  

public:
    void nhapThongTin() {
        cout << "Nhap ten: ";
        cin.ignore();
        getline(cin, name);

        cout << "Nhap ngay sinh (dd mm yyyy): ";
        cin >> birthdate.day >> birthdate.month >> birthdate.year;

        cout << "Nhap que quan: ";
        cin.ignore();
        getline(cin, hometown);
    }

    void hienThiThongTin() {
        cout << "Ten: " << name << endl;
        cout << "Ngay sinh: " << birthdate.day << "/" << birthdate.month << "/" << birthdate.year << endl;
        cout << "Que quan: " << hometown << endl;
    }

    string layTen() {
        return name;
    }

    void ganTen(const string& newName) {
        name = newName;
    }

    string layQueQuan() {
        return hometown;
    }

    void ganQueQuan(const string& newHometown) {
        hometown = newHometown;
    }

    Date layNgaySinh() {
        return birthdate;
    }

    void ganNgaySinh(int day, int month, int year) {
        birthdate.day = day;
        birthdate.month = month;
        birthdate.year = year;
    }
};

int main() {
    Person p;

    p.nhapThongTin();

    cout << "\nThong tin cua nguoi vua nhap:\n";
    p.hienThiThongTin();

    cout << "\nTen cua nguoi: " << p.layTen() << endl;
    p.ganTen("Tran Van An");
    cout << "Sau khi gan ten moi: ";
    p.hienThiThongTin();

    cout << "\nQue quan cua nguoi: " << p.layQueQuan() << endl;
    p.ganQueQuan("Ha Noi");
    cout << "Sau khi gan que quan moi: ";
    p.hienThiThongTin();

    Date birthdate = p.layNgaySinh();
    cout << "\nNgay sinh cua nguoi: " << birthdate.day << "/" << birthdate.month << "/" << birthdate.year << endl;

    p.ganNgaySinh(15, 8, 1995);
    cout << "Sau khi gan ngay sinh moi: ";
    p.hienThiThongTin();

    return 0;
}
