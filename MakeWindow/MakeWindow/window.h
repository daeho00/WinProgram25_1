#ifndef WINDOW_H
#define WINDOW_H

typedef struct {
    int width;       // 윈도우 기본크기 가로
    int height;      // 윈도우 기본크기 세로
    int location_x;  // 윈도우 기본위치 X 좌표
    int location_y;  // 윈도우 기본위치 Y 좌표
    char name[50];   // 윈도우 이름
    int color;       // 윈도우 색상 (1: 빨강, 그외: 파랑)
} WindowProperties;

void gotoxy(int x, int y);
void DrawWindow(WindowProperties win);

#endif