#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <conio.h>
using namespace std;

#define MAX_RIGHT 104
#define MAX_LEFT 10
#define MAX_ABOVE 1
#define MAX_UNDER 25

void gotoxy( int column, int line ); //Hàm goto
void getChar( int &huong); // Lấy kí tự từ bàn phím


class CONRAN {
private:
    struct Point {
        int x, y;
    };

    struct Ran {
        Point body[100];
        int length; //Độ dài rắn
    };

    Ran ran;
    int toc_do;
    //int tang_toc;
    int score;
    Point Food;

public:
    CONRAN() { // Hàm khởi tạo giá trị ban đầu
        ran.length = 3;
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

void menu (CONRAN game);

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
// Hướng 0: Đi xuống
// Hướng 1: Đi lên
// Hướng 2: Sang phải
// Hướng 3: Sang trái
// Di chuyển bằng phím mũi tên hoặc các phím AWSD
      while (true) {
        getChar(huong);

        if (huong == 0) {
            y++;
        } else if (huong == 1) {
            y--;
        } else if (huong == 2) {
            x++;
        } else if (huong == 3) {
            x--;
        }
        //Di chuyển con trỏ in đến tọa độ của điểm cuối cùng của con rắn trên màn hình.
        gotoxy(ran.body[ran.length - 1].x, ran.body[ran.length - 1].y);
        // In khoảng trắng tại điểm cuối của rắn, giúp xóa điểm cuối cùng, tạo cảm giác như rắn di chuyển
        cout << " ";
        DiChuyen(x, y);
        VeRan();
        Sleep(100);
        Score();
        AnMoi();
        if (gameover()) {
            gotoxy(50, 14);
            cout << "GAME OVER!!!";
            gotoxy(50, 15);
            cout << "Your Score : " << score;
            gotoxy(30, 16);
            cout << "Press any key, or wait 3 seconds to return to the menu.";
            Sleep(3000);
            score = 0;
            break;
        }
    }
}



void CONRAN::VeKhung() { //Hàm vẽ tường giới hạn khu vực chơi
    for (int i = MAX_LEFT; i <= MAX_RIGHT; i++) {
        gotoxy(i, MAX_ABOVE);
        cout << (char)220;
        gotoxy(i, MAX_UNDER + 1);
        cout << (char)223;
    }
    for (int i = MAX_ABOVE + 1; i <= MAX_UNDER; i++) {
        gotoxy(MAX_LEFT, i);
        cout << (char)221;
        gotoxy(MAX_RIGHT, i);
        cout << (char)222;
    }
}
void CONRAN::TaoRan() { // Hàm tạo rắn
    int x_head = 50;
    int y_head = 10;
    for (int i = 0; i < ran.length; i++) {
        ran.body[i].x = x_head--;
        ran.body[i].y = y_head;
      }
}

void CONRAN::VeRan() { // Hàm vẽ rắn
    for (int i = 0; i < ran.length; i++) {
        gotoxy(ran.body[i].x, ran.body[i].y);
        if (i == 0) {
            cout << (char)254;
        }
        else {
            cout << (char)219;
        }
    }
}

void CONRAN::DiChuyen(int x, int y) { // Hàm di chuyển của rắn
    for (int i = ran.length - 1; i > 0; i--) {
        ran.body[i] = ran.body[i - 1];
    }
    ran.body[0].x = x;
    ran.body[0].y = y;
}



bool CONRAN::gameover() { // Rắn chết và chương trình kết thúc khi rắn tự cắn phải mình hoặc chạm tường
     for (int i = 1; i < ran.length; i++) {
        if (ran.body[i].x == ran.body[0].x && ran.body[i].y == ran.body[0].y) {
            return true;
        }
    }
    if (ran.body[0].x == MAX_LEFT || ran.body[0].x == MAX_RIGHT || ran.body[0].y == MAX_ABOVE || ran.body[0].y == MAX_UNDER) {
        return true;
    }
    return false;
}


void CONRAN::VeMoi() {
    gotoxy(Food.x, Food.y);
    cout << (char)42;

}

void CONRAN::AnMoi() {   // Rắn ăn mồi thì sẽ dài ra thêm 1 đốt
    if (ran.body[0].x == Food.x && ran.body[0].y == Food.y) {
        ran.length++;
        do {
            Food.x = rand() % (MAX_RIGHT - MAX_LEFT) + MAX_LEFT+1;
            Food.y = rand() % (MAX_UNDER - MAX_ABOVE) + MAX_ABOVE+1;
        } while (KiemTraMoi());
        VeMoi();
    }
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
    if (ran.body[0].x == Food.x && ran.body[0].y == Food.y) {
        gotoxy(107, 2);
        score += 5;
        cout << "Score: " << score;
    }
}

int main() {
    CONRAN game;
    menu(game);
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

  void getChar(int &huong)
{
        if (_kbhit()) {
            char c = _getch();
            if (c == -32) {   // Kiểm tra xem có phải là các phím mũi tên không
                c = _getch();
                if (  c == 72   && huong != 0) {
                    huong = 1;
                } else if ( c == 80  && huong != 1) {
                    huong = 0;
                } else if ( c == 75 && huong != 2) {
                    huong = 3;
                } else if ( c == 77 && huong != 3) {
                    huong = 2;
                }
            }
         else {
                if ((c == 'w') && huong != 0) {
                    huong = 1;
                } else if ((c == 's') && huong != 1) {
                    huong = 0;
                } else if ((c == 'a') && huong != 2) {
                    huong = 3;
                } else if ((c == 'd') && huong != 3) {
                    huong = 2;
                }
            }
        }
}

void menu(CONRAN game)
{
       do {
    system("cls");
    cout << "\t\t\t\t\t\t\tMenu\n";
    cout << "\t\t\t\t\t\t1. Start Game\n";
    cout << "\t\t\t\t\t\t2. Information\n";
    cout << "\t\t\t\t\t\t3. Exit\n";
    cout << "\t\t\t\t\tSelect your choice from the keyboard!\n ";

    char choice = _getch(); // Lấy lựa chọn từ bàn phím

    switch (choice) {
        case '1':
            game.startGame();
            break;
        case '3':
            cout << "Exiting...\n";
            return;
        case '2':
            cout << "============================================================================" << endl;
            cout << "Day la bai lam SnakeGame don gian cua nhom.\n";
            cout << "Gom cac thanh vien : \n";
            cout << "1.Duong Phat Vinh\n";
            cout << "2.Nguyen Dai Tung\n";
            cout << "3.Nguyen Huynh Minh Thu\n";
            cout << "4.Do Van Vu\n";
            wcout << "\t\t\t\tHUONG DAN" << endl;
            cout << "Dung phim mui ten de di chuyen ran an moi nhieu nhat co the." << endl;
            cout << "Khi ran dung tuong hoac tu can ban than thi game se ket thuc." << endl;
            cout << "Chuc cac ban choi vui ve!"<<endl;
            cout << "Press any key to return to the menu."<<endl;
            cout << "============================================================================" << endl;
            _getch();
            break;
        default:
            cout << "Invalid choice. Please choose again.\n";
            Sleep(1500);
            _getch();
            break;
    }
} while (true);

}
