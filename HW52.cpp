/*�ۼ��� : �輺�� HW52 ȸ��(Palindrome) �˻� ���α׷� */
#include <stdio.h>
#include<string.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int mystrlen(char* str);
void input(const char* msg, char* pstr);
int PalindromeCheck(char* pstr);
void mytolower(char* pstr, int len);
int mystrlen(char* str);
void output(int jud);
int main(void)
{
	//TODO
	int jud;
	char str[100];
	while (1) {
		input("# �ܾ� �Է� : ", str);
		jud = strcmp(str, "end");
		if (jud == 0) break;
		printf("\"%s\" : ", str);
		jud = PalindromeCheck(str);
		output(jud);
	}
	return 0;
}
void input(const char* msg, char* pstr) {
	printf(msg);
	scanf("%s", pstr);
}

int PalindromeCheck(char* pstr) {
	int len, i;
	len = mystrlen(pstr);
	mytolower(pstr, len);
	for (i = 0; i < len / 2; i++) {
		if (pstr[i] != pstr[len - 1 - i]) return 0;
	}
	return 1;
}

void mytolower(char* pstr, int len) { //call by argument, pstr�� �ּҰ� �ƴ� �ȿ� ����ִ� ���� �־��⿡ char **�� �ƴ� char *
	int i;
	for (i = 0; i < len; i++) {
		if (pstr[i] < 'a') pstr[i] += -'A' + 'a';
	}
}

int mystrlen(char* str) {
	int i, cnt = 0;
	for (i = 0; str[i] != '\0'; i++) { //*(str + i) : str�迭�� ���� �ּ� ���� i�� ���� �ּҰ� ����Ű�� ��? �� �ּҿ� �ִ� ��(char�ϱ� 1����Ʈ�� �б�)
		cnt++;
	}
	return cnt;
}

void output(int jud) {
	if (jud == 1) printf("ȸ���Դϴ�!\n\n");
	else printf("ȸ���� �ƴմϴ�!\n\n");
	return;
}