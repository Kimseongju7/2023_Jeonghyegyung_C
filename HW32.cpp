/*작성자 : 김성주 HW32 누승 함수 만들기 */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int inputUInt(const char* msg);
double inputDouble(const char* msg);
int ipow(int num, int n);
double fpow(double fnum, int n);
int main(void)
{
	//TODO
	int num, n, intpow;
	double fnum, flpow;
	num = inputUInt("* 양의 정수 밑을 입력 하시오 : ");
	n = inputUInt("* 양의 승을 입력 하시오 : ");
	intpow = ipow(num, n);
	printf("%d의 %d승은 %d입니다.\n\n", num, n, intpow);
	fnum = inputDouble("* 양의 실수 밑을 입력 하시오 : ");
	n = inputUInt("* 양의 승을 입력 하시오 : ");
	flpow = fpow(fnum, n);
	printf("%.2lf의 %d승은 %.3lf입니다.\n", fnum, n, flpow);
	return 0;
}

int inputUInt(const char* msg) { //문자열 상수는 곧 그 문자열의 시작 주소이고 상수임
	int num;
	while (1)
	{
		printf("%s", msg);
		scanf("%d", &num);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else if (num < 0);
		else break;
	}
	return num;
}

double inputDouble(const char* msg) { //문자열 상수는 곧 그 문자열의 시작 주소이고 상수임
	double num;
	while (1) {
		printf("%s", msg);
		scanf("%lf", &num);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else if (num < 0);
		else break;
	}
	return num;
}

int ipow(int num, int n) {
	int mul = 1, i;
	if (num == 0) return 0;
	else {
		for (i = 0; i < n; i++) {
			mul *= num;
		}
		return mul;
	}
}

double fpow(double fnum, int n) {
	double mul = 1;
	int i;
	if (fnum == 0) return 0; //실수 0은 정수 0과 2진수 비트열이 같음
	else {
		for (i = 0; i < n; i++) {
			mul *= fnum;
		}
		return mul;
	}
}