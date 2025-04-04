#include <Windows.h>
#include <stdio.h>
#include "window.h"

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, coord);
}

void DrawWindow(WindowProperties win) {
    int i, j;

    //1�̸� ���� ��� �ƴϸ� �Ķ� ���
    if (win.color == 1) {
        printf("\033[41m");  // ���� ���
    }
    else {
        printf("\033[44m");  // �Ķ� ���
    }

    // ���� �׵θ� �׸���
    gotoxy(win.location_x, win.location_y);
    printf("|");
    for (i = 0; i < win.width - 2; i++) {
        printf("-");
    }
    printf("|");

    // ���� �׵θ� �׸���
    for (i = 1; i < win.height - 1; i++) {
        gotoxy(win.location_x, win.location_y + i);
        printf("|");
        for (j = 1; j < win.width - 1; j++) {
            printf(" ");
        }
        printf("|");
    }

    // �߰� ���� �׵θ� �׸���
    gotoxy(win.location_x, win.location_y + 2);
    printf("|");
    for (i = 0; i < win.width - 2; i++) {
        printf("-");
    }
    printf("|");

    // �Ʒ��� �׵θ� �׸���
    gotoxy(win.location_x, win.location_y + win.height - 1);
    printf("|");
    for (i = 0; i < win.width - 2; i++) {
        printf("-");
    }
    printf("|");

    // â ���� 
    gotoxy(win.location_x + 1, win.location_y + 1);
    printf(" %s ", win.name);

    // ���� �ʱ�ȭ (�ʷϻ�)
    printf("\033[42m");
}