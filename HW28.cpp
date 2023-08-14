/*작성자 : 김성주 HW28 문자 종류별 카운트 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
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
	printf("* 영문자 대소문자 개수 : %d개\n", char_cnt);
	printf("* 숫자문자 개수 : %d개\n", num_cnt);
	printf("* 여백문자(space, tab, enter) 개수 : %d개\n", bla_cnt);
	printf("* 그 외 기타문자 개수 : %d개\n", oth_cnt);
		return 0;
}