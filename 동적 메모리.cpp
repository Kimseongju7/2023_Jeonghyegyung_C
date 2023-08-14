#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
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
	int*** p; //이렇게 기둥 메모리를 세우지 않는다면 1차원 배열을 여러개 사용해야만 하니까
	p = (int ***)malloc(sizeof(int) * n); //각 면의 시작주소를 저장할 배열의 주소
	for (i = 0; i < n; i++) { 
		p[i] = (int**)malloc(sizeof(int) * row); // 각 방에 면의 시작 주소를 저장 //행의 개수만큼 메모리 할당
		for (j = 0; j < row; j++) { //행의 시작주소 저장
			p[i][j] = (int*)malloc(sizeof(int) * col); //열 개수만큼의 방을 잡아 그 시작 주소를 저장
		}
	}
	return p;
}

void input(int*** p, int n, int row, int col) {
	int i, j, k;
	for (i = 0; i < n; i++) {
		printf("\n%d면 입력\n", i);
		for (j = 0; j < row; j++) {
			printf("\n%d행 입력\n", j);
			for (k = 0; k < col; k++) {
				printf("\n%d번째 문자 입력 : ", k);
				scanf("%d", (*(*(p + i) + j) + k));
			}
		}
	}
}

void print(int*** p, int n, int row, int col) {
	int i, j, k;
	for (i = 0; i < n; i++) {
		printf("\n%d면 출력\n", i);
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				printf("%3d", p[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}