#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <conio.h>
using namespace std;
void gotoxy( int column, int line ); //Hàm goto



class CONRAN {
private:
    struct Diem {
        int x, y;
    };

    struct Ran {
        Diem body[100];
        int length; //Độ dài rắn
    };

    Ran ran;
    int toc_do;
    //int tang_toc;
    int score;
    Diem Food;

public:
    CONRAN() { // Hàm khởi tạo giá trị ban đầu
        ran.length = 4;
        toc_do = 300;
      //  tang_toc = 4;
        score = 0;
    }

    void startGame();
    void VeKhung();
    void TaoRan();
    void VeRan();
    void DiChuyen(int x, int y);
    bool gameover();
    void VeMoi();
    void AnMoi();
    bool KiemTraMoi();
    void Score();
};

void CONRAN::startGame() {
    system("cls");
    VeKhung();
    TaoRan();
    VeRan();
    Food.x = 40;
    Food.y = 16;
    VeMoi();

    int x = ran.body[0].x;
    int y = ran.body[0].y;
    int huong = 2;

    while (true) {
        if (_kbhit()) {
            char c = _getch();
            if (c == -32) {
                c = _getch();
                if (c == 72 && huong != 0) {
                    huong = 1;
                } else if (c == 80 && huong != 1) {
                    huong = 0;
                } else if (c == 75 && huong != 2) {
                    huong = 3;
                } else if (c == 77 && huong != 3) {
                    huong = 2;
                }
            }
        }

        if (huong == 0) {
            y++;
        } else if (huong == 1) {
            y--;
        } else if (huong == 2) {
            x++;
        } else if (huong == 3) {
            x--;
        }
        gotoxy(ran.body[ran.length - 1].x, ran.body[ran.length - 1].y);
        cout << " ";
        DiChuyen(x, y);
        VeRan();
        Sleep(100);
        Score();
        AnMoi();
        if (gameover()) {
            gotoxy(50, 14);
            cout << "GAME OVER";
            break;
        }
    }
}

void CONRAN::VeKhung() { //Hàm vẽ tường giới hạn khu vực chơi

}

void CONRAN::TaoRan() { // Hàm tạo rắn
    int x_head = 50;
    int y_head = 10;
    for (int i = 0; i < ran.length; i++) {
        ran.body[i].x = x_head--;
        ran.body[i].y = y_head;
}

void CONRAN::VeRan() { // Hàm vẽ rắn
    for (int i = 0; i < ran.length; i++) {
        gotoxy(ran.body[i].x, ran.body[i].y);
        if (i == 0) {
            cout << "0";
        }
        else if ( i == ran.length - 1 ) {
            cout << -;
        }
         else {
            cout << "O";
        }
    }
}

void CONRAN::DiChuyen(int x, int y) { // Hàm di chuyển của rắn
    for (int i = ran.length - 1; i > 0; i--)
        ran.body[i] = ran.body[i - 1];
    ran.body[0].x = x;
    ran.body[0].y = y;


}




}

bool CONRAN::gameover() { // Rắn chết và chương trình kết thúc khi rắn tự cắn phải mình hoặc chạm tường

}

void CONRAN::VeMoi() {

    gotoxy(Food.x, Food.y);
    cout << "X";

}

void CONRAN::AnMoi() {   // Rắn ăn mồi thì sẽ dài ra thêm 1 đốt

}

bool CONRAN::KiemTraMoi() {  // Kiểm tra xem mồi có bị trùng với thân rắn không
   for (int i = 0; i < ran.length; ++i) {
        if (Food.x == ran.body[i].x && Food.y == ran.body[i].y) {
            return true;
        }
    }
    return false;
}

void CONRAN::Score() {

}

int main() {
    CONRAN game;
    game.startGame();
    _getch();
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
