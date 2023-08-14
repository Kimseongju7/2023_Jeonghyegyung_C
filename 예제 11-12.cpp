#include<stdio.h>
#include<malloc.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int** myAlloc(int, int);
void dataInput(int**, int, int);
void dataOutput(int**, int, int);
void myDelete(int**, int); //곁가지 먼저 해제
int main()
{
	int** ip;
	int col, row;
	printf("row 수 입력 : ");
	scanf("%d", &row);
	printf("column 수 입력 : ");
	scanf("%d", &col);
	ip = myAlloc(row, col);
	if (ip == NULL) printf("할당 실패!\n");
	else {
		dataInput(ip, row, col);
		dataOutput(ip, row, col);
		myDelete(ip, row);
	}
	return 0;
}

int** myAlloc(int row, int col) {
	int** ip;
	int i;
	ip = (int**)malloc(sizeof(int*) * row); //int 아닌 int *형		//곁가지 메모리의 시작 주소를 저장할 기둥 메모리 먼저 할당
	if (ip == NULL) return NULL; //기둥 메모리 할당 실패했다면
	for (i = 0; i < row; i++) { //곁가지 메모리는 row개 필요. 곁가지 메모리 크기가 col개
		ip[i] = (int*)malloc(sizeof(int) * col);		//기둥 메모리에 곁가지 메모리 할당하고 시작 주소 저장
		if (ip[i] == NULL) { //곁까지 메모리 할당 실패 했다면
			//그냥 리턴하면 이전에 할당된 곁가지 메모리는 살아있음
			myDelete(ip, i);//성공적으로 할당한 행의 개수
			return NULL;
		}
	}

	return ip;
}

void dataInput(int** ip, int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		printf("\n%d행 입력\n", i + 1);
		for (j = 0; j < col; j++) {
			printf("정수 입력 : ");
			scanf("%d", (*(ip + i) + j)); //scanf의 마지막 형식문자 뒤에는 어떠한 것도 입력하면 안 됨. 오동작 일어남
		}
	}
	printf("\n");
	return;
}

void dataOutput(int** ip, int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%5d", ip[i][j]);
		}
		printf("\n");
	}
	return;
}

void myDelete(int** ip, int row) {
	int i;
	if (ip != NULL) {
		for (i = 0; i < row; i++) { //곁가지 매모리는 row개 있음 각 행마다 곁가지 메모리의 주소가 저장됨
			//if (ip[i] != NULL) {
				free(ip[i]); //곁가지 메모리 해제
			//} ip부터가 안 잡히면 그 안에 있는 애들도 안 잡힘
		}
		free(ip); //기둥 메모리 해제
	} //끝나는 메시지가 나오면 중간에 죽지 않고 제대로 실행된 것
}