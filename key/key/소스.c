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

        if (_kbhit()) {

            char ch = _getch();  // ���� Ű�� �޾ƿ�

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

                printf("���� ����\n");

                break;  // 'q' Ű�� ������ ���� ����

            }

        }

        system("cls");

        gotoxy(posX, posY);
        printf("A");


        // ���⿡ �ٸ� ���� ������ �� �� ����

    }



    return 0;

}
