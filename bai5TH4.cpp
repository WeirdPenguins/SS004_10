#include <iostream>
using namespace std;
class CDate {
private:
    int ngay, thang, nam;

public:

    CDate(int ngay = 1, int thang = 1, int nam = 0) : ngay(ngay), thang(thang), nam(nam) {}
    CDate operator+(int days) const {
        CDate result = *this;
        result.ngay += days;
        while (result.ngay > ngaytrongthang(result.thang, result.nam)) {
            result.ngay -= ngaytrongthang(result.thang, result.nam);
            result.thang++;
            if (result.thang > 12) {
                result.thang = 1;
                result.nam++;
            }
        }
        return result;
    }
    int operator-(const CDate& other) const {
        int days1 = countDays(*this);
        int days2 = countDays(other);
        return days1 - days2;
    }
    CDate& operator++() {
        ngay++;
        if (ngay > ngaytrongthang(thang, nam)) {
            ngay = 1;
            thang++;
            if (thang > 12) {
                thang = 1;
                nam++;
            }
        }
        return *this;
    }
    CDate& operator--() {
        ngay--;
        if (ngay < 1) {
            thang--;
            if (thang < 1) {
                thang = 12;
                nam--;
            }
            ngay = ngaytrongthang(thang, nam);
        }
        return *this;
    }


    int ngaytrongthang(int thang, int nam) const {
        if (thang == 2) {
            return (ktrnamnhuan(nam)) ? 29 : 28;
        }
        else if (thang == 4 || thang== 6 || thang == 9 ||thang == 11) {
            return 30;
        }
        else {
            return 31;
        }
    }
    bool ktrnamnhuan(int year) const {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }
    int countDays(const CDate& date) const {
        int days = 0;
        for (int i = 0; i < date.nam; ++i) {
            days += ktrnamnhuan(i) ? 366 : 365;
        }
        for (int i = 1; i < date.thang; ++i) {
            days += ngaytrongthang(i, date.nam);
        }
        days += date.ngay;
        return days;
    }

    friend ostream& operator<<(ostream& out, const CDate& date) {
        out << date.ngay << "/" << date.thang << "/" << date.nam;
        return out;
    }

    friend istream& operator>>(istream& in, CDate& date) {
        cout << "Nhập ngày, tháng, năm: ";
        in >> date.ngay >> date.thang >> date.nam;
        return in;
    }
};

int main() {
    CDate date1;
    cout << "Hay nhap thao tac ban muon thuc hien: \n";
    while (1) {
        cout << "1. Nhap vao lan luot ngay, thang, nam (ngay/thang/nam).\n";
        cout << "2. Cong cho mot so ngay cho truoc.\n";
        cout << "3. Tru cho mot so ngay cho truoc.\n";
        cout << "4. Tang ngay len 1.\n";
        cout << "5. Giam ngay xuong 1.\n";
        cout << "6. Tinh khoang cach giua hai moc thoi gian.\n";
        cout << "7. Xuat ngay, thang, nam.\n";
        cout << "8. Thoat chuong trinh.\n";
        int x;  cin >> x;
        if (x == 1) {
            cin >> date1;
        }
        else if (x == 2) {
            int b; cin >> b;
            cout << date1 + b << '\n';
        }
        else if (x == 3) {
            int b; cin >> b;
            cout << date1 - b << '\n';
        }
        else if (x == 4) {
            cout << ++date1 << '\n';
        }
        else if (x == 5) {
            cout << --date1 << '\n';
        }
        else if (x == 6) {
            CDate date2;
            cin >> date2;
            cout << date1 - date2 << '\n';
        }
        else if (x == 7) {
            cout << date1;
        }
        else if (x == 8) {
            cout << "Da thoat chuong trinh!!!\n";
            break;
        }
    }
    return 0;
}