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
	printf("sub()�Լ� ȣ�� abc �Լ�\n");
}