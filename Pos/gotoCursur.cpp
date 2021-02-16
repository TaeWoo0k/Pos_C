#include"Header.h"
int gotoCursor(int width, int length, int x, int y)
/*������ ���� ������ ����Ű�� �����̸� Ŀ���� �ش� ��ġ��ŭ �̵���Ű��, �ٸ�Ű���� �������� �ش� �ƽ�Ű�ڵ带 ��ȯ�ϴ� �Լ�*/
{
	x += 2;/*Ŀ���� ������ ��ġ�� ��������. �̴� printBox�� ���� '��' ���� ��ȣ�� ��µ� �� ������ Ŀ���� �������� �ʵ��� ���� ����*/
	y += 1;
	int a = x, b = y;
	int xy;
	int x_max = x - 1 + width * (2 * (garo + 1)), y_max = y - 1 + length * (sero + 1);/*x, yĿ�� ������ �ִ밪�� ����*/
	int key;/*�Է¹��� key ��*/
	gotoxy(a, b);
	printBox2(a, b);
	do
	{
		key = getch();
		if (key == 0 || key == 0xe0)/*�Է¹��� key�� Ȯ���ڵ��� ���, 2byte�� �ʿ�� �ϹǷ� �ٸ� Ű�ʹ� �޸� ����*/
		{
			key = getch();/*�Է��� �� �� �� ���������ν� ���� ���� ��*/
			switch (key)
			{
			case 72:/*���� ������ ȭ��ǥ Ű �Է�*/
				delBox2(a, b);
				b = b - (sero + 1);
				if (b < y)	b = y;/*���� �� �� �ִ� �ִ밪 ����*/
				printBox2(a, b);
				gotoxy(a, b);
				break;
			case 75:/*���� ������ ȭ��ǥ Ű �Է�*/
				delBox2(a, b);
				a = a - (2 * garo + 2);
				if (a < x)	a = x;/*�������� �� �� �ִ� �ִ밪 ����*/
				printBox2(a, b);
				gotoxy(a, b);
				break;
			case 77:/*������ ������ ȭ��ǥ Ű �Է�*/
				delBox2(a, b);
				a = a + 2 * garo + 2;
				if (a > x_max)	a = x;/*���������� �� �� �ִ� �ִ밪 ����*/
				printBox2(a, b);
				gotoxy(a, b);
				break;
			case 80:/*�Ʒ��� ������ ȭ��ǥ Ű �Է�*/
				delBox2(a, b);
				b = b + sero + 1;
				if (b > y_max)	b = y;/*�Ʒ������� �� �� �ִ� �ִ밪 ����*/
				printBox2(a, b);
				gotoxy(a, b);
				break;
			}
		}
		else/*�Էµ� Ű�� �Ϲ� �ƽ�Ű �ڵ� �� ���*/
		{
			switch (key)
			{
			case 27:/*ESC*/
				return key;
			case 13:/*Enter*/
				delBox2(a, b);
				a = (a - x) / (2 * (garo + 1));
				b = (b - y) / (sero + 1);
				xy = a + b * 5;/*���� ����� ���ؼ� xy���� ���̺� ��ȣ(0~19) ������ ���� ��Ÿ��*/
				return xy;
			case 9:/*Tab*/
				return 54;/*T�� �ƽ�Ű�ڵ�. 9�� �ƴ� 54�� return��Ű�� ������ ���͸� return�ÿ� 9���� ���̺� ��ȣ�� ��ĥ �� �ֱ� ����*/
			case 43:/*'+'*/
				return key;
			case 45:/*'-'*/
				return key;
			}
		}
	} while ((key == 72) || (key == 75) || (key == 77) || (key == 80));/*����Ű�� �ƴҶ� ���� �ݺ�*/
}