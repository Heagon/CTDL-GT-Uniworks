#include <iostream>
#include <vector>
#include <string>

using namespace std;

// thu
struct Revenue {
    string description;
    double amount;
};

// chi
struct Expense {
    string description;
    double amount;
};

//quan ly tai chinh
class FinancialManagement {
private:
    vector<Revenue> revenues;
    vector<Expense> expenses;

public:
    void addRevenue(const string &desc, double amount) {
        revenues.push_back({desc, amount});
    }

    void listRevenues() const {
        cout << "=== Sao Ke Khoan Thu ===" << endl;
        for (const auto &rev : revenues) {
            cout << "Mo ta: " << rev.description << " - So tien: " << rev.amount << endl;
        }
    }

    void addExpense(const string &desc, double amount) {
        expenses.push_back({desc, amount});
    }

    void listExpenses() const {
        cout << "=== Sao Ke Khoan Chi ===" << endl;
        for (const auto &exp : expenses) {
            cout << "Mo ta: " << exp.description << " - So tien: " << exp.amount << endl;
        }
    }
};

int main() {
    FinancialManagement fm;
    int choice;
    string description;
    double amount;

    do {
        cout << "Chuong Trinh Quan Ly Tai Chinh Phong Kham" << endl;
        cout << "1. Nhap khoan thu" << endl;
        cout << "2. Sao ke khoan thu" << endl;
        cout << "3. Nhap khoan chi" << endl;
        cout << "4. Sao ke khoan chi" << endl;
        cout << "5. Thoat" << endl;
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap mo ta khoan thu: ";
                cin.ignore(); 
                getline(cin, description);
                cout << "Nhap so tien: ";
                cin >> amount;
                fm.addRevenue(description, amount);
                break;
            case 2:
                fm.listRevenues();
                break;
            case 3:
                cout << "Nhap mo ta khoan chi: ";
                cin.ignore(); 
                getline(cin, description);
                cout << "Nhap so tien: ";
                cin >> amount;
                fm.addExpense(description, amount);
                break;
            case 4:
                fm.listExpenses();
                break;
            case 5:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le, vui long thu lai." << endl;
        }
    } while (choice != 5);

    return 0;
}
