/*작성자 : 김성주 HW46 요일 구하는 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int input(const char* msg, int* pyear, int* pmon, int* pday);
int errorcheck(int year, int mon, int day, int* pmonthday);
int totaldays(int year, int mon, int day, int* pmonthday);
void output(int tot);
int yearCheck(int year);
int main(void)
{
	//TODO
	int year, mon, day, totdays;
	int monthday[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int end, jud = 0;
	while (1) {
		while (jud == 0) {
			end = input("* 년 월 일을 입력하시오 : ", & year, &mon, &day);
			if (end == 0) return 0;
			jud = errorcheck(year, mon, day, monthday);
		}
		totdays = totaldays(year, mon, day, monthday);
		printf("  %d년 %d월 %d일은 ", year, mon, day);
		output(totdays);
		jud = 0;
	}
	return 0;
}

int input(const char* msg, int* pyear, int* pmon, int* pday) {
	while (1) {
		printf(msg);
		scanf("%d%d%d", pyear, pmon, pday);
		if (getchar() != '\n')
			return 0;
		else break;
	}
	return 1;
}

int errorcheck(int year, int mon, int day, int* pmonthday) {
	if (year < 1900) return 0;
	if (mon < 1 || mon > 12) return 0;
	if (day < 1) return 0;
	if (mon == 2) {
		if (yearCheck(year)) {
			if (day > (pmonthday[mon] + 1)) return 0;
		}
		else {
			if (day > pmonthday[mon]) return 0;
		}
	}
	else if (day > pmonthday[mon]) return 0;
	return 1;
}

int totaldays(int year, int mon, int day, int* pmonthday) {
	int sumy = 0, summ = 0, tot = 0;
	int i;
	for (i = 1900; i < year; i++) {
		if (yearCheck(i)) sumy += 366;
		else sumy += 365;
	}
	for (i = 1; i < mon; i++) {
		summ += pmonthday[i];
	}
	tot = sumy + summ + day;
	if (yearCheck(year) && mon >= 3) tot++;
	return tot;
}

int yearCheck(int year) {
	int n;
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) n = 1;
			else n = 0;
		}
		else n = 1;
	}
	else n = 0;
	return n;
}

void output(int tot) {
	int Day;
	Day = tot % 7;
	switch (Day)
	{
	case 0 : 
		printf("일요일입니다.\n");
		break;
	case 1:
		printf("월요일입니다.\n");
		break;
	case 2:
		printf("화요일입니다.\n");
		break;
	case 3:
		printf("수요일입니다.\n");
		break;
	case 4:
		printf("목요일입니다.\n");
		break;
	case 5:
		printf("금요일입니다.\n");
		break;
	case 6:
		printf("토요일입니다.\n");
		break;
	default:
		break;
	}
}