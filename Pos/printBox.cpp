#include"Header.h"
void printBox(int width, int length, int x, int y)/*���ϴ� ��ǥ (x, y)���� �������� ���� width��, ����length�� �ڽ� ����*/
{
	int i = 0, j = 0, k = 0, l = 0;

	gotoxy(x, y);/*�ڽ� �� ������ �������������������� �κ� ���� */
	printf("��");
	for (j = 0; j < width - 1; j++)
	{
		for (k = 0; k < garo; k++)
		{
			printf("��");
		}
		printf("��");
	}
	for (k = 0; k < garo; k++)
	{
		printf("��");
	}
	printf("��");

	gotoxy(x, ++y);/*�� ��° ���� ��    ��    �� ����*/
	for (l = 0; l < length - 1; l++)
	{
		for (i = 0; i < sero; i++)
		{
			for (j = 0; j < width; j++)
			{
				printf("��");
				for (k = 0; k < garo; k++)
				{
					printf("  ");
				}
			}
			printf("��");
			gotoxy(x, ++y);
		}

		printf("��");/*�������� ������������������ �κ� ����*/
		for (j = 0; j < width - 1; j++)
		{
			for (k = 0; k < garo; k++)
			{
				printf("��");
			}
			printf("��");
		}
		for (k = 0; k < garo; k++)
		{
			printf("��");
		}
		printf("��");
		gotoxy(x, ++y);
	}

	for (i = 0; i < sero; i++)/*��    ��    �� �κ� ����*/
	{
		for (j = 0; j < width; j++)
		{
			printf("��");
			for (k = 0; k < garo; k++)
			{
				printf("  ");
			}
		}
		printf("��");
		gotoxy(x, ++y);
	}

	printf("��");/*�� ���������� ������������������ ����*/
	for (j = 0; j < width - 1; j++)
	{
		for (k = 0; k < garo; k++)
		{
			printf("��");
		}
		printf("��");
	}
	for (k = 0; k < garo; k++)
	{
		printf("��");
	}
	printf("��\n");
}