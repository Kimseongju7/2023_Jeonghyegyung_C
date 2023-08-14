/*작성자 : 김성주 HW55 배열의 부분합 구하기 (이차원배열 이용) */
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
void randnum(int(*num)[5], int row, int col);
void printfnum(int(*num)[5], int row, int col);
void calcsum1(int(*num)[5], int row, int* sum);
void calcsum2(int(*num)[5], int row, int col, int* sum);
void calcsum3(int(*num)[5], int row, int* sum);
void output(int* sum);
int main(void)
{
	//TODO
	int num[5][5];
	int row, col;
	int sum[4] = {};
	row = sizeof(num) / sizeof(num[0]);
	col = sizeof(num[0])/sizeof(num[0][0]);
	srand(time(NULL));
	randnum(num, row, col);
	printfnum(num, row, col);
	calcsum1(num, row, sum);
	calcsum2(num, row, col, sum);
	calcsum3(num, row, sum);
	output(sum);

	return 0;
}

void randnum(int(*num)[5], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			num[i][j] = rand() % 20 + 1;
		}
	}
	return;
}

void printfnum(int(*num)[5], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		printf("%d번 행 :", i);
		for (j = 0; j < col; j++) {
			printf("%3d", num[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void calcsum1(int(*num)[5], int row, int* sum){
	int i;
	for (i = 0; i < row; i++) {
		sum[1] += num[i][i];
	}
	return;
}

void calcsum2(int(*num)[5], int row, int col, int* sum) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = i + 1; j < col; j++) {
			sum[2] += num[i][j];
		}
	}
	return;
}

void calcsum3(int(*num)[5], int row, int* sum) {
	int i, j;
	for (i = 1; i < row; i++) {
		for (j = 0; j < i; j++) {
			sum[3] += num[i][j];
		}
	}
	return;
}

void output(int* sum) {
	int i;
	for (i = 1; i <= 3; i++) {
		printf("sum%d = %3d\n", i, sum[i]);
	}
	return;
}