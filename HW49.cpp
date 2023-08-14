/*작성자 : 김성주 HW */
#include <stdio.h>
void swap(int* ary, int size);
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int main(void)
{
	//TODO
	int ary[] = { 1, 2, 3, 4, 5 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int i;
	printf("처음 배열에 저장된 값 : ");
	for (i = 0; i < size; i++) {
		printf("%3d", ary[i]);
	}
	printf("\n");
	swap(ary, size);
	printf("바뀐 배열에 저장된 값 : ");
	for (i = 0; i < size; i++) {
		printf("%3d", ary[i]);
	}
	printf("\n");
	return 0;
}

void swap(int* ary, int size) {
	int i;
	int temp;
	for (i = 0; i < (size / 2); i++) {
		temp = ary[i];
		ary[i] = ary[size - i - 1];
		ary[size - i - 1] = temp;
	}
	return;
}