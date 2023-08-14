/*작성자 : 김성주 HW50 문자검색 프로그램(단일 검색) */
#include <stdio.h>
#include<string.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
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
			if (loc == -1) printf("\"%s\"문자열 안에 \'%c\'문자는 존재하지 않습니다.\n\n", str, c);
			else printf("\"%s\"문자열 안에 \'%c\'문자는 %d번 위치에 존재합니다.\n\n", str, c, loc);
		}
	}
	return 0;
}

int input(char* str, char *c) {
	printf("# 문자열을 입력하시오 : ");
	scanf("%s", str);
	if (strcmp(str, "end") == 0) return 0;
	else {
		MYFLUSH
		printf("# 문자를 입력하시오 : ");
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
