#include"Header.h"
void printBox2(int x, int y)/*원하는 좌표 (x, y)값에 printBox로 생성된 박스보다 한 칸씩 작은박스를 1개 생성*/
{
	int i = 0, j = 0, k = 0, l = 0;
	int hoing = 9, jong = 9;
	gotoxy(x, y);/*박스 맨 윗줄의 ┌─────┐ 부분 제작 */
	printf("┌");
	for (k = 0; k < hoing; k++)
	{
		printf("─");
	}
	printf("┐");

	gotoxy(x, ++y);/*두 번째 줄인 │      │ 제작*/
	for (i = 0; i < jong; i++) {
		printf("│");
		gotoxy(x + (hoing * 2) + 2, y);
		printf("│");
		gotoxy(x, ++y);
	}
	printf("└");/*맨 마지막줄인 └─────┘ 제작*/
	for (k = 0; k < hoing; k++)
	{
		printf("─");
	}
	printf("┘");
}
