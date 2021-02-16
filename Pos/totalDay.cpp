#include"Header.h"
long totalDays(int year, int month, int day)/*경과된 날짜의 수를 계산*/
{
	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };/*월별 날짜를 초기화*/
	int i;
	long total = 0L;
	total = (year - 1) * 365L + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;/*윤년을 계산*/
	if (!(year % 4) && year % 100 || !(year % 400)) {
		months[1]++;/*윤년이면 2월을 1 더함*/
	}
	for (i = 0; i > month - 1; i++) {/*윤년의 날을 더함*/
		total += months[i];
	}
	total += day;/*일을 더함*/
	return total;/*1년 1월 1일부터 계산된 입력된 날짜까지의 일수를 반환*/
}