/*�ۼ��� : �輺�� HW54 3�� 4��¥�� 2���� int �迭�� ��, ���� ���� ���ϱ� */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void randNum(int(*num)[4], int row, int col);
void sumPrintf(int(*num)[4], int row, int col);
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int main(void)
{
	//TODO
	srand(time(NULL));
	int num[3][4];
	int rowSize = sizeof(num) / sizeof(num[0]);
	int colSize = sizeof(num[0]) / sizeof(num[0][0]);
	randNum(num, rowSize, colSize);
	sumPrintf(num, rowSize, colSize);
	return 0;
}

void randNum(int(*num)[4], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) {
			num[i][j] = rand() % 9 + 1;
		}
	}
	return;
}

void sumPrintf(int(*num)[4], int row, int col) {
	int i, j;
	int sumrow, sumcol;
	for (i = 0; i < row; i++) {
		sumrow = 0;
		printf("%d��\t:", i);
		for (j = 0; j < col; j++) {
			printf("%3d", num[i][j]);
			sumrow += num[i][j];
		}
		printf("\t%d ���� �� : %d\n", i, sumrow);
		printf("\n");
	}
	printf("���� ��\t:");
	for (i = 0; i < col; i++) {
		sumcol = 0;
		for (j = 0; j < row; j++) {
			sumcol += num[j][i];
		}
		printf("%3d", sumcol);
	}
	return;
}