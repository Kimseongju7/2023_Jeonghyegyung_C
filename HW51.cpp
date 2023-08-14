/*작성자 : 김성주 HW51 정수 값 소트 프로그램 (1 차원 배열사용)*/
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
void sort(int* num, int n);
void printfAry(const char* msg, int* num, int n);
int main(void)
{
	//TODO
	int num[] = { 8, 2, 4, 11, 1, 6 };
	int SIZE = sizeof(num) / sizeof(num[0]);
	printfAry("# 소트 전 데이터 : ", num, SIZE);
	sort(num, SIZE);
	printfAry("# 소트 후 데이터 : ", num, SIZE);
	return 0;
}

void printfAry(const char* msg, int* num, int n) {
	int i;
	printf(msg);
	for (i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
	return;
}

void sort(int* num, int n) {
	int i, j;
	int temp;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) { //i값 증가에 의해 j값이 증가함에 따라 반복 횟수는 자동으로 하나씩 작아짐
			if (num[i] > num[j]) {
				//swap
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	return;
}