/*�ۼ��� : �輺�� HW30 2 ���� ��ȯ ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int inputInt(const char* msg);
void bin(int);
int main(void)
{
	//TODO
	int num;
	num = inputInt("* 10���� ������ �Է��Ͻÿ� : ");
	bin(num);
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
		else break;
	}
	return num;
}

void bin(int num) {
	int i;
	unsigned jud = 0x80000000;
	printf("%d(10) = ", num);
	for (i = 0; i < 32; i++) {
		if ((num & jud) == 0) printf("%d", 0);
		else printf("%d", 1);
		jud = jud >> 1;
	}
	printf("(2)\n");
}