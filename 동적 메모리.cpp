#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int*** myalloc(int n, int row, int col);
void input(int*** p, int n, int row, int col);
void print(int*** p, int n, int row, int col);
int main(void)
{
	//TODO
	int*** p;
	int row, col, n;
	scanf("%d%d%d", &n, &row, &col);
	p = myalloc(n, row, col);
	input(p, n, row, col);
	print(p, n, row, col);
	return 0;
}

int*** myalloc(int n, int row, int col) {
	int i, j;
	int*** p; //�̷��� ��� �޸𸮸� ������ �ʴ´ٸ� 1���� �迭�� ������ ����ؾ߸� �ϴϱ�
	p = (int ***)malloc(sizeof(int) * n); //�� ���� �����ּҸ� ������ �迭�� �ּ�
	for (i = 0; i < n; i++) { 
		p[i] = (int**)malloc(sizeof(int) * row); // �� �濡 ���� ���� �ּҸ� ���� //���� ������ŭ �޸� �Ҵ�
		for (j = 0; j < row; j++) { //���� �����ּ� ����
			p[i][j] = (int*)malloc(sizeof(int) * col); //�� ������ŭ�� ���� ��� �� ���� �ּҸ� ����
		}
	}
	return p;
}

void input(int*** p, int n, int row, int col) {
	int i, j, k;
	for (i = 0; i < n; i++) {
		printf("\n%d�� �Է�\n", i);
		for (j = 0; j < row; j++) {
			printf("\n%d�� �Է�\n", j);
			for (k = 0; k < col; k++) {
				printf("\n%d��° ���� �Է� : ", k);
				scanf("%d", (*(*(p + i) + j) + k));
			}
		}
	}
}

void print(int*** p, int n, int row, int col) {
	int i, j, k;
	for (i = 0; i < n; i++) {
		printf("\n%d�� ���\n", i);
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				printf("%3d", p[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}