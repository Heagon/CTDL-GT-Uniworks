#include <iostream>
#include <vector>
#include <string>

using namespace std;

// input info
struct Product {
    int id;
    string name;
    string unit;
    long price;
};

// ngay thang nam
struct Date {
    int day;
    int month;
    int year;
};
//hoa don
struct Invoice {
    int id;
    Date date;
    vector<pair<Product, int>> products; 
    long total;
};

// input 1
Product inputProduct() {
    Product product;
    cout << "Nhap ma so san pham: ";
    cin >> product.id;
    cout << "Nhap ten san pham: ";
    cin.ignore();
    getline(cin, product.name);
    cout << "Nhap don vi tinh: ";
    getline(cin, product.unit);
    cout << "Nhap don gia: ";
    cin >> product.price;
    return product;
}

Invoice inputInvoice(const vector<Product>& products) {
    Invoice invoice;
    cout << "Nhap ma so hoa don: ";
    cin >> invoice.id;
    cout << "Nhap ngay ban (dd/mm/yyyy): ";
    cin >> invoice.date.day >> invoice.date.month >> invoice.date.year;

    // input 2
    while (true) {
        int productId, quantity;
        cout << "Nhap ma so san pham mua (nhap 0 de ket thuc): ";
        cin >> productId;
        if (productId == 0)
            break;
        cout << "Nhap so luong: ";
        cin >> quantity;

        bool found = false;
        for (const auto& product : products) {
            if (product.id == productId) {
                invoice.products.push_back(make_pair(product, quantity));
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Khong tim thay san pham voi ma so nay. Vui long nhap lai.\n";
    }

    invoice.total = 0;
    for (const auto& item : invoice.products) {
        invoice.total += item.first.price * item.second;
    }

    return invoice;
}
//output
void displayInvoice(const Invoice& invoice) {
    cout << "Ma so hoa don: " << invoice.id << endl;
    cout << "Ngay ban: " << invoice.date.day << "/" << invoice.date.month << "/" << invoice.date.year << endl;
    cout << "Danh sach cac san pham:\n";
    for (const auto& item : invoice.products) {
        cout << "  - Ten san pham: " << item.first.name << endl;
        cout << "    Don vi tinh: " << item.first.unit << endl;
        cout << "    So luong: " << item.second << endl;
        cout << "    Thanh tien: " << item.first.price * item.second << endl;
    }
    cout << "Tong tien: " << invoice.total << endl;
}

int main() {
    vector<Product> products;
    int choice;

    while (true) {
        cout << "1. Nhap thong tin san pham\n";
        cout << "0. Ket thuc nhap\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;
        if (choice == 0)
            break;
        else if (choice == 1)
            products.push_back(inputProduct());
        else
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
    }

    Invoice customerInvoice = inputInvoice(products);

    cout << "Tong so tien khach phai tra: " << customerInvoice.total << endl;

    cout << "\nThong tin chi tiet cua hoa don:\n";
    displayInvoice(customerInvoice);

    return 0;
}
