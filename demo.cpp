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

}

void CONRAN::VeRan() { // Hàm vẽ rắn

}

void CONRAN::DiChuyen(int x, int y) { // Hàm di chuyển của rắn

}

bool CONRAN::gameover() { // Rắn chết và chương trình kết thúc khi rắn tự cắn phải mình hoặc chạm tường

}

void CONRAN::VeMoi() {

}

void CONRAN::AnMoi() {   // Rắn ăn mồi thì sẽ dài ra thêm 1 đốt

}

bool CONRAN::KiemTraMoi() {  // Kiểm tra xem mồi có bị trùng với thân rắn không

}

void CONRAN::Score() {

}

int main() {
    char choice;
    CONRAN game;

    do {
        system("cls");
        cout << "\t\t\t\t\t\t\t\t\t\t\t\tMenu\n";
        cout << "\t\t\t\t\t\t\t\t\t\t1. Start Game\n";
        cout << "\t\t\t\t\t\t\t\t\t\t2. Exit\n";
        cout << "\t\t\t\t\t\t\t\t\t\t3.Infomation\n";
        cout << "\t\t\t\t\t\t\t\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                game.startGame();
                break;
            case '2':
                cout << "Exiting...\n";
                break;
            case '3':
                cout << "Đây là bài làm Snakegame đơn giản của nhóm.\n";
                cout <<"Gom cac thanh vien : \n";
                cout <<"1.Duong Phat Vinh\n";
                cout <<"2.Nguyen Dai Tung\n";
                cout <<"3.Nguyen Huynh Minh Thu\n";
                cout <<"4.Do Van Vu\n";
                wcout << "\t\t\t\tHƯỚNG DẪN" << endl;
		        cout << "\tDùng phím mũi tên để di chuyển rắn ăn mồi nhiều nhất có thể nhưng không để\n\tchạm thân và tường" << endl;
		        cout <<"Chuc cac ban may man";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
                break;
        }
    } while (choice != '2');

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
