/*�ۼ��� : �輺�� HW51 ���� �� ��Ʈ ���α׷� (1 ���� �迭���)*/
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
void sort(int* num, int n);
void printfAry(const char* msg, int* num, int n);
int main(void)
{
	//TODO
	int num[] = { 8, 2, 4, 11, 1, 6 };
	int SIZE = sizeof(num) / sizeof(num[0]);
	printfAry("# ��Ʈ �� ������ : ", num, SIZE);
	sort(num, SIZE);
	printfAry("# ��Ʈ �� ������ : ", num, SIZE);
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
		for (j = i + 1; j < n; j++) { //i�� ������ ���� j���� �����Կ� ���� �ݺ� Ƚ���� �ڵ����� �ϳ��� �۾���
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