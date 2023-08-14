/*작성자 : 김성주 HW25 숫자 맞추기 게임 */
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int input(void);
void output(int tnum, int num, int* pmin, int* pmax);

int main(void)
{
	//TODO
	srand((unsigned int)time(NULL));
	int tnum, num, min = 0, max = 100, i=1;
	tnum = rand() % 100 + 1;
	num = input();
	while (tnum != num) {
		output(tnum, num, &min, &max);
		num = input();
		i++;
	}
	printf("우와~ 맞았당~~~ 추카추카~~ %d 번째 만에 맞추셨습니다.", i);
	return 0;
}

int input(void) {
	int num;
	while (1) {
		printf("# 숫자를 입력하시오 : ");
		scanf("%d", &num);
		if (getchar() != '\n') {
			while (getchar() != '\n');
		}
		else if (1 <= num && num <= 100) break;
	}
	return num;
}

void output(int tnum, int num, int *pmin, int *pmax) {
	if (num > tnum) {
		*pmax = num;
	}
	else *pmin = num;
	printf("%d 보다는 크고 %d 보다는 작습니다.\n", *pmin, *pmax);
	return;
}