#include <iostream>

using namespace std;

class Complex {
private:
    float real; 
    float imag; 

public:
    void nhapDuLieu() {
        cout << "Nhap thanh phan thuc: ";
        cin >> real;
        cout << "Nhap thanh phan ao: ";
        cin >> imag;
    }

    void hienThi() {
        cout << real;
        if (imag >= 0) {
            cout << " + " << imag << "i";
        } else {
            cout << " - " << -imag << "i";
        }
    }

    float layThanhPhanThuc() {
        return real;
    }

    void ganThanhPhanThuc(float newReal) {
        real = newReal;
    }

    float layThanhPhanAo() {
        return imag;
    }

    void ganThanhPhanAo(float newImag) {
        imag = newImag;
    }

    void layThanhPhan(float& realOut, float& imagOut) {
        realOut = real;
        imagOut = imag;
    }

    void ganThanhPhan(float newReal, float newImag) {
        real = newReal;
        imag = newImag;
    }

    Complex tinhTong(const Complex& other) {
        Complex result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }
};

int main() {
    Complex c1, c2;

    cout << "Nhap du lieu cho so phuc thu nhat:\n";
    c1.nhapDuLieu();
    cout << "Nhap du lieu cho so phuc thu hai:\n";
    c2.nhapDuLieu();

    cout << "\nSo phuc thu nhat: ";
    c1.hienThi();
    cout << "\nSo phuc thu hai: ";
    c2.hienThi();
    cout << endl;

    Complex sum = c1.tinhTong(c2);
    cout << "\nTong cua hai so phuc: ";
    sum.hienThi();
    cout << endl;

    return 0;
}
