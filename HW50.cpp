/*�ۼ��� : �輺�� HW50 ���ڰ˻� ���α׷�(���� �˻�) */
#include <stdio.h>
#include<string.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int input(char* str, char* c);
int strcheck(char* str, char c);
#define MYFLUSH while(getchar() != '\n');
int main(void)
{
	//TODO
	char str[100] = {};
	char c;
	int jud, loc;
	while (1) {
		jud = input(str, &c);
		if (jud == 0) break;
		else {
			loc = strcheck(str, c);
			if (loc == -1) printf("\"%s\"���ڿ� �ȿ� \'%c\'���ڴ� �������� �ʽ��ϴ�.\n\n", str, c);
			else printf("\"%s\"���ڿ� �ȿ� \'%c\'���ڴ� %d�� ��ġ�� �����մϴ�.\n\n", str, c, loc);
		}
	}
	return 0;
}

int input(char* str, char *c) {
	printf("# ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", str);
	if (strcmp(str, "end") == 0) return 0;
	else {
		MYFLUSH
		printf("# ���ڸ� �Է��Ͻÿ� : ");
		scanf(" %c", c);
		MYFLUSH
		return 1;
	}
}

int strcheck(char* str, char c) {
	int i, len, res = -1;
	len = strlen(str);
	for(i = 0; i < len; i++) {
		if (c == str[i]) {
			res = i;
			break;
		}
	}
	return res;
}
