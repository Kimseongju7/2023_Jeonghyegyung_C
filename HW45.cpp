/*작성자 : 김성주 HW */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
void inputInt(const char* msg, int* num);
int inputCharEO(int st, int end);
void even(int st, int end);
void odd(int, int);
int main(void)
{
	//TODO
	int st = 0, end = 0;
	int jud;
	inputInt("# 시작값을 입력하시오 : ", &st);
	while (end <= st) inputInt("# 끝 값을 입력하시오 : ", &end);
	jud = inputCharEO(st, end);
	if (jud == 0) even(st, end);
	else odd(st, end);
	
	return 0;
}

void inputInt(const char* msg, int* num) { //문자열 상수는 곧 그 문자열의 시작 주소이고 상수임
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
		printf("* %d~%d까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요?(짝수:e/홀수:o) : ", st, end);
		scanf(" %c", &c);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else if (c == 'e' || c == 'o') break;
		else ;
	}
	if (c == 'e') return 0; //짝수면 10리턴
	else return 1; //홀수면 1 리턴

}

void even(int st, int end) {
	int i, sum = 0;
	printf("  %d~%d 까지의 짝수(", st, end);
	for (i = st; i <= end; i++) {
		if (i % 2 == 0) {
			printf("%d ", i);
			sum += i;
		}
	}
	printf("\b)의 합은 %d 입니다.\n", sum);
}

void odd(int st, int end) {
	int i, sum = 0;
	printf("  %d~%d 까지의 홀수(", st, end);
	for (i = st; i <= end; i++) {
		if (i % 2 == 1) {
			printf("%d ", i);
			sum += i;
		}
	}
	printf("\b)의 합은 %d 입니다.\n", sum);
}