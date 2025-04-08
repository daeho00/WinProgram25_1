#include <conio.h>
#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    int posX = 10;
    int posY = 10;

    printf("\033[43m");

    while (1) {

        // 키가 눌렸으면

        if (_kbhit()) {

            char ch = _getch();  // 눌린 키를 받아옴

            if (ch == 'w') {

                posY--;

            }
            else if (ch == 's') {

                posY++;

            }
            else if (ch == 'a') {

                posX--;

            }
            else if (ch == 'd') {

                posX++;

            }
            else if (ch == 'q') {

                printf("게임 종료\n");

                break;  // 'q' 키를 누르면 게임 종료

            }

        }

        system("cls");

        gotoxy(posX, posY);
        printf("A");


        // 여기에 다른 게임 로직이 들어갈 수 있음

    }



    return 0;

}
