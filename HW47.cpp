/*�ۼ��� : �輺�� HW */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
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

void input(double* pary, int size) { //���ڿ� ����� �� �� ���ڿ��� ���� �ּ��̰� �����
	int i;
	for (i = 0; i < size; i++) {
		while (1) {
			printf("%d �� �� �� : ", i);
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
	printf("\n���� ū �� : %.2lf\n", max);
	printf("���� ���� �� : %.2lf\n", min);
}
