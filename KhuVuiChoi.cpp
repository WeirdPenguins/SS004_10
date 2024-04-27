#include <iostream>
using namespace std;

class SoVe
{
  private:
    int n;
  public:
    void NhapTroChoi()
    {
       cin>>n;
    }
    long long TinhTong();
};

long long SoVe::TinhTong()
{
    return n*20000 + 70000;
}

class SoTroChoi
{
    private:
        int m;
        SoVe *sv;
    public:
        void Nhap();
        ~SoTroChoi()
        {
            delete []sv;
        }
        long long TongSoTien();
        void Xuat()
        {
            cout<<"Tong so tien la: "<<TongSoTien();
        }

};

void SoTroChoi::Nhap()
{
    cout<<"Nhap so ve: ";
    cin>>m;
    sv = new SoVe[m];
   for(int i = 0; i < m; i++) {
         cout<<"Nhap so tro choi da choi cua ve thu "<<i+1<<": ";
         sv[i].NhapTroChoi();
   }
}

long long SoTroChoi::TongSoTien()
{
     long long sum = 0;
      for(int i = 0; i < m; i++) {
        sum+=sv[i].TinhTong();
      }
      return sum;
}

int main()
{
    SoTroChoi a;
    a.Nhap();
    a.TongSoTien();
    a.Xuat();
    return 0;

}
