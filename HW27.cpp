/*�ۼ��� : �輺�� HW27 �ް� ���� ���α׷� �ۼ��ϱ� */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int input(void);
int main(void)
{
	//TODO
	int egg = 0, wei;
	while (egg < 10) {
		wei = input();
		if (wei > 500) printf("* Ÿ���� ������ �峭���� ���ÿ�~ ^^\n");
		else if (wei < 150) printf("* ���߸��� ������ �峭���� ���ÿ�~ ^^\n");
		else {
			egg++;
			printf("* ���� �ް��� �� : %d\n", egg);
		}		
	}
	printf("\n*** �ް� ������ �������ϴ�.\n");
	return 0;
}


int input(void) {
	int wei;
	while (1) {
		printf("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
		scanf("%d", &wei);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else break;
	}
	return wei;
}