/*작성자 : 김성주 HW29 고집수 */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int inputUInt(const char* msg);
int transNumber(int num);
int stub;
int main(void)
{
	//TODO
	int P1, P2, N;
	int num, res, cnt = 0;
	P1 = inputUInt("시작 값(P1) : ");
	P2 = inputUInt("끝 값(P2) : ");
	N = inputUInt("고집수(N) : ");
	printf("고집수가 %d인 숫자 출력\n", N);
	for (num = P1; num <= P2; num++) {
		stub = 0;
		res = transNumber(num);
		if (N == stub) {
			printf("%d\n", num);
			cnt++;
		}
	}
	printf("총 개수 : %d개\n", cnt);

	return 0;
}

int inputUInt(const char* msg) {
	int num;
	while (1)
	{
		printf("%s", msg);
		scanf("%d", &num);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else if (num <= 0) {
			;
		}
		else break;
	}
	return num;
}

int transNumber(int num) {
	int th10, th, hun, ten, one;
	int num2;
	int res;
	num2 = num;
	stub++;
	if (num / 10000 == 0) th10 = 0;
	else {
		th10 = num / 10000;
		num -= th10 * 10000;
	}
	if (num / 1000 == 0) th = 0;
	else {
		th = num / 1000;
		num -= 1000 * th;
	}
	if (num / 100 == 0) hun = 0;
	else {
		hun = num / 100;
		num -= 100 * hun;
	}
	if (num / 10 == 0) ten = 0;
	else {
		ten = num / 10;
		num -= 10 * ten;
	}
	one = num;
	if (num2 < 100) res = ten * one; //1011 같은 경우 각 자리를 곱할 경우 0이 되기에 유효숫자에 0이 있는 경우를 골라내기 위한 if문 3형식
	else if (num2 < 1000) res = hun * ten * one;
	else if (num2 < 10000) res = th * hun * ten * one;
	else res = th10 * th * hun * ten * one;
	if (res / 10 == 0) return res;
	else return transNumber(res);

}