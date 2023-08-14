#include <stdio.h>
static void abc(void);
float num = 123;
void sub(void)
{
	//TODO
	abc();
	return;
}
static void abc(void) {
	printf("sub()함수 호출 abc 함수\n");
}