#include"Header.h"
void func(Info* tableInfo)/*기능키들이 포진될 함수.*/
{
	int key;
	int x = 3, y = 7;
	for (key = 0; key != 27;) {
		system("cls");
		nowTime();/*현재 시간 출력*/
		gotoxy(1, 5);
		printBox(4, 1, 1, 5);
		gotoxy(x, y);
		printf("%12s", "예 약");
		gotoxy(x + 2 * (garo + 1), y);
		printf("%12s", "단 체");
		gotoxy(x + 4 * (garo + 1), y);
		printf("%12s", "총 매출액");
		gotoxy(x + 6 * (garo + 1), y);
		printf("%12s", "종 료");
		key = gotoCursor(4, 1, 1, 5);
		if (key == 0) {/*0번 칸을 선택시 - 예약함수 선택시*/
			reserve(tableInfo);/*예약 함수로 이동*/
		}
		else if (key == 1) {
			party(tableInfo);
		}
		else if (key == 2) {
			totalSell();
		}
		else if (key == 3) {/*시스템 종료 선택시*/
			gotoxy(2, 50);
			exit(1);/*프로그램 종료*/
		}
	}
}