/*�ۼ��� : �輺�� HW43 ������ ����ϱ� (for�� ���) */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int main(void)
{
	//TODO
	register int j;
	int i, k, l;
	printf("<2�� for���� �̿��� ���>\n");
	for (i = 1; i <= 9; i++) {
		for (j = 2; j <= 5; j++) {
			printf("%d*%d=%2d\t\t", j, i, j * i);
		}
		printf("\n");
		if (i == 9) printf("\n");
	}
	for (i = 1; i <= 9; i++) {
		for (j = 6; j <= 9; j++) {
			printf("%d*%d=%2d\t\t", j, i, j * i);
		}
		printf("\n");
	}
	for (j = 0; j < 77; j++) printf("-");
	printf("\n\n<3�� for���� �̿��� ���>\n");
	for (i = 0, k = 2; i < 2; i++) {
		l = k + 3;
		for (j = 1; j <= 9; j++) {
			for (k = l - 3; k <= l; k++) {
				printf("%d*%d=%2d\t\t", k, j, k * j);
			}
			printf("\n");
		}
		printf("\n");
		k = 6;
	}
	return 0;
}