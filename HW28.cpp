/*�ۼ��� : �輺�� HW28 ���� ������ ī��Ʈ ���α׷� */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf ��� �� ���� ����
int main(void)
{
	//TODO
	int char_cnt = 0, num_cnt = 0, bla_cnt = 0, oth_cnt = 0;
	char c;
	c = getchar();
	while (1) {
		if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
			char_cnt++;
			c = getchar();
		}
		else if ('0' <= c && c <= '9') {
			num_cnt++;
			c = getchar();
		}
		else if (c == '\t' || c == ' ') {
			bla_cnt++;
			c = getchar();
		}
		else if (c == '\n') {
			bla_cnt++;
			c = getchar();
			if (c == EOF) break;
		}
		else {
			oth_cnt++;
			c = getchar();
		}
	}
	printf("* ������ ��ҹ��� ���� : %d��\n", char_cnt);
	printf("* ���ڹ��� ���� : %d��\n", num_cnt);
	printf("* ���鹮��(space, tab, enter) ���� : %d��\n", bla_cnt);
	printf("* �� �� ��Ÿ���� ���� : %d��\n", oth_cnt);
		return 0;
}