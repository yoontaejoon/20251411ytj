#include <stdio.h>

int PassOrFail(int score) {
    if (score >= 50) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int score = 72;
    int result = PassOrFail(score);

    if (result == 1) {
        printf("����� �����ϴ�!\n");
    }
    else {
        printf("����� �ֽ��ϴ�.\n");
    }

    return 0;
}
