#include"Header.h"
void printBox3(int sizeofX, int sizeofY, int x, int y)/*���ϴ� ��ǥ (x, y)���� �������� ����sizeofX, ���� sizeofY ũ���� 1�� �簢�� ����*/
{
	int i = 0, j = 0;
	x += 2;
	y++;
	gotoxy(x, y);/*�ڽ� �� ������ ������������������ �κ� ���� */
	printf("��");
	for (i = 0; i < sizeofX; i++)
	{
		printf("��");
	}
	printf("��");

	gotoxy(x, ++y);/*�� ��° ���� ��        �� ����*/
	for (i = 0; i < sizeofY; i++) {
		printf("��");
		for (j = 0; j < sizeofX; j++) {
			printf("  ");
		}
		printf("��");
		gotoxy(x, ++y);
	}
	printf("��");/*�� ���������� ���������������� ����*/
	for (i = 0; i < sizeofX; i++)
	{
		printf("��");
	}
	printf("��");
}