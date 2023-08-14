/*�ۼ��� : �輺�� HW53 ���ڿ� ���� ������ �� ���ϱ� */
#include <stdio.h>
#include<string.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
void input(const char* msg, char* str);
int calc(char* str);
int calcnum(int* num);
int ten(int n);
void output(char* str, int res);
int myarylen(int* ary);
int mystrlen(char* str);
#define MYFLUSH while(getchar() != '\n');
int main(void)
{
	//TODO
	char str[100] = {};
	int res;
	while (1) {
		input("# ������ �Է��Ͻÿ� : ", str);
		if (strcmp(str, "end")) {
			res = calc(str);
			output(str, res);
		}
		else break;
	}
	return 0;
}

void input(const char* msg, char* str) {
	printf(msg);
	scanf("%s", str);
	MYFLUSH
	return;
}

int calc(char* str) {
	int len, i, j, cnt = 0, sum = 0;
	int num[100] = {};
	len = mystrlen(str);
	for (i = 0, j = 0; i < len; i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			num[j++] = str[i] - '0';
			if ('0' > str[i + 1] || str[i + 1] > '9') {
				num[j] = '\0';
				sum += calcnum(num);
				j = 0;
			}
		}
	}
	return sum;
}

int calcnum(int* num) {
	int len, i = 0, sum = 0;
	len = myarylen(num);
	while (num[i] != '\0') {
		num[i] *= ten(len - i - 1);
		i++;
	}
	for (i = 0; i < len; i++) {
		sum += num[i];
	}
	return sum;
}

int ten(int n) {
	int i, ten = 1;
	for (i = 0; i < n; i++) {
		ten *= 10;
	}
	return ten;
}

int mystrlen(char* str) {
	int i, cnt = 0;
	for (i = 0; str[i] != '\0'; i++) { //*(str + i) : str�迭�� ���� �ּ� ���� i�� ���� �ּҰ� ����Ű�� ��? �� �ּҿ� �ִ� ��(char�ϱ� 1����Ʈ�� �б�)
		cnt++;
	}
	return cnt;
}

int myarylen(int* ary) {
	int i, cnt = 0;
	for (i = 0; ary[i] != '\0'; i++) {
		cnt++;
	}
	return cnt;
}

void output(char* str, int res) {
	printf("  \"%s\" ���� �� ���ڴ� [%d]�Դϴ�.\n\n", str, res);
	return;
}