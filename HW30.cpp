/*작성자 : 김성주 HW30 2 진수 변환 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int inputInt(const char* msg);
void bin(int);
int main(void)
{
	//TODO
	int num;
	num = inputInt("* 10진수 정수를 입력하시오 : ");
	bin(num);
	return 0;
}

int inputInt(const char* msg) { //문자열 상수는 곧 그 문자열의 시작 주소이고 상수임
	int num;
	while (1)
	{
		printf("%s", msg);
		scanf("%d", &num);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else break;
	}
	return num;
}

void bin(int num) {
	int i;
	unsigned jud = 0x80000000;
	printf("%d(10) = ", num);
	for (i = 0; i < 32; i++) {
		if ((num & jud) == 0) printf("%d", 0);
		else printf("%d", 1);
		jud = jud >> 1;
	}
	printf("(2)\n");
}