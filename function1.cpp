/*���� �Է��� �޾� ���丮�� ����, ���� ���� �� ����, ����, �Ǽ� �Է� �� ���Է� �䱸 */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int inputInt(const char* msg);
int fact(int);
void output(int, int);
//int fact(int num);
//myflush�� ��ũ�� �Լ���
#define MYFLUSH {while(getchar() != '\n') ;} //��ü���� �ʰ� �߰�ȣ��. �Ұ�ȣ�� ����
int main(void)
{
	//TODO
	int num, fac;
	char str[] = "he;;o\n";
	printf(str);
	while (1) {
		num = inputInt("���� �Է� : ");
		if (num < 0) break;
		fac = fact(num);
		output(num, fac);
	}
	return 0;
}
//�Լ��� ����� ���� �ϴ� �ϰ� main �Լ��� �ۼ�

int inputInt(const char* msg) { //���ڿ� ����� �� �� ���ڿ��� ���� �ּ��̰� �����
	int num;
	while (1)
	{
		printf(msg);//��� ��� "%s"�� �� ����ǥ�� ���ڿ���, ��� ����� �ּҸ� �׳� �� ��. �ڿ��� �׳� �����ϴ� ���̱⿡ ����� ���ڿ��� �ּҸ� �ָ� ����� ���ڿ��� �׳� ��� ����� ��
		//printf("%s", msg);
		scanf("%d", &num); //�Է� ���۰� ��� �ִ� ���¿����� ���� �Է� : �� �����
		//����ڰ� �Է��ϱ⸦ ��ٸ�
		//���ʹ� �Է� ���� ���������� ���� �ȿ� ���๮�ڷ� ����
		//���๮�ڴ� �ܿ������Ͱ� �ǰ� �ܿ������ʹ� ���� �Է� �Լ��� ������ ��ħ
		if (getchar() != '\n') //������ �Է� ���� �ʾҴٸ�
			MYFLUSH
			/*while (getchar() != '\n');*/ //NULL statement�� ���� �ʾƵ� ������ �ٸ� ���ߵ鿡�� ���� �ǵ��� ���� �ʾҴٴ� ���� �˷��� 
		//��. �̶��� �߰�ȣ �־�� �� ���� ������ �� ���� ������ while�� ���ӵ�
		else break; //������ �Է� �Ǿ��ٸ�
		/*
		if (getchar() == '\n') break;
		else myflush(); //���۸� ����� �Լ�
		// getchar() : stdin ���ۿ��� �� ���� �� ���ھ� �������� �Լ�
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