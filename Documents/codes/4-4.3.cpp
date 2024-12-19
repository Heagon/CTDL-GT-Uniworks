#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    float x; 
    float y; 
};

void nhapToaDo(Point& p) {
    cout << "Nhap hoanh do: ";
    cin >> p.x;
    cout << "Nhap tung do: ";
    cin >> p.y;
}

float tinhKhoangCach(Point p1, Point p2) {
    float distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distance;
}

void thayDoiToaDo(Point& p, float newX, float newY) {
    p.x = newX;
    p.y = newY;
}

void hienThiToaDo(Point p) {
    cout << "(" << p.x << ", " << p.y << ")";
}

int main() {
    Point p1, p2;

    cout << "Nhap toa do cho diem thu nhat:\n";
    nhapToaDo(p1);
    cout << "Nhap toa do cho diem thu hai:\n";
    nhapToaDo(p2);

    cout << "\nToa do cua diem thu nhat la: ";
    hienThiToaDo(p1);
    cout << endl;
    cout << "Toa do cua diem thu hai la: ";
    hienThiToaDo(p2);
    cout << endl;

    float distance = tinhKhoangCach(p1, p2);
    cout << "\nKhoang cach giua hai diem la: " << distance << endl;

    thayDoiToaDo(p1, 2.0, 3.0);
    cout << "\nToa do cua diem thu nhat sau khi thay doi la: ";
    hienThiToaDo(p1);
    cout << endl;

    return 0;
}
