/*�ۼ��� : �輺�� HW32 ���� �Լ� ����� */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int inputUInt(const char* msg);
double inputDouble(const char* msg);
int ipow(int num, int n);
double fpow(double fnum, int n);
int main(void)
{
	//TODO
	int num, n, intpow;
	double fnum, flpow;
	num = inputUInt("* ���� ���� ���� �Է� �Ͻÿ� : ");
	n = inputUInt("* ���� ���� �Է� �Ͻÿ� : ");
	intpow = ipow(num, n);
	printf("%d�� %d���� %d�Դϴ�.\n\n", num, n, intpow);
	fnum = inputDouble("* ���� �Ǽ� ���� �Է� �Ͻÿ� : ");
	n = inputUInt("* ���� ���� �Է� �Ͻÿ� : ");
	flpow = fpow(fnum, n);
	printf("%.2lf�� %d���� %.3lf�Դϴ�.\n", fnum, n, flpow);
	return 0;
}

int inputUInt(const char* msg) { //���ڿ� ����� �� �� ���ڿ��� ���� �ּ��̰� �����
	int num;
	while (1)
	{
		printf("%s", msg);
		scanf("%d", &num);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else if (num < 0);
		else break;
	}
	return num;
}

double inputDouble(const char* msg) { //���ڿ� ����� �� �� ���ڿ��� ���� �ּ��̰� �����
	double num;
	while (1) {
		printf("%s", msg);
		scanf("%lf", &num);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else if (num < 0);
		else break;
	}
	return num;
}

int ipow(int num, int n) {
	int mul = 1, i;
	if (num == 0) return 0;
	else {
		for (i = 0; i < n; i++) {
			mul *= num;
		}
		return mul;
	}
}

double fpow(double fnum, int n) {
	double mul = 1;
	int i;
	if (fnum == 0) return 0; //�Ǽ� 0�� ���� 0�� 2���� ��Ʈ���� ����
	else {
		for (i = 0; i < n; i++) {
			mul *= fnum;
		}
		return mul;
	}
}