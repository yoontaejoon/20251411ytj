#include <stdio.h>

int main() {
    int year = 2025;
    char grade = 'A';
    char name[] = "���ִ�";

    // %%d: ���� %d�� ����ϰ� ���� �� ���
    printf("����: %c ���� (��� ����: %%d ��� ����)\n", grade);

    // ���� ���� ���
    printf("���� ����: %d��\n", year);

    // char �迭 ���
    printf("�б� �̸�: %s\n", name);

    // ���� ���� ���
    printf("ù ���ڸ� ����ϸ�? %c\n", name[0]);

    return 0;
}