/*�ۼ��� : �輺�� HW29 ������ */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int inputUInt(const char* msg);
int transNumber(int num);
int stub;
int main(void)
{
	//TODO
	int P1, P2, N;
	int num, res, cnt = 0;
	P1 = inputUInt("���� ��(P1) : ");
	P2 = inputUInt("�� ��(P2) : ");
	N = inputUInt("������(N) : ");
	printf("�������� %d�� ���� ���\n", N);
	for (num = P1; num <= P2; num++) {
		stub = 0;
		res = transNumber(num);
		if (N == stub) {
			printf("%d\n", num);
			cnt++;
		}
	}
	printf("�� ���� : %d��\n", cnt);

	return 0;
}

int inputUInt(const char* msg) {
	int num;
	while (1)
	{
		printf("%s", msg);
		scanf("%d", &num);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else if (num <= 0) {
			;
		}
		else break;
	}
	return num;
}

int transNumber(int num) {
	int th10, th, hun, ten, one;
	int num2;
	int res;
	num2 = num;
	stub++;
	if (num / 10000 == 0) th10 = 0;
	else {
		th10 = num / 10000;
		num -= th10 * 10000;
	}
	if (num / 1000 == 0) th = 0;
	else {
		th = num / 1000;
		num -= 1000 * th;
	}
	if (num / 100 == 0) hun = 0;
	else {
		hun = num / 100;
		num -= 100 * hun;
	}
	if (num / 10 == 0) ten = 0;
	else {
		ten = num / 10;
		num -= 10 * ten;
	}
	one = num;
	if (num2 < 100) res = ten * one; //1011 ���� ��� �� �ڸ��� ���� ��� 0�� �Ǳ⿡ ��ȿ���ڿ� 0�� �ִ� ��츦 ��󳻱� ���� if�� 3����
	else if (num2 < 1000) res = hun * ten * one;
	else if (num2 < 10000) res = th * hun * ten * one;
	else res = th10 * th * hun * ten * one;
	if (res / 10 == 0) return res;
	else return transNumber(res);

}