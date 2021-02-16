#include"Header.h"
int gotoCursor2(int width, int length, int x, int y)
/*지정된 범위 내에서 방향키를 움직이면 커서를 해당 위치만큼 이동시키며, 다른키들을 눌렀을땐 해당 아스키코드를 반환하는 함수
위의 gotoCursor과 다른점은 위, 아래 방향키 또한 반환시킨다는 점인데, 이는 메뉴함수의 특성상 상위, 하위 메뉴로 이동하기 위해서 별도로 구분함
따라서 위, 아래 방향키를 반환한다는 점을 제외한 다른부분은 동일*/
{
	x += 2;
	y += 1;
	int a = x, b = y;
	int xy;
	int x_max = x - 1 + width * (2 * (garo + 1)), y_max = y - 1 + length * (sero + 1);
	char key;
	gotoxy(a, b);
	printBox2(a, b);
	do
	{
		key = getch();
		switch (key)
		{
		case 72:
			delBox2(a, b);
			return 72;/*위쪽 방향의 화살표 키의 코드값 72를 return*/
		case 75:
			delBox2(a, b);
			a = a - (2 * garo + 2);
			if (a < x)	a = x;
			printBox2(a, b);
			gotoxy(a, b);
			break;
		case 77:
			delBox2(a, b);
			a = a + 2 * garo + 2;
			if (a > x_max)	a = x;
			printBox2(a, b);
			gotoxy(a, b);
			break;
		case 80:
			delBox2(a, b);
			return 80;/*아래쪽 방향의 화살표 키의 코드값 80을 return*/
		case 27:/*ESC*/
			return key;
		case 13:/*Enter*/
			delBox2(a, b);
			a = (a - x) / (2 * (garo + 1));
			b = (b - y) / (sero + 1);
			xy = a + b * 5;
			return xy;
		case 9:/*Tab*/
			return 54;/*T의 아스키코드*/
		case 43:/*'+'*/
			return key;
		case 45:/*'-'*/
			return key;
		}
	} while (key != 27);
}