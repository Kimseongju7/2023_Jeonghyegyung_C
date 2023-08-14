/*작성자 : 김성주 HW27 달걀 포장 프로그램 작성하기 */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int input(void);
int main(void)
{
	//TODO
	int egg = 0, wei;
	while (egg < 10) {
		wei = input();
		if (wei > 500) printf("* 타조알 가지고 장난하지 마시오~ ^^\n");
		else if (wei < 150) printf("* 메추리알 가지고 장난하지 마시오~ ^^\n");
		else {
			egg++;
			printf("* 현재 달걀의 수 : %d\n", egg);
		}		
	}
	printf("\n*** 달걀 포장이 끝났습니다.\n");
	return 0;
}


int input(void) {
	int wei;
	while (1) {
		printf("# 계란의 무게를 입력하세요(단위 : g) : ");
		scanf("%d", &wei);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else break;
	}
	return wei;
}