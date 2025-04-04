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

    //1이면 빨강 배경 아니면 파랑 배경
    if (win.color == 1) {
        printf("\033[41m");  // 빨강 배경
    }
    else {
        printf("\033[44m");  // 파랑 배경
    }

    // 위쪽 테두리 그리기
    gotoxy(win.location_x, win.location_y);
    printf("|");
    for (i = 0; i < win.width - 2; i++) {
        printf("-");
    }
    printf("|");

    // 양쪽 테두리 그리기
    for (i = 1; i < win.height - 1; i++) {
        gotoxy(win.location_x, win.location_y + i);
        printf("|");
        for (j = 1; j < win.width - 1; j++) {
            printf(" ");
        }
        printf("|");
    }

    // 중간 가로 테두리 그리기
    gotoxy(win.location_x, win.location_y + 2);
    printf("|");
    for (i = 0; i < win.width - 2; i++) {
        printf("-");
    }
    printf("|");

    // 아래쪽 테두리 그리기
    gotoxy(win.location_x, win.location_y + win.height - 1);
    printf("|");
    for (i = 0; i < win.width - 2; i++) {
        printf("-");
    }
    printf("|");

    // 창 제목 
    gotoxy(win.location_x + 1, win.location_y + 1);
    printf(" %s ", win.name);

    // 배경색 초기화 (초록색)
    printf("\033[42m");
}