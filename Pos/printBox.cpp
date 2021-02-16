#include"Header.h"
void printBox(int width, int length, int x, int y)/*원하는 좌표 (x, y)값을 시작으로 가로 width개, 세로length개 박스 생성*/
{
	int i = 0, j = 0, k = 0, l = 0;

	gotoxy(x, y);/*박스 맨 윗줄의 ┌────┬───┐ 부분 제작 */
	printf("┌");
	for (j = 0; j < width - 1; j++)
	{
		for (k = 0; k < garo; k++)
		{
			printf("─");
		}
		printf("┬");
	}
	for (k = 0; k < garo; k++)
	{
		printf("─");
	}
	printf("┐");

	gotoxy(x, ++y);/*두 번째 줄인 │    │    │ 제작*/
	for (l = 0; l < length - 1; l++)
	{
		for (i = 0; i < sero; i++)
		{
			for (j = 0; j < width; j++)
			{
				printf("│");
				for (k = 0; k < garo; k++)
				{
					printf("  ");
				}
			}
			printf("│");
			gotoxy(x, ++y);
		}

		printf("├");/*교차점인 ├───┼───┤ 부분 제작*/
		for (j = 0; j < width - 1; j++)
		{
			for (k = 0; k < garo; k++)
			{
				printf("─");
			}
			printf("┼");
		}
		for (k = 0; k < garo; k++)
		{
			printf("─");
		}
		printf("┤");
		gotoxy(x, ++y);
	}

	for (i = 0; i < sero; i++)/*│    │    │ 부분 제작*/
	{
		for (j = 0; j < width; j++)
		{
			printf("│");
			for (k = 0; k < garo; k++)
			{
				printf("  ");
			}
		}
		printf("│");
		gotoxy(x, ++y);
	}

	printf("└");/*맨 마지막줄인 └───┴───┘ 제작*/
	for (j = 0; j < width - 1; j++)
	{
		for (k = 0; k < garo; k++)
		{
			printf("─");
		}
		printf("┴");
	}
	for (k = 0; k < garo; k++)
	{
		printf("─");
	}
	printf("┘\n");
}