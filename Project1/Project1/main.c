#include <stdio.h>
#include <conio.h>    
#include <windows.h> 
#include <string.h>
#include <stdlib.h>

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawInputUI() {
    gotoxy(10, 2);
    printf("�ѹ� ���� ������ ����");

    gotoxy(10, 4);
    printf("[ ] [ ] [ ] [ ]");

    gotoxy(11, 4);
}

int main() {
    char slots[5] = { ' ', ' ', ' ', ' ', '\0' }; 
    int filled = 0;
    char ch;

    system("cls");
    drawInputUI();

    while (filled < 4) {
        ch = _getch();

        if (ch >= '0' && ch <= '9') {
            slots[filled] = ch;

            gotoxy(11 + filled * 4, 4);
            printf("%c", ch);

            filled++;
            if (filled < 4) {
                gotoxy(11 + filled * 4, 4);
            }
        }
        else if (ch == '\b' && filled > 0) {
            filled--;
            slots[filled] = ' ';
            gotoxy(11 + filled * 4, 4);
            printf(" ");
            gotoxy(11 + filled * 4, 4);
        }
    }

    gotoxy(0, 6);
    if (strcmp(slots, "8540") == 0) {
        printf("�� ������ �ƴ±���?\n");
    }
    else {
        int value = atoi(slots);
        if (value % 2 == 0) {
            printf("�� �� ¯��\n");
        }
        else {
            printf("�� ���� �� ���礻��\n");
        }
    }
    printf("\n���� ����");
    getchar();
    return 0;
}
