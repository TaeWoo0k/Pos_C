#include"Header.h"
int gotoCursor3(int width, int length, int x, int y)
/*������ ���� ������ ����Ű�� �����̸� Ŀ���� �ش� ��ġ��ŭ �̵���Ű��, �ٸ�Ű���� �������� �ش� �ƽ�Ű�ڵ带 ��ȯ�ϴ� �Լ�*/
{
	int a = x, b = y;
	int xy;
	int x_max = x - 1 + width * (2 * (garo + 1)), y_max = y - 1 + length;/*x, yĿ�� ������ �ִ밪�� ����*/
	int key;/*�Է¹��� key ��*/
	gotoxy(a, b);
	printf("��");
	do
	{
		key = getch();
		if (key == 0 || key == 0xe0)/*�Է¹��� key�� Ȯ���ڵ��� ���, 2byte�� �ʿ�� �ϹǷ� �ٸ� Ű�ʹ� �޸� ����*/
		{
			key = getch();/*�Է��� �� �� �� ���������ν� ���� ���� ��*/
			switch (key)
			{
			case 72:/*���� ������ ȭ��ǥ Ű �Է�*/
				b = b - 1;
				if (b < y)
				{
					b = y;/*���� �� �� �ִ� �ִ밪 ����*/
					printf("\b ");
					return 72;
				}
				else
				{
					printf("\b ");
					gotoxy(a, b);
					printf("��");
					break;
				}
			case 80:/*�Ʒ��� ������ ȭ��ǥ Ű �Է�*/
				b = b + 1;
				if (b > y_max)
				{
					b = y;/*�Ʒ������� �� �� �ִ� �ִ밪 ����*/
					printf("\b ");
					return 80;
				}
				else
				{
					printf("\b ");
					gotoxy(a, b);
					printf("��");
					break;
				}
			}
		}
		else/*�Էµ� Ű�� �Ϲ� �ƽ�Ű �ڵ� �� ���*/
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
				return 54;/*T�� �ƽ�Ű�ڵ�. 9�� �ƴ� 54�� return��Ű�� ������ ���͸� return�ÿ� 9���� ���̺� ��ȣ�� ��ĥ �� �ֱ� ����*/
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
	} while ((key == 72) || (key == 75) || (key == 77) || (key == 80));/*����Ű�� �ƴҶ� ���� �ݺ�*/
}
