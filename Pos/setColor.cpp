#include"Header.h"
void setColor(int bg, int fg)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg | fg);
}
