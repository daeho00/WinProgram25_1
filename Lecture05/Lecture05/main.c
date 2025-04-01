#include <Windows.h>
#include <stdio.h>

void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, Cur);
}

void DrawWindow(int width, int height) {

    int i;

    // 윗쪽 테두리 그리기
    gotoxy(0, 0);
    printf("|");
    for (i = 0; i < width - 2; i++) {
        printf("-");
    }
    printf("|");

    // 양쪽 테두리 그리기
    for (i = 1; i < height - 1; i++) {
        gotoxy(0, i);
        printf("|");
        gotoxy(width - 1, i);
        printf("|");
    }

    // 윗쪽 테두리 그리기
    gotoxy(0, 2);
    printf("|");
    for (i = 0; i < width - 2; i++) {
        printf("-");
    }
    printf("|");

    // 양쪽 테두리 그리기
    for (i = 1; i < height - 1; i++) {
        gotoxy(0, i);
        printf("|");
        gotoxy(width - 1, i);
        printf("|");
    }

    // 아랫쪽 테두리 그리기
    gotoxy(0, height - 1);
    printf("|");
    for (i = 0; i < width - 2; i++) {
        printf("-");
    }
    printf("|");
}

