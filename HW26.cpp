/*�ۼ��� : �輺�� HW26 ���� ���� �� ������ ������ */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int input(void);
void output(int hum, int com, int jud);
char shum[4][30] = { "0", "  ����� ���� ����,", "  ����� ���� ����,", "  ����� �� ����," };
char scom[4][30] = { "0", "��ǻ�ʹ� ���� ����", "��ǻ�ʹ� ���� ����", "��ǻ�ʹ� �� ����" };
int main(void)
{
	//TODO
	srand((unsigned int)time(NULL));
	int com, hum, win=0, draw=0;
	com = rand() % 3 + 1;
	hum = input();
	int minus = com - hum;
	while (!(minus == 2 || minus == -1)) {
		if (minus == 0) {
			draw++;
			output(hum, com, 0);
		}
		else {
			win++;
			output(hum, com,  1);
		}
		com = rand() % 3 + 1;
		hum = input();
		minus = com - hum;
	}
	output(hum, com, -1);
	printf("���Ӱ�� : %d �� %d ��\n", win, draw);
	return 0;
}

int input(void) {
	int hum;
	while (1) {
		printf("# ������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");
		scanf("%d", &hum);
		if (1 <= hum && hum <= 3) break;
	}
	return hum;
}

void output(int hum, int com, int jud) {
	if (jud == 0) printf("%s %s : �����ϴ�.\n", shum[hum], scom[com]);
	else if (jud == 1) printf("%s %s : �̰���ϴ�.\n", shum[hum], scom[com]);
	else printf("%s %s : ����� �����ϴ�.\n", shum[hum], scom[com]);
	return;
}