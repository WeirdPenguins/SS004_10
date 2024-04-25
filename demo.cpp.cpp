#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;


void gotoxy( int column, int line ); //Hàm goto
void VeKhung(); //Vẽ tường cho game


struct Point{
    int x,y;
};

class CONRAN{
public:
    Point A[100]; // Con rắn
    Point Qua; //Qủa: mồi của rắn
    int DoDai; // Độ dài hiện tại của con rắn

    CONRAN(){
        //HÀM KHỞI TẠO GIÁ TRỊ MẶC ĐỊNH ĐỘ DÌ CỦA CON RẮN BAN ĐẦU
    }
    void Ve(){
       //Hàm vẽ rắn
    }
    void DiChuyen(int Huong){
        //HÀM DI CHUYỂN CỦA CON RẮN
    }
};

int main()
{
    CONRAN r;
    int Huong = 0;
    char t;

    while (1){
        if (kbhit()){
            t = getch();
            if (t=='a') Huong = 2;
            if (t=='w') Huong = 3;
            if (t=='d') Huong = 0;
            if (t=='x') Huong = 1;
        }
        system("cls");
        r.Ve();
        r.DiChuyen(Huong);
        Sleep(300);
    }

    return 0;
}


void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }
