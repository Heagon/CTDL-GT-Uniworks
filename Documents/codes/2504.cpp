#include <iostream>
#include <cstring>

using namespace std;

struct Person {
    char name[50];    
    int day, month, year;  
    char hometown[100];  
};

void nhapThongTin(Person& p) {
    cout << "Nhap ten : ";
    cin.ignore(); 
    cin.getline(p.name, 50);

    cout << "Nhap ngay sinh : ";
    cin >> p.day >> p.month >> p.year;

    cout << "Nhap que quan : ";
    cin.ignore(); 
    cin.getline(p.hometown, 100);
}
void hienThiThongTin(const Person& p) {
    cout << "Ten: " << p.name << endl;
    cout << "Ngay sinh: " << p.day << "/" << p.month << "/" << p.year << endl;
    cout << "Que quan: " << p.hometown << endl;
}

const char* layTen(const Person& p) {
    return p.name;
}

void ganTen(Person& p, const char* newName) {
    strncpy(p.name, newName, 49); 
    p.name[49] = '\0'; 
}

const char* layQueQuan(const Person& p) {
    return p.hometown;
}

void ganQueQuan(Person& p, const char* newHometown) {
    strncpy(p.hometown, newHometown, 99); 
    p.hometown[99] = '\0';
}

void layNgaySinh(const Person& p, int& day, int& month, int& year) {
    day = p.day;
    month = p.month;
    year = p.year;
}

void ganNgaySinh(Person& p, int day, int month, int year) {
    p.day = day;
    p.month = month;
    p.year = year;
}

int main() {
    Person person;
    nhapThongTin(person);

    cout << "\nThong tin:\n";
    hienThiThongTin(person);

    cout << "\nTen cua nguoi: " << layTen(person) << endl;

    ganTen(person, "Nguyen Van An");
    cout << "ten moi: ";
    hienThiThongTin(person);

    cout << "\nQue quan : " << layQueQuan(person) << endl;

    ganQueQuan(person, "Ha Noi");
    cout << "que quan moi: ";
    hienThiThongTin(person);

    int day, month, year;
    layNgaySinh(person, day, month, year);
    cout << "\nNgay sinh cua nguoi: " << day << "/" << month << "/" << year << endl;

    ganNgaySinh(person, 10, 10, 1990);
    cout << "ngay sinh moi: ";
    hienThiThongTin(person);

    return 0;
}
