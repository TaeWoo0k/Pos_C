#include"Header.h"/*printBox2로 인해 생성된 작은 네모 박스 하나를 지우는 역할*/
void delBox2(int x, int y)
{
	int i = 0, j = 0, k = 0, l = 0;
	int hoing = 9, jong = 9;
	gotoxy(x, y);/*박스 맨 윗줄의 ┌───────┐ 부분 삭제 */
	for (k = 0; k < hoing + 2; k++)
	{
		printf("  ");
	}
	gotoxy(x, ++y);/*두 번째 줄인 │        │ 삭제*/
	for (i = 0; i < jong; i++) {
		printf("  ");
		gotoxy(x + (hoing * 2) + 2, y);
		printf("  ");
		gotoxy(x, ++y);
	}
	for (k = 0; k < hoing + 2; k++)/*맨 마지막줄인 └──────┘ 삭제*/
	{
		printf("  ");
	}
}