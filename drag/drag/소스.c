//��������!! (������)

#include <windows.h>
#include <stdio.h>

int main() {
    char letter = 'O';  // ���ĺ� 'O' ����
    POINT mousePos;     // ���콺 ��ġ
    int isDragging = 0;  // �巡�� ���� (0: �巡�� �� �ƴ�, 1: �巡�� ��)
    int letterX = 10;    // ���ĺ� 'O'�� �ʱ� X ��ǥ
    int letterY = 5;     // ���ĺ� 'O'�� �ʱ� Y ��ǥ

    // �ܼ� ȭ�� �ʱ�ȭ
    system("cls");

    while (1) {
        system("cls");  // ȭ�� �ʱ�ȭ
        printf("���ĺ� '%c'�� ���콺�� �巡���ϼ���.\n", letter);
        printf("���� ���ĺ� '%c'�� ��ġ: (%d, %d)\n", letter, letterX, letterY);
        // ȭ�� ���� (�巡�� ���� ���� ��ġ ����)
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            POINT p;
            GetCursorPos(&p);  // ���콺�� ���� ȭ�� ��ǥ�� p�� ����
            letterX = p.x / 9;
            letterY = p.y / 20;
            
        }
        

        // ���ĺ� O ���
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf("%c", letter);


        // ���� ����: Q Ű�� ������ ���α׷� ����
        if (GetAsyncKeyState(0x51) & 0x8000) {
            printf("\n���α׷� ����\n");
            break;
        }

        // ��� ��� (CPU ��� ����ȭ)
        Sleep(10);
    }

    return 0;
}