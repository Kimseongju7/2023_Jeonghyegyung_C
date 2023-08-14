/*작성자 : 김성주 HW */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
void input(double* pary, int size);
double serchmax(double* pary, int size);
double serchmin(double* pary, int size);
void output(double max, double min);
int main(void)
{
	//TODO
	double ary[5];
	double max, min;
	int size = sizeof(ary) / sizeof(ary[0]);
	input(ary, size);
	max = serchmax(ary, size);
	min = serchmin(ary, size);
	output(max, min);
	return 0;
}

void input(double* pary, int size) { //문자열 상수는 곧 그 문자열의 시작 주소이고 상수임
	int i;
	for (i = 0; i < size; i++) {
		while (1) {
			printf("%d 번 번 값 : ", i);
			scanf("%lf", &pary[i]);
			if (getchar() != '\n')
				while (getchar() != '\n');
			else break;
		}
	}
	return;
}

double serchmax(double* pary, int size) {
	int i;
	double max = pary[0];
	for (i = 1; i < size; i++) {
		if (pary[i] > max) max = pary[i];
	}
	return max;
}

double serchmin(double* pary, int size) {
	int i;
	double min = pary[0];
	for (i = 1; i < size; i++) {
		if (pary[i] < min) min = pary[i];
	}
	return min;
}

void output(double max, double min) {
	printf("\n가장 큰 값 : %.2lf\n", max);
	printf("가장 작은 값 : %.2lf\n", min);
}
