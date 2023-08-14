#include <stdio.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int inputInt(const char*);
void myflush();
int main(void)
{
	//TODO
	int age;
	int score;

	age = inputInt("나이 입력 : ");
	score = inputInt("점수 입력 : ");
	printf("age = %d\n", age);
	printf("score = %d\n", score);
	return 0;
}

int inputInt(const char* msg) { //문자열 상수는 곧 그 문자열의 시작 주소이고 상수임
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

double inputDouble(const char* msg) { //문자열 상수는 곧 그 문자열의 시작 주소이고 상수임
	double num;
	while (1) {
		printf("%s", msg);
		scanf("%lf", &num);
		if (getchar() != '\n')
			while (getchar() != '\n');
		else break;
	}
	return num;
}

void myflush() {
	while (getchar() != '\n');
	return;
}