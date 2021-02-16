#include"Header.h"
void printBox3(int sizeofX, int sizeofY, int x, int y)/*원하는 좌표 (x, y)값을 시작으로 가로sizeofX, 세로 sizeofY 크기의 1개 사각형 생성*/
{
	int i = 0, j = 0;
	x += 2;
	y++;
	gotoxy(x, y);/*박스 맨 윗줄의 ┌───────┐ 부분 제작 */
	printf("┌");
	for (i = 0; i < sizeofX; i++)
	{
		printf("─");
	}
	printf("┐");

	gotoxy(x, ++y);/*두 번째 줄인 │        │ 제작*/
	for (i = 0; i < sizeofY; i++) {
		printf("│");
		for (j = 0; j < sizeofX; j++) {
			printf("  ");
		}
		printf("│");
		gotoxy(x, ++y);
	}
	printf("└");/*맨 마지막줄인 └──────┘ 제작*/
	for (i = 0; i < sizeofX; i++)
	{
		printf("─");
	}
	printf("┘");
}