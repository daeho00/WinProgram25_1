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

        // Ű�� ��������

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

            printf("���� ����\n");

            break;  // Q Ű�� ������ ����

        }



        system("cls");

        gotoxy(posX, posY);
        printf("A");

        Sleep(10);


        // ���⿡ �ٸ� ���� ������ �� �� ����

    }



    return 0;

}
