/*작성자 : 김성주 HW52 회문(Palindrome) 검사 프로그램 */
#include <stdio.h>
#include<string.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
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
		input("# 단어 입력 : ", str);
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

void mytolower(char* pstr, int len) { //call by argument, pstr의 주소가 아닌 안에 들어있는 값을 주었기에 char **가 아닌 char *
	int i;
	for (i = 0; i < len; i++) {
		if (pstr[i] < 'a') pstr[i] += -'A' + 'a';
	}
}

int mystrlen(char* str) {
	int i, cnt = 0;
	for (i = 0; str[i] != '\0'; i++) { //*(str + i) : str배열의 시작 주소 값에 i를 더한 주소가 가리키는 값? 그 주소에 있는 값(char니까 1바이트를 읽기)
		cnt++;
	}
	return cnt;
}

void output(int jud) {
	if (jud == 1) printf("회문입니다!\n\n");
	else printf("회문이 아닙니다!\n\n");
	return;
}