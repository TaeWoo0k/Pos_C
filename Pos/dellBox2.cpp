#include"Header.h"/*printBox2�� ���� ������ ���� �׸� �ڽ� �ϳ��� ����� ����*/
void delBox2(int x, int y)
{
	int i = 0, j = 0, k = 0, l = 0;
	int hoing = 9, jong = 9;
	gotoxy(x, y);/*�ڽ� �� ������ ������������������ �κ� ���� */
	for (k = 0; k < hoing + 2; k++)
	{
		printf("  ");
	}
	gotoxy(x, ++y);/*�� ��° ���� ��        �� ����*/
	for (i = 0; i < jong; i++) {
		printf("  ");
		gotoxy(x + (hoing * 2) + 2, y);
		printf("  ");
		gotoxy(x, ++y);
	}
	for (k = 0; k < hoing + 2; k++)/*�� ���������� ���������������� ����*/
	{
		printf("  ");
	}
}