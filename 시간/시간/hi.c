#include <stdio.h>
#include <time.h>
#include <windows.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int i = 0;
    while (i <= 10)
    {
        printf("���� %d\n", i);
        i = i + 1;

        Sleep(1);
    }

    end = clock();

    cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("�ɸ� �ð�: %.2f��\n", cpu_time_used);

    return 0;
}


