#include <iostream>
using namespace std;

class Point
{
private:
    float X, Y;
public:
    void Nhap() {
       cin>>X>>Y;
    }
    void Xuat() {
     cout<<"("<<X<<", "<<Y<<")"<<endl;
    }
    void setX(float newX) {
       X = newX;
    }
    void setY(float newY) {
       Y = newY;
    }
    float getX() {
      return X;
    }
    float getY() {
      return Y;
    }
    void TinhTien(float dx, float dy) {
      X += dx;
      Y += dy;
    }
     void Quay(float angle) {
       float radian = angle * M_PI / 180;
       X = (X * cos(radian) - Y * sin(radian));
       Y = (X * sin(radian) + Y * cos(radian));
    }
};

class DaGiac
{
   private:
       Diem *p;
       int n;
   public:
     DaGiac() {
       p = NULL;
       n = 0;
     }
     ~DaGiac() {
       delete[] p;
     }
     void Nhap() {
      cout<<"Nhap so dinh cua da giac: ";
      cin>>n;
      p = new Diem[n];
      for(int i = 0; i< n; i++) {
         cout<<"Nhap toa do diem thu "<<i+1<<": \n";
         cin>>p[i].Nhap();
      }
    }
    void Xuat() {
     cout<<"Da giac co cac dinh la: "<<endl;
     for (int i = 0 ; i < n; i++) {
        cout<<"("<<p[i].getX<<", "<<p[i].getY<<")"<<endl;
     }
     cout<<endl;
    }
    void TinhTien(float dx, float dy) {
     for (int i = 0 ; i < n; i++) {
        p[i].TinhTien(dx, dy);
     }
    }
    void
};

int main()
{


    return 0;
}

