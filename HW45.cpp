/*�ۼ��� : �輺�� HW */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
void inputInt(const char* msg, int* num);
int inputCharEO(int st, int end);
void even(int st, int end);
void odd(int, int);
int main(void)
{
	//TODO
	int st = 0, end = 0;
	int jud;
	inputInt("# ���۰��� �Է��Ͻÿ� : ", &st);
	while (end <= st) inputInt("# �� ���� �Է��Ͻÿ� : ", &end);
	jud = inputCharEO(st, end);
	if (jud == 0) even(st, end);
	else odd(st, end);
	
	return 0;
}

void inputInt(const char* msg, int* num) { //���ڿ� ����� �� �� ���ڿ��� ���� �ּ��̰� �����
	while (1)
	{
		printf("%s", msg);
		scanf("%d", num);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else if (*num < 0);
		else break;
	}
	return;
}

int inputCharEO(int st, int end) {
	char c;
	while (1)
	{
		printf("* %d~%d������ ¦���� ���� ���ұ��? Ȧ���� ���� ���ұ��?(¦��:e/Ȧ��:o) : ", st, end);
		scanf(" %c", &c);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else if (c == 'e' || c == 'o') break;
		else ;
	}
	if (c == 'e') return 0; //¦���� 10����
	else return 1; //Ȧ���� 1 ����

}

void even(int st, int end) {
	int i, sum = 0;
	printf("  %d~%d ������ ¦��(", st, end);
	for (i = st; i <= end; i++) {
		if (i % 2 == 0) {
			printf("%d ", i);
			sum += i;
		}
	}
	printf("\b)�� ���� %d �Դϴ�.\n", sum);
}

void odd(int st, int end) {
	int i, sum = 0;
	printf("  %d~%d ������ Ȧ��(", st, end);
	for (i = st; i <= end; i++) {
		if (i % 2 == 1) {
			printf("%d ", i);
			sum += i;
		}
	}
	printf("\b)�� ���� %d �Դϴ�.\n", sum);
}