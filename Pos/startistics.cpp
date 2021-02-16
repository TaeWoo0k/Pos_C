#include"Header.h"
void statistics(int key, int** menuList)/*통계함수*/
{
	int i, j, k, quantity;
	char LMC[um][lm][13] = {
		{ "삼겹살", "항정살", "꽃등심", "안창살", "갈매기살" },
		{ "콜라", "사이다", "매화주", "소주", "맥주" },
		{ "된장찌개", "물냉면", "비빔냉면" }
	};/*메뉴들의 이름을 저장*/
	system("cls");/*화면 지우고 시간 출력*/
	nowTime();/*현재 시간 출력*/
	gotoxy(1, 5);

	for (i = 0; i < um; i++) { /*상위메뉴*하위 메뉴 만큼 반복*/
		for (j = 0; j < lm; j++) {
			if (LMC[i][j][0] != 0) {/*메뉴 이름이 저장되지 않은 상태가 아닐때, 즉 메뉴가 존재하는 경우*/
				printf("%-10s│", LMC[i][j]);/*메뉴 이름을 출력*/
				quantity = menuList[i][j] / 2;/*수량을 2로 나눈것 만큼 ■ 출력*/
				for (k = 0; k < quantity; k++) {
					printf("■");
				}
				printf("%d\n%10s│\n", menuList[i][j], " ");/*실제 판매개수 출력하고 줄바꿈*/
			}
		}
	}
	getchar();
}