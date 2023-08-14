/*정수 입력을 받아 팩토리얼 구현, 음수 음력 시 종료, 문자, 실수 입력 시 재입력 요구 */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int inputInt(const char* msg);
int fact(int);
void output(int, int);
//int fact(int num);
//myflush를 매크로 함수로
#define MYFLUSH {while(getchar() != '\n') ;} //해체되지 않게 중괄호로. 소괄호는 오류
int main(void)
{
	//TODO
	int num, fac;
	char str[] = "he;;o\n";
	printf(str);
	while (1) {
		num = inputInt("정수 입력 : ");
		if (num < 0) break;
		fac = fact(num);
		output(num, fac);
	}
	return 0;
}
//함수를 만들기 전에 일단 믿고 main 함수로 작성

int inputInt(const char* msg) { //문자열 상수는 곧 그 문자열의 시작 주소이고 상수임
	int num;
	while (1)
	{
		printf(msg);//출력 양식 "%s"도 쌍 따옴표의 문자열임, 출력 양식의 주소를 그냥 준 것. 뒤에는 그냥 연산하는 것이기에 출력할 문자열의 주소를 주면 출력할 문자열이 그냥 출력 양식이 됨
		//printf("%s", msg);
		scanf("%d", &num); //입력 버퍼가 비어 있는 상태에서는 정수 입력 : 을 띄워두
		//사용자가 입력하기를 기다림
		//엔터는 입력 종료 조건이지만 버퍼 안에 개행문자로 들어옴
		//개행문자는 잔여데이터가 되고 잔여데이터는 다음 입력 함수에 영향을 미침
		if (getchar() != '\n') //정수가 입력 되지 않았다면
			MYFLUSH
			/*while (getchar() != '\n');*/ //NULL statement를 넣지 않아도 되지만 다른 개발들에게 내가 의도로 넣지 않았다는 것을 알려줌 
		//단. 이때는 중괄호 넣어야 함 넣지 않으면 그 다음 문장이 while에 종속됨
		else break; //정수가 입력 되었다면
		/*
		if (getchar() == '\n') break;
		else myflush(); //버퍼를 지우는 함수
		// getchar() : stdin 버퍼에서 한 번에 한 문자씩 꺼내오는 함수
		*/
	}
	return num;
}

int fact(int num) {
	if (num == 0) return 1;
	else return (num * fact(num - 1));
}

/*
int fact(int num) {
	int i, total = 1;
	for (i = 2; i <= num; i++) {
		total *= i;
	}
	return total;
}
*/

void output(int num, int fac) {
	printf("%d! = %d\n", num, fac);
}