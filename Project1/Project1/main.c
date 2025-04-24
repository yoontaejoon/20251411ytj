#include <stdio.h>
#include <conio.h>    // _getch()
#include <windows.h>  // gotoxy, SetConsoleCursorPosition
#include <string.h>   // strcmp
#include <stdlib.h>   // atoi

// gotoxy 구현 (Windows)
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 화면에 입력 UI를 그리는 함수
void drawInputUI() {
    // 안내 문구
    gotoxy(10, 2);
    printf("한번 맞춰 보시지 케케");

    // 입력 슬롯 네 칸
    gotoxy(10, 4);
    printf("[ ] [ ] [ ] [ ]");

    // 커서 위치는 첫 칸 안으로
    gotoxy(11, 4);
}

int main() {
    char slots[5] = { ' ', ' ', ' ', ' ', '\0' };  // 마지막은 문자열 종료용
    int filled = 0;
    char ch;

    system("cls");
    drawInputUI();

    // 한 글자씩 입력 받기
    while (filled < 4) {
        ch = _getch();

        // 숫자 키만 허용 (0~9)
        if (ch >= '0' && ch <= '9') {
            slots[filled] = ch;

            // 해당 칸에 출력
            gotoxy(11 + filled * 4, 4);
            printf("%c", ch);

            filled++;
            // 다음 칸으로 커서 이동
            if (filled < 4) {
                gotoxy(11 + filled * 4, 4);
            }
        }
        // 백스페이스 처리 (한 칸 지우기)
        else if (ch == '\b' && filled > 0) {
            filled--;
            slots[filled] = ' ';
            gotoxy(11 + filled * 4, 4);
            printf(" ");
            gotoxy(11 + filled * 4, 4);
        }
        // 그 외 키는 무시
    }

    // 4자리 입력이 완료된 뒤 결과 처리
    // 슬롯에 담긴 문자들을 문자열로 만들었으니, strcmp로 비교 가능
    gotoxy(0, 6);
    if (strcmp(slots, "8540") == 0) {
        printf("너 정답을 아는구나?\n");
    }
    else {
        // 문자열을 정수로 바꿔서 짝/홀 검사
        int value = atoi(slots);
        if (value % 2 == 0) {
            printf("응 너 짱ㅋ\n");
        }
        else {
            printf("넌 절대 못 맞춰ㅋㅋ\n");
        }
    }

    return 0;
}
