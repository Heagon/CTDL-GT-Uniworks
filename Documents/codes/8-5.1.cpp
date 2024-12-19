#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    float x;  
    float y;  

public:
    void nhapToaDo() {
        cout << "Nhap hoanh do: ";
        cin >> x;
        cout << "Nhap tung do: ";
        cin >> y;
    }

    void hienThiToaDo() {
        cout << "(" << x << ", " << y << ")";
    }

    float layHoanhDo() {
        return x;
    }

    void ganHoanhDo(float newX) {
        x = newX;
    }

    float layTungDo() {
        return y;
    }

    void ganTungDo(float newY) {
        y = newY;
    }

    void layToaDo(float& xOut, float& yOut) {
        xOut = x;
        yOut = y;
    }

    void ganToaDo(float newX, float newY) {
        x = newX;
        y = newY;
    }

    float tinhKhoangCach(const Point& p) {
        return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
    }
};

int main() {
    Point p1, p2;

    cout << "Nhap toa do cho diem thu nhat:\n";
    p1.nhapToaDo();
    cout << "Nhap toa do cho diem thu hai:\n";
    p2.nhapToaDo();

    cout << "\nToa do cua diem thu nhat: ";
    p1.hienThiToaDo();
    cout << "\nToa do cua diem thu hai: ";
    p2.hienThiToaDo();
    cout << endl;

    float khoangCach = p1.tinhKhoangCach(p2);
    cout << "\nKhoang cach giua hai diem: " << khoangCach << endl;

    p1.ganToaDo(5.0, 5.0);
    cout << "\nToa do cua diem thu nhat sau khi thay doi: ";
    p1.hienThiToaDo();
    cout << endl;

    p2.ganTungDo(10.0);
    cout << "Toa do cua diem thu hai sau khi gan tung do moi: ";
    p2.hienThiToaDo();
    cout << endl;

    return 0;
}
