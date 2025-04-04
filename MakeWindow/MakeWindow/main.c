#include <stdio.h>
#include <stdlib.h>
#include "window.h"

int main() {
    // 초록 배경 후 화면 클리어
    printf("\033[42m");
    system("cls");

    WindowProperties win1 = { 20, 7, 10, 3, "윈도우 1", 1 };
    WindowProperties win2 = { 20, 7, 15, 5, "윈도우 2", 0 };

    DrawWindow(win1);
    DrawWindow(win2);

    //종료 지연
    scanf_s("%s");

    return 0;
}
