#include"Header.h"
int gotoCursor2(int width, int length, int x, int y)
/*������ ���� ������ ����Ű�� �����̸� Ŀ���� �ش� ��ġ��ŭ �̵���Ű��, �ٸ�Ű���� �������� �ش� �ƽ�Ű�ڵ带 ��ȯ�ϴ� �Լ�
���� gotoCursor�� �ٸ����� ��, �Ʒ� ����Ű ���� ��ȯ��Ų�ٴ� ���ε�, �̴� �޴��Լ��� Ư���� ����, ���� �޴��� �̵��ϱ� ���ؼ� ������ ������
���� ��, �Ʒ� ����Ű�� ��ȯ�Ѵٴ� ���� ������ �ٸ��κ��� ����*/
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
			return 72;/*���� ������ ȭ��ǥ Ű�� �ڵ尪 72�� return*/
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
			return 80;/*�Ʒ��� ������ ȭ��ǥ Ű�� �ڵ尪 80�� return*/
		case 27:/*ESC*/
			return key;
		case 13:/*Enter*/
			delBox2(a, b);
			a = (a - x) / (2 * (garo + 1));
			b = (b - y) / (sero + 1);
			xy = a + b * 5;
			return xy;
		case 9:/*Tab*/
			return 54;/*T�� �ƽ�Ű�ڵ�*/
		case 43:/*'+'*/
			return key;
		case 45:/*'-'*/
			return key;
		}
	} while (key != 27);
}