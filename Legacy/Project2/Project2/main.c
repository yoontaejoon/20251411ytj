#include <stdio.h>
#include <conio.h>
#include <windows.h>

// Ŀ�� �̵� �Լ�
void gotoxy(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    char c;
    int isLoop = 1;

    gotoxy(2, 2);
    printf("input>");

    while (isLoop) {
        c = _getch();

        if (c >= '0' && c <= '9') {
            gotoxy(9, 2);
            printf("\033[92m%c\033[0m", c);  // ���� �ʷϻ� ���� ���
            isLoop = 0;
        }
        else {
            gotoxy(2, 3);
            printf("\033[31m\a����: ���ڸ� �Է��ϼ���.\033[0m     ");  // ������ ��� + �����
        }
    }

    return 0;
}
