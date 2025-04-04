#ifndef WINDOW_H
#define WINDOW_H

typedef struct {
    int width;       // ������ �⺻ũ�� ����
    int height;      // ������ �⺻ũ�� ����
    int location_x;  // ������ �⺻��ġ X ��ǥ
    int location_y;  // ������ �⺻��ġ Y ��ǥ
    char name[50];   // ������ �̸�
    int color;       // ������ ���� (1: ����, �׿�: �Ķ�)
} WindowProperties;

void gotoxy(int x, int y);
void DrawWindow(WindowProperties win);

#endif