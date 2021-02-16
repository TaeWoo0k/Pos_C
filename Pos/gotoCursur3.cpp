#include"Header.h"
int gotoCursor3(int width, int length, int x, int y)
/*지정된 범위 내에서 방향키를 움직이면 커서를 해당 위치만큼 이동시키며, 다른키들을 눌렀을땐 해당 아스키코드를 반환하는 함수*/
{
	int a = x, b = y;
	int xy;
	int x_max = x - 1 + width * (2 * (garo + 1)), y_max = y - 1 + length;/*x, y커서 조정의 최대값을 설정*/
	int key;/*입력받을 key 값*/
	gotoxy(a, b);
	printf("▣");
	do
	{
		key = getch();
		if (key == 0 || key == 0xe0)/*입력받은 key가 확장코드일 경우, 2byte를 필요로 하므로 다른 키와는 달리 동작*/
		{
			key = getch();/*입력을 한 번 더 수행함으로써 문제 없게 함*/
			switch (key)
			{
			case 72:/*위쪽 방향의 화살표 키 입력*/
				b = b - 1;
				if (b < y)
				{
					b = y;/*위로 갈 수 있는 최대값 설정*/
					printf("\b ");
					return 72;
				}
				else
				{
					printf("\b ");
					gotoxy(a, b);
					printf("▣");
					break;
				}
			case 80:/*아래쪽 방향의 화살표 키 입력*/
				b = b + 1;
				if (b > y_max)
				{
					b = y;/*아래쪽으로 갈 수 있는 최대값 설정*/
					printf("\b ");
					return 80;
				}
				else
				{
					printf("\b ");
					gotoxy(a, b);
					printf("▣");
					break;
				}
			}
		}
		else/*입력된 키가 일반 아스키 코드 일 경우*/
		{
			switch (key)
			{
			case 27:/*ESC*/
				return key;
			case 13:/*Enter*/
				b = (b - y);
				xy = b;
				return xy;
			case 9:/*Tab*/
				return 54;/*T의 아스키코드. 9가 아닌 54를 return시키는 이유는 엔터를 return시에 9번의 테이블 번호가 겹칠 수 있기 때문*/
			case 43:/*'+'*/
				xy = 2000 + b - y;
				printf("\b ");
				return xy;
			case 45:/*'-'*/
				xy = 1000 + b - y;
				printf("\b ");
				return xy;
			}
		}
	} while ((key == 72) || (key == 75) || (key == 77) || (key == 80));/*방향키가 아닐때 까지 반복*/
}
