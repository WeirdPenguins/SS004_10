#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct DONTHUC {
    double heso;
    int somu;
};
class DATHUC {
private:
    DONTHUC* donthuc;
    int capacity;
    int size;

public:
    DATHUC(int capacity = 10);
    ~DATHUC();
    void Nhap(double heso, int somu);
    void Xuat();
    double TinhDaThuc(double x);
};
DATHUC::DATHUC(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->donthuc = new DONTHUC[capacity];
}

DATHUC::~DATHUC() {
    delete[] donthuc;
}

void DATHUC::Nhap(double heso, int somu) {
    if (size >= capacity) {
        cout << "Da thuc da day!" << endl;
        return;
    }
    donthuc[size].heso = heso;
    donthuc[size].somu = somu;
    size++;
}

void DATHUC::Xuat() {
    bool firstTerm = true;

    for (int i = 0; i < size; i++) {
        if (donthuc[i].heso != 0) {
            if (!firstTerm && donthuc[i].heso > 0) {
                cout << "+";
            }
            if (abs(donthuc[i].heso) != 1 || donthuc[i].somu == 0) {
                cout << donthuc[i].heso;
            } else if (donthuc[i].heso == -1) {
                cout << "-";
            }
            if (donthuc[i].somu > 0) {
                cout << "x";
                if (donthuc[i].somu > 1) {
                    cout << "^" << donthuc[i].somu;
                }
            }
            firstTerm = false;
        }
    }
    if (firstTerm) {
        cout << 0;
    }
    cout << endl;
}

double DATHUC::TinhDaThuc(double x) {
    double result = 0;

    for (int i = 0; i < size; i++) {
        result += donthuc[i].heso * pow(x, donthuc[i].somu);
    }

    return result;
}
int main() {
    DATHUC B;
    int n;
    cin >> n;
    double heso;
    int somu;
    for (int i = 0; i < n; i++) {
        cout <<"Nhap lan luot he so va so mu: ";
        cin >> heso >> somu;
        B.Nhap(heso, somu);
    }
    cout << "Da thuc vua nhap la: ";
    B.Xuat();
    double x;
    cout <<"Nhap x= ";
    cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << B.TinhDaThuc(x);
    return 0;
}