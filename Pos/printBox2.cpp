#include"Header.h"
void printBox2(int x, int y)/*���ϴ� ��ǥ (x, y)���� printBox�� ������ �ڽ����� �� ĭ�� �����ڽ��� 1�� ����*/
{
	int i = 0, j = 0, k = 0, l = 0;
	int hoing = 9, jong = 9;
	gotoxy(x, y);/*�ڽ� �� ������ �������������� �κ� ���� */
	printf("��");
	for (k = 0; k < hoing; k++)
	{
		printf("��");
	}
	printf("��");

	gotoxy(x, ++y);/*�� ��° ���� ��      �� ����*/
	for (i = 0; i < jong; i++) {
		printf("��");
		gotoxy(x + (hoing * 2) + 2, y);
		printf("��");
		gotoxy(x, ++y);
	}
	printf("��");/*�� ���������� �������������� ����*/
	for (k = 0; k < hoing; k++)
	{
		printf("��");
	}
	printf("��");
}
