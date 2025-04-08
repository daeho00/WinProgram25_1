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

        if (GetAsyncKeyState(0x57) & 0x8000) {

            posY--;

        }

        if (GetAsyncKeyState(0x53) & 0x8000) {

            posY++;

        }

        if (GetAsyncKeyState(0x41) & 0x8000) {

            posX--;

        }

        if (GetAsyncKeyState(0x44) & 0x8000) {

            posX++;

        }

        if (GetAsyncKeyState(0x51) & 0x8000) {

            printf("게임 종료\n");

            break;  // Q 키를 누르면 종료

        }



        system("cls");

        gotoxy(posX, posY);
        printf("A");

        Sleep(10);


        // 여기에 다른 게임 로직이 들어갈 수 있음

    }



    return 0;

}
