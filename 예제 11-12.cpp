#include<stdio.h>
#include<malloc.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int** myAlloc(int, int);
void dataInput(int**, int, int);
void dataOutput(int**, int, int);
void myDelete(int**, int); //�簡�� ���� ����
int main()
{
	int** ip;
	int col, row;
	printf("row �� �Է� : ");
	scanf("%d", &row);
	printf("column �� �Է� : ");
	scanf("%d", &col);
	ip = myAlloc(row, col);
	if (ip == NULL) printf("�Ҵ� ����!\n");
	else {
		dataInput(ip, row, col);
		dataOutput(ip, row, col);
		myDelete(ip, row);
	}
	return 0;
}

int** myAlloc(int row, int col) {
	int** ip;
	int i;
	ip = (int**)malloc(sizeof(int*) * row); //int �ƴ� int *��		//�簡�� �޸��� ���� �ּҸ� ������ ��� �޸� ���� �Ҵ�
	if (ip == NULL) return NULL; //��� �޸� �Ҵ� �����ߴٸ�
	for (i = 0; i < row; i++) { //�簡�� �޸𸮴� row�� �ʿ�. �簡�� �޸� ũ�Ⱑ col��
		ip[i] = (int*)malloc(sizeof(int) * col);		//��� �޸𸮿� �簡�� �޸� �Ҵ��ϰ� ���� �ּ� ����
		if (ip[i] == NULL) { //����� �޸� �Ҵ� ���� �ߴٸ�
			//�׳� �����ϸ� ������ �Ҵ�� �簡�� �޸𸮴� �������
			myDelete(ip, i);//���������� �Ҵ��� ���� ����
			return NULL;
		}
	}

	return ip;
}

void dataInput(int** ip, int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		printf("\n%d�� �Է�\n", i + 1);
		for (j = 0; j < col; j++) {
			printf("���� �Է� : ");
			scanf("%d", (*(ip + i) + j)); //scanf�� ������ ���Ĺ��� �ڿ��� ��� �͵� �Է��ϸ� �� ��. ������ �Ͼ
		}
	}
	printf("\n");
	return;
}

void dataOutput(int** ip, int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%5d", ip[i][j]);
		}
		printf("\n");
	}
	return;
}

void myDelete(int** ip, int row) {
	int i;
	if (ip != NULL) {
		for (i = 0; i < row; i++) { //�簡�� �Ÿ𸮴� row�� ���� �� �ึ�� �簡�� �޸��� �ּҰ� �����
			//if (ip[i] != NULL) {
				free(ip[i]); //�簡�� �޸� ����
			//} ip���Ͱ� �� ������ �� �ȿ� �ִ� �ֵ鵵 �� ����
		}
		free(ip); //��� �޸� ����
	} //������ �޽����� ������ �߰��� ���� �ʰ� ����� ����� ��
}