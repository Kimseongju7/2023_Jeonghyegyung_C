#include <stdio.h> //���� �ִ� �Լ��鵵 extern �Լ� �̱⿡ ���� �� ��밡�� //���Ǻδ� ���̺귯�� ���� ���Ͽ� �־ include ������ �ϴ��� ���Ǻδ� �ϳ�
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
	printf("main() �Լ� ȣ�� abc �Լ�\n");
}