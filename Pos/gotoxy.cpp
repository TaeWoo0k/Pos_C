#include"Header.h"
void gotoxy(int x, int y)/*커서의 위치 제어*/
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}