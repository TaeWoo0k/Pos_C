
#include"Header.h"
int bill(int number, int tableNum, Info* tableInfo)
{
	int i, j, key;
	int innerMoney = 0;
	int totalCoast = 0;
	int sizeofMenu = 0;
	char LMC[um][lm][13] = {
		{ "삼겹살", "항정살", "꽃등심", "안창살", "갈매기살" },
		{ "콜라", "사이다", "매화주", "소주", "맥주" },
		{ "된장찌개", "물냉면", "비빔냉면" }
	};/*메뉴의 이름을 저장*/
	int menuCoast[um][lm] = {
		{ 9000, 12000, 30000, 13000, 10000 },
		{ 1500, 1500, 3000, 3000, 4000 },
		{ 3000, 4500, 4500 } };/*메뉴의 가격을 저장*/

	for (i = 0; i < um; i++) {
		for (j = 0; j < lm; j++) {
			if (tableInfo[tableNum].menuList[i][j] != 0) {
				totalCoast += (menuCoast[i][j] * tableInfo[tableNum].menuList[i][j]);
			}/*총액을 저장*/
		}
	}
	time_t curr;
	struct tm* d;
	curr = time(NULL);
	d = localtime(&curr);

	system("cls");
	printf("대박집\n");
	while (innerMoney < totalCoast) {/*금액을 입력받는 부분*/
		printf("합 계 : %d\n받은 돈 : ", totalCoast);
		scanf("%d", &innerMoney);
		if (innerMoney < totalCoast) {
			printf("금액이 적습니다.\n");
		}
		else {
			printf("받은돈 : %d\n", innerMoney);
		}
	}
	printf("거스름 돈 : %d\n", innerMoney - totalCoast);
	printBox(1, 1, 5, 20);
	gotoxy(7, 21);
	printf("영수증을");/*영수증 출력을 묻는 부분*/
	gotoxy(7, 22);
	printf("출력하시겠습니까?");
	printBox(2, 1, 5, 34);
	gotoxy(9, 36);
	printf("예");
	gotoxy(34, 36);
	printf("아니오");
	key = gotoCursor(2, 1, 5, 34);
	if (key == 27) {/*ESC의 경우 상위 함수로 이동*/
		return 27;
	}
	else if (key == 0) {
		system("cls");
		for (i = 0; i < um; i++) {
			for (j = 0; j < lm; j++) {
				if (tableInfo[tableNum].menuList[i][j] != 0) {
					sizeofMenu++;/*주문된 전체 메뉴의 수를 계산*/
				}
			}
		}
		tableInfo[tableNum].sizeofMenu = sizeofMenu;
		printBox3(18, 25 + sizeofMenu, 33, 5);
		gotoxy(39, 8);
		printf("%19s", "대박집");/*가게 정보 출력*/
		gotoxy(39, 10);
		printf("사업자No:123-45-67890");
		gotoxy(39, 11);
		printf("%30s", "대표 : 김이박");
		gotoxy(39, 12);
		printf("경기 안양시 만안구 성결대학로 8");
		gotoxy(39, 13);
		printf("Tel:031-464-3392");
		gotoxy(39, 14);
		printf("-------------------------------");
		gotoxy(39, 15);
		printf("%-10s%-5s%6s%10s", "품  명", "단 가", "수 량", "금 액"); /*항목 출력*/
		gotoxy(39, 16);
		printf("-------------------------------");
		sizeofMenu = 0;
		for (i = 0; i < um; i++) {
			for (j = 0; j < lm; j++) {
				if (tableInfo[tableNum].menuList[i][j] != 0) {
					sizeofMenu++;
					gotoxy(39, 16 + sizeofMenu);
					printf("%-10s%5d%5d%11d", LMC[i][j], menuCoast[i][j], tableInfo[tableNum].menuList[i][j], menuCoast[i][j] * tableInfo[tableNum].menuList[i][j]);
				}/*품명, 단가, 수량, 금액 출력*/
			}
		}
		gotoxy(39, sizeofMenu + 17);
		printf("-------------------------------");
		gotoxy(39, sizeofMenu + 18);
		printf("%-20s%11d", "합 계", totalCoast);
		gotoxy(39, sizeofMenu + 19);
		printf("%-20s%11d", "현 금", innerMoney);
		gotoxy(39, sizeofMenu + 20);
		printf("%-20s%11d", "받은 돈", innerMoney);
		gotoxy(39, sizeofMenu + 21);
		printf("%-20s%11d", "거스름 돈", innerMoney - totalCoast);
		gotoxy(39, sizeofMenu + 22);
		printf("-------------------------------");
		gotoxy(39, sizeofMenu + 24);
		printf("%21s", "감사합니다");
		gotoxy(39, sizeofMenu + 26);
		printf("%s", asctime(d));
		gotoxy(39, sizeofMenu + 28);
		printf("테이블 번호 : %2d", tableNum + 1);
		gotoxy(39, sizeofMenu + 29);
		printf("인원수 : %2d\n\n", number);
		fflush(stdin);
		getch();
	}
	return 0;
}
