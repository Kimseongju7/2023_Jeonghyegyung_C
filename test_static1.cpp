#include <stdio.h> //여기 있는 함수들도 extern 함수 이기에 선언 후 사용가능 //정의부는 라이브러리 기계어 파일에 있어서 include 여러번 하더라도 정의부는 하나
static void abc();
void sub();
int num = 0;
int main(void)
{
	//TODO
	abc();
	sub();
	return 0;
}

static void abc(void) {
	printf("main() 함수 호출 abc 함수\n");
}