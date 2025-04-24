#include <stdio.h>
#include <conio.h>    // _getch()
#include <windows.h>  // gotoxy, SetConsoleCursorPosition
#include <string.h>   // strcmp
#include <stdlib.h>   // atoi

// gotoxy ���� (Windows)
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// ȭ�鿡 �Է� UI�� �׸��� �Լ�
void drawInputUI() {
    // �ȳ� ����
    gotoxy(10, 2);
    printf("�ѹ� ���� ������ ����");

    // �Է� ���� �� ĭ
    gotoxy(10, 4);
    printf("[ ] [ ] [ ] [ ]");

    // Ŀ�� ��ġ�� ù ĭ ������
    gotoxy(11, 4);
}

int main() {
    char slots[5] = { ' ', ' ', ' ', ' ', '\0' };  // �������� ���ڿ� �����
    int filled = 0;
    char ch;

    system("cls");
    drawInputUI();

    // �� ���ھ� �Է� �ޱ�
    while (filled < 4) {
        ch = _getch();

        // ���� Ű�� ��� (0~9)
        if (ch >= '0' && ch <= '9') {
            slots[filled] = ch;

            // �ش� ĭ�� ���
            gotoxy(11 + filled * 4, 4);
            printf("%c", ch);

            filled++;
            // ���� ĭ���� Ŀ�� �̵�
            if (filled < 4) {
                gotoxy(11 + filled * 4, 4);
            }
        }
        // �齺���̽� ó�� (�� ĭ �����)
        else if (ch == '\b' && filled > 0) {
            filled--;
            slots[filled] = ' ';
            gotoxy(11 + filled * 4, 4);
            printf(" ");
            gotoxy(11 + filled * 4, 4);
        }
        // �� �� Ű�� ����
    }

    // 4�ڸ� �Է��� �Ϸ�� �� ��� ó��
    // ���Կ� ��� ���ڵ��� ���ڿ��� ���������, strcmp�� �� ����
    gotoxy(0, 6);
    if (strcmp(slots, "8540") == 0) {
        printf("�� ������ �ƴ±���?\n");
    }
    else {
        // ���ڿ��� ������ �ٲ㼭 ¦/Ȧ �˻�
        int value = atoi(slots);
        if (value % 2 == 0) {
            printf("�� �� ¯��\n");
        }
        else {
            printf("�� ���� �� ���礻��\n");
        }
    }

    return 0;
}
