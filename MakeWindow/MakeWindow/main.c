#include <stdio.h>
#include <stdlib.h>
#include "window.h"

int main() {
    // �ʷ� ��� �� ȭ�� Ŭ����
    printf("\033[42m");
    system("cls");

    WindowProperties win1 = { 20, 7, 10, 3, "������ 1", 1 };
    WindowProperties win2 = { 20, 7, 15, 5, "������ 2", 0 };

    DrawWindow(win1);
    DrawWindow(win2);

    //���� ����
    scanf_s("%s");

    return 0;
}
