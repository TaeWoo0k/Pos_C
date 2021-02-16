#include"Header.h"
void nowTime()/*현재 시간을 분단위 까지만 출력할 함수*/
{
	time_t curr;
	struct tm* d;
	curr = time(NULL);
	d = localtime(&curr);
	gotoxy(1, 1);
	printf("대박집\n");
	printf("%.16s", asctime(d));/*맨 위에 현재 시간을 분 단위까지 출력*/
}