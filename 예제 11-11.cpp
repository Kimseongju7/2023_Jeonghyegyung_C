#include<stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int* myAlloc(int);
void dataInput(int*, int);
void dataOutput(int*, int);
void myDelete(int*);
int main()
{
	int* ip;
	int col;
	printf("column �� �Է� : "); //���� ����
	scanf("%d", &col);
	ip = myAlloc(col);
	//���� �Ҵ� ���� ó�� �ڵ�
	if (ip == NULL) printf("���� �޸� �Ҵ� ����!\n");
	else {
		dataInput(ip, col); //���� ���� �� �����ϸ� ��Ÿ�� ����
		dataOutput(ip, col);
		myDelete(ip);
	}
	return 0;
}

int* myAlloc(int col) { //���� ������ŭ ���� �޸� �Ҵ��ؼ� ����
	int* ip;
	ip = (int*)malloc(sizeof(int) * col);
	//20����Ʈ�� �Ҵ�Ǹ� ip�� �� �� �� 20 ����Ʈ�� int�� 5�� �迭ó�� ����
	return ip; //�ּҸ� �����ָ� ��� ����
}

void dataInput(int* ip, int col) {
	int i;
	for (i = 0; i < col; i++) {
		printf("���� �Է� : ");
		scanf("%d", ip + i); //scanf("%d",&ip[i]); //Ÿ��, ������ �°� �����ּҸ� ��� ������ �迭��ó�� ��� ����
	}
	return;
}

void dataOutput(int* ip, int col) {
	int i;
	for (i = 0; i < col; i++) {
		printf("%5d", *(ip + i));
	}
	printf("\n");
	return;
}

void myDelete(int* ip) {
	if (ip != NULL) { //���� �޸� �Ҵ� ����?
		free(ip);
	}
	return;
}