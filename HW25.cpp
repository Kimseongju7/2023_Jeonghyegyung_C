/*�ۼ��� : �輺�� HW25 ���� ���߱� ���� */
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int input(void);
void output(int tnum, int num, int* pmin, int* pmax);

int main(void)
{
	//TODO
	srand((unsigned int)time(NULL));
	int tnum, num, min = 0, max = 100, i=1;
	tnum = rand() % 100 + 1;
	num = input();
	while (tnum != num) {
		output(tnum, num, &min, &max);
		num = input();
		i++;
	}
	printf("���~ �¾Ҵ�~~~ ��ī��ī~~ %d ��° ���� ���߼̽��ϴ�.", i);
	return 0;
}

int input(void) {
	int num;
	while (1) {
		printf("# ���ڸ� �Է��Ͻÿ� : ");
		scanf("%d", &num);
		if (getchar() != '\n') {
			while (getchar() != '\n');
		}
		else if (1 <= num && num <= 100) break;
	}
	return num;
}

void output(int tnum, int num, int *pmin, int *pmax) {
	if (num > tnum) {
		*pmax = num;
	}
	else *pmin = num;
	printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", *pmin, *pmax);
	return;
}