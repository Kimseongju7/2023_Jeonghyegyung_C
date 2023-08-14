/*작성자 : 김성주 HW26 가위 바위 보 게임을 만들어보자 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int input(void);
void output(int hum, int com, int jud);
char shum[4][30] = { "0", "  당신은 바위 선택,", "  당신은 가위 선택,", "  당신은 보 선택," };
char scom[4][30] = { "0", "컴퓨터는 바위 선택", "컴퓨터는 가위 선택", "컴퓨터는 보 선택" };
int main(void)
{
	//TODO
	srand((unsigned int)time(NULL));
	int com, hum, win=0, draw=0;
	com = rand() % 3 + 1;
	hum = input();
	int minus = com - hum;
	while (!(minus == 2 || minus == -1)) {
		if (minus == 0) {
			draw++;
			output(hum, com, 0);
		}
		else {
			win++;
			output(hum, com,  1);
		}
		com = rand() % 3 + 1;
		hum = input();
		minus = com - hum;
	}
	output(hum, com, -1);
	printf("게임결과 : %d 승 %d 무\n", win, draw);
	return 0;
}

int input(void) {
	int hum;
	while (1) {
		printf("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
		scanf("%d", &hum);
		if (1 <= hum && hum <= 3) break;
	}
	return hum;
}

void output(int hum, int com, int jud) {
	if (jud == 0) printf("%s %s : 비겼습니다.\n", shum[hum], scom[com]);
	else if (jud == 1) printf("%s %s : 이겼습니다.\n", shum[hum], scom[com]);
	else printf("%s %s : 당신이 졌습니다.\n", shum[hum], scom[com]);
	return;
}