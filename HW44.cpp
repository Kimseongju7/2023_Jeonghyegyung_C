/*작성자 : 김성주 HW */
#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int inputInt(const char* msg);
int primeNumber(int num);
int main(void)
{
	//TODO
	int num, i, cnt = 0;
	num = inputInt("* 정수값 하나를 입력하시오 : ");
	printf("1~%d까지의 소수 값은 다음과 같습니다.\n", num);
	for (i = 2; i <= num; i++) {
		if (primeNumber(i) == 1) {
			printf("%d\t", i);
			cnt++;
			if (cnt % 5 == 0) printf("\n");
		}
	}
	printf("\n1~%d까지의 총 소수는 %d개 입니다.\n", num, cnt);
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
		else if (num < 1);
		else break;
	}
	return num;
}

int primeNumber(int num) {
	int i, sqr;
	sqr = (int)sqrt(num);
	for (i = 2; i <= sqr; i++) {
		if (num % i == 0) return 0;
	}
	return 1;
}