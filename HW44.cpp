/*�ۼ��� : �輺�� HW */
#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int inputInt(const char* msg);
int primeNumber(int num);
int main(void)
{
	//TODO
	int num, i, cnt = 0;
	num = inputInt("* ������ �ϳ��� �Է��Ͻÿ� : ");
	printf("1~%d������ �Ҽ� ���� ������ �����ϴ�.\n", num);
	for (i = 2; i <= num; i++) {
		if (primeNumber(i) == 1) {
			printf("%d\t", i);
			cnt++;
			if (cnt % 5 == 0) printf("\n");
		}
	}
	printf("\n1~%d������ �� �Ҽ��� %d�� �Դϴ�.\n", num, cnt);
	return 0;
}

int inputInt(const char* msg) { //���ڿ� ����� �� �� ���ڿ��� ���� �ּ��̰� �����
	int num;
	while (1)
	{
		printf("%s", msg);
		scanf("%d", &num);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else if (num < 1);
		else break;
	}
	return num;
}

int primeNumber(int num) {
	int i, sqr;
	sqr = (int)sqrt(num);
	for (i = 2; i <= sqr; i++) {
		if (num % i == 0) return 0;
	}
	return 1;
}