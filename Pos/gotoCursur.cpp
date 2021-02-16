#include"Header.h"
int gotoCursor(int width, int length, int x, int y)
/*지정된 범위 내에서 방향키를 움직이면 커서를 해당 위치만큼 이동시키며, 다른키들을 눌렀을땐 해당 아스키코드를 반환하는 함수*/
{
	x += 2;/*커서가 깜빡일 위치를 지정해줌. 이는 printBox로 인해 '┌' 같은 기호가 출력된 곳 위에서 커서가 깜빡이지 않도록 함을 위함*/
	y += 1;
	int a = x, b = y;
	int xy;
	int x_max = x - 1 + width * (2 * (garo + 1)), y_max = y - 1 + length * (sero + 1);/*x, y커서 조정의 최대값을 설정*/
	int key;/*입력받을 key 값*/
	gotoxy(a, b);
	printBox2(a, b);
	do
	{
		key = getch();
		if (key == 0 || key == 0xe0)/*입력받은 key가 확장코드일 경우, 2byte를 필요로 하므로 다른 키와는 달리 동작*/
		{
			key = getch();/*입력을 한 번 더 수행함으로써 문제 없게 함*/
			switch (key)
			{
			case 72:/*위쪽 방향의 화살표 키 입력*/
				delBox2(a, b);
				b = b - (sero + 1);
				if (b < y)	b = y;/*위로 갈 수 있는 최대값 설정*/
				printBox2(a, b);
				gotoxy(a, b);
				break;
			case 75:/*왼쪽 방향의 화살표 키 입력*/
				delBox2(a, b);
				a = a - (2 * garo + 2);
				if (a < x)	a = x;/*왼쪽으로 갈 수 있는 최대값 설정*/
				printBox2(a, b);
				gotoxy(a, b);
				break;
			case 77:/*오른쪽 방향의 화살표 키 입력*/
				delBox2(a, b);
				a = a + 2 * garo + 2;
				if (a > x_max)	a = x;/*오른쪽으로 갈 수 있는 최대값 설정*/
				printBox2(a, b);
				gotoxy(a, b);
				break;
			case 80:/*아래쪽 방향의 화살표 키 입력*/
				delBox2(a, b);
				b = b + sero + 1;
				if (b > y_max)	b = y;/*아래쪽으로 갈 수 있는 최대값 설정*/
				printBox2(a, b);
				gotoxy(a, b);
				break;
			}
		}
		else/*입력된 키가 일반 아스키 코드 일 경우*/
		{
			switch (key)
			{
			case 27:/*ESC*/
				return key;
			case 13:/*Enter*/
				delBox2(a, b);
				a = (a - x) / (2 * (garo + 1));
				b = (b - y) / (sero + 1);
				xy = a + b * 5;/*위의 계산을 통해서 xy값은 테이블 번호(0~19) 사이의 값을 나타냄*/
				return xy;
			case 9:/*Tab*/
				return 54;/*T의 아스키코드. 9가 아닌 54를 return시키는 이유는 엔터를 return시에 9번의 테이블 번호가 겹칠 수 있기 때문*/
			case 43:/*'+'*/
				return key;
			case 45:/*'-'*/
				return key;
			}
		}
	} while ((key == 72) || (key == 75) || (key == 77) || (key == 80));/*방향키가 아닐때 까지 반복*/
}