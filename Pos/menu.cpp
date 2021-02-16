#include"Header.h"
int menu(int number, int tableNum, Info* tableInfo)/*메뉴들을 출력하여 그 중 손님이 원하는 메뉴를 선택하여 저장, 출력할 함수.*/
{
	int i, j, k, p, q = 0, r, key;
	int a, b, x = 3, y = 7;
	int sign = 0, location = 0;
	Stat myStat;
	myStat.totalCoast = 0; // 서버에 보낼 총액
	myStat.sizeofMenu[13]; // 서버에 보낼 메뉴 수량
	int i_umc, i_lmc;/*int_UpperMenuCategory :  상위 메뉴 카테고리에서 선택된 카테고리의 번호
					 int_LowerMenuCategory : 하위 메뉴 카테고리에서 선택된 카테고리의 번호*/
	int paragraph = 0;/*단락. 여기서는 각 paragraph의 값에 따라 선택 가능한, 이동 가능한 범위가 달라진다.
					  paragraph = 0 : 상위 메뉴 카테고리에 조작이 가능하다.
					  paragraph = 1 : 하위 메뉴 카테고리에 조작이 가능하다.
					  paragraph = 2 : 지금까지 선택된 메뉴들의 리스트 부분에 조작이 가능하다.
					  paragraph = 3 : "주문 완료"를 선택하기 위한 곳이다.
					  paragraph = 4 : 메뉴함수의 반복의 끝을 알리며, 다음 함수인 영수증으로 넘어갈 준비가 됨을 뜻한다.*/
	char UMC[um][14] = { { "고기류" }, { "음료/주류" }, { "후식" } };/*UpperMenuCategory. 상위 메뉴 카테고리 이다.*/
	char LMC[um][lm][13] = {
		{ "삼겹살", "항정살", "꽃등심", "안창살", "갈매기살" },
		{ "콜라", "사이다", "매화주", "소주", "맥주" },
		{ "된장찌개", "물냉면", "비빔냉면" }
	};/*LowerMenuCategory, 하위 메뉴 카테고리로서, 각각 상위 메뉴들에 종속된 메뉴들이다.*/
	int menuCoast[um][lm] = {
		{ 9000, 12000, 30000, 13000, 10000 },
		{ 1500, 1500, 3000, 3000, 4000 },
		{ 3000, 4500, 4500 } };/*각 메뉴들의 가격을 저장*/

	system("cls");
	nowTime();
	gotoxy(20, 1);
	printf("테이블 번호 : %d", tableNum + 1);
	gotoxy(20, 2);
	printf("인원수 : %d 명", number);
	printBox(3, 1, 1, 5);/*상위 메뉴 칸을 출력*/
	printBox(5, 1, 1, 18);/*하위 메뉴 칸을 출력*/
	printBox(1, 1, 80, 39);
	gotoxy(84, 41);
	printf("\t선택완료");
	do
	{
		switch (paragraph)
		{
		case 0:/*상위 메뉴 카테고리 영역*/
			a = x;
			b = y;
			for (i = 0; i < 3; i++)
			{
				gotoxy(a, b);
				printf("%12s", UMC[i]);/*미리 저장해둔 상위 카테고리 이름들을 출력한다*/
				a += 2 * (garo + 1);
			}
			a = x - 2;
			b = y + 13 * 2;
			k = 0;
			gotoxy(a, b);
			for (i = 0; i < um; i++) {/*선택된 메뉴의 개수만큼 반복*/
				for (j = 0; j < lm; j++) {
					if (tableInfo[tableNum].menuList[i][j] != 0) {
						k++;
						q = k > q ? k : q;
						printf("\t%9s\t", LMC[i][j]);/*선택된 하위 메뉴들을 출력한다.*/
						printf("%4d개\t", tableInfo[tableNum].menuList[i][j]);/*선택된 하위 메뉴의 수량 출력*/
						printf("%7d원\n", tableInfo[tableNum].menuList[i][j] * menuCoast[i][j]);/*선택된 하위메뉴의 가격 출력*/
					}
				}
			}
			for (r = k; r < q; r++) {/*메뉴의 취소를 통해서 새로 출력되는 양이 기존 내용보다 적어서 잔상이 남는 경우*/
				printf("\t\t\t\t\n");/*공백을 생성하여 덮어씌움*/
			}
			i_umc = gotoCursor(3, 1, 1, 5);/*상위 메뉴를 선택한다.*/
			if (i_umc == 27) {
				return 27;
			}
			else {
				paragraph = 1;/*상위 메뉴 선택이 끝나면 단락을 1, 즉 하위메뉴로 이동시킨다.*/
			}
		case 1:/*하위 메뉴 카테고리 영역*/
			a = x;
			b = y + 13;
			for (i = 0; i < 5; i++)
			{
				gotoxy(a, b);
				printf("%10s", LMC[i_umc][i]);/*미리 저장해둔 하위 메뉴 이름들을 출력한다.*/
				gotoxy(a, b + 2);
				if (menuCoast[i_umc][i] != 0) {
					printf("%10d", menuCoast[i_umc][i]);
				}
				else {
					printf("\t\t");
				}
				a += 2 * (garo + 1);
			}
			while (paragraph == 1)/*단락이 여전히 하위메뉴에 머무를 경우의 반복문*/
			{
				i_lmc = gotoCursor2(5, 1, 1, 18);/*하위 메뉴 카테고리의 값을 선택을 통해 넘겨받는다*/
				if (i_lmc == 27) {
					return 27;
				}
				else {
					fflush(stdin);
					if (i_lmc == 72)/*위쪽 화실표 방향키의 경우*/
					{
						paragraph = 0;/*상위메뉴로 이동시킨다.*/
					}
					else if (i_lmc == 80)/*아래 화살표 방향키의 경우*/
					{
						paragraph = 2;/*하위 메뉴로 이동시킨다.*/
					}
					else if (0 <= i_lmc && i_lmc <= lm)/*넘겨받은 값이 하위 메뉴의 인덱스 중 하나일 경우*/
					{
						tableInfo[tableNum].menuList[i_umc][i_lmc]++;
						a = x - 2;
						b = y + 13 * 2;
						k = 0;
						gotoxy(a, b);
						for (i = 0; i < um; i++) {/*선택된 메뉴의 개수만큼 반복*/
							for (j = 0; j < lm; j++) {
								if (tableInfo[tableNum].menuList[i][j] != 0) {
									k++;
									q = k > q ? k : q;
									printf("\t%9s\t", LMC[i][j]);/*선택된 하위 메뉴들을 출력한다.*/
									printf("%4d개\t", tableInfo[tableNum].menuList[i][j]);/*선택된 하위 메뉴의 수량 출력*/
									printf("%7d원\n", tableInfo[tableNum].menuList[i][j] * menuCoast[i][j]);/*선택된 하위메뉴의 가격 출력*/
								}
							}
						}
						for (r = k; r < q; r++) {/*메뉴의 취소를 통해서 새로 출력되는 양이 기존 내용보다 적어서 잔상이 남는 경우*/
							printf("\t\t\t\t\n");/*공백을 생성하여 덮어씌움*/
						}
					}
				}
			}
		case 2:/*선택된 메뉴 리스트를 관리하는 영역*/
			a = x;
			b = y + 13 * 2;
			gotoxy(a, b);
			while (paragraph == 2) {
				key = gotoCursor3(1, k, a, b);
				if (key == 72) {/*위 방향키는 하위 메뉴, 아래 방향키면 '선택완료' 로 이동*/
					paragraph = 1;
				}
				else if (key == 80) {
					paragraph = 3;
				}
				else if (key == 27) {
					printf("\b ");
					paragraph = 3;
				}
				else if ((1000 <= key) && (key <= 3000)) {/*'+' 또는 '-'를 입력받았을 경우*/
					location = key % 1000;/*연산을 통해 반환된 값을 디코더하여 n번째 위치와 부호로 나눠 저장*/
					sign = key / 1000;
					p = 0;
					for (i = 0; i < um && p <= location; i++) {/*선택된 메뉴들중 n번째 (location값 만큼)의 메뉴를 선택*/
						for (j = 0; j < lm && p <= location; j++) {
							if (tableInfo[tableNum].menuList[i][j] != 0) {
								p++;
							}
						}
					}
					i--;
					j--;
					if (sign == 2) {/*'+'일 경우*/
						tableInfo[tableNum].menuList[i][j]++;/*개수를 증가시켜줌*/
					}
					else if (sign == 1) {/*'-'일 경우*/
						if (tableInfo[tableNum].menuList[i][j] > 0) {/*개수를 감소시켜줌*/
							tableInfo[tableNum].menuList[i][j]--;
						}
					}
				}
				a = x - 2;
				b = y + 13 * 2;
				k = 0;
				gotoxy(a, b);
				for (i = 0; i < um; i++) {/*선택된 메뉴의 개수만큼 반복*/
					for (j = 0; j < lm; j++) {
						if (tableInfo[tableNum].menuList[i][j] != 0) {
							k++;
							q = k > q ? k : q;
							printf("\t%9s\t", LMC[i][j]);/*선택된 하위 메뉴들을 출력한다.*/
							printf("%4d개\t", tableInfo[tableNum].menuList[i][j]);/*수량과 가격도 출력*/
							printf("%7d원\n", tableInfo[tableNum].menuList[i][j] * menuCoast[i][j]);
						}
					}
				}
				for (r = k; r < q; r++) {
					printf("\t\t\t\t\t\t\n");
				}
			}
		case 3:/*'선택 완료 창*/
			gotoxy(80, 39);
			while (paragraph == 3)
			{
				key = gotoCursor2(1, 1, 80, 39);
				switch (key)
				{
				case 27:/*ESC이면 상위 함수로 이동*/
					return 27;
				case 72:/*위 방향키이면 '선택된 메뉴 리스트'로 이동*/
					paragraph = 2;
					break;
				case 0:/*엔터를 누른 경우 반복 조건의 불만족을 통한 반복문을 종료*/
					paragraph = 4;
					break;
				case 80:/*아래 방향키를 누른 경우 반복 조건의 불만족을 통한 반복문을 종료*/
					paragraph = 4;
					break;
				}
			}
		}
	} while (paragraph != 4);/*이 반복을 모든 주문이 완료될 때 까지 반복*/




	printBox3(22, 10, 40, 15);
	gotoxy(44, 20);
	printf("계산을 진행하시겠습니까?");
	printBox(2, 1, 41, 28);
	gotoxy(44, 30);
	printf("%12s", "예");
	gotoxy(44 + 2 * (garo + 1), 30);
	printf("%12s", "아니오");
	key = gotoCursor(2, 1, 41, 28);



	tableInfo[tableNum].totalCoast = 0;/*해당 테이블의 총액을 초기화*/
	tableInfo[tableNum].sizeofMenu = 0;/*해당 테이블의 메뉴 종류들을 초기화*/
	tableInfo[tableNum].number = number;/*해당 테이블의 인원수를 입력되었던 인원수로 조정*/
	if (tableInfo[tableNum].purpose == 0) {/*테이블 사용 목적이 '빈 테이블' 인 경우*/
		tableInfo[tableNum].purpose = 1;/*사용중인 테이블로 목적을 변경*/
	}
	else if (tableInfo[tableNum].purpose == 3) {/*테이블의 사용 목적이 '단체' 인 경우*/
		tableInfo[tableNum].purpose = 4;/*사용중인 단체 테이블로 목적 변경*/
	}
	for (i = 0; i < um; i++) {
		for (j = 0; j < lm; j++) {
			tableInfo[tableNum].totalCoast += menuCoast[i][j] * tableInfo[tableNum].menuList[i][j];/*해당 테이블의 총액을 저장*/
			myStat.totalCoast += tableInfo[tableNum].totalCoast;                                 // 서버에보낼 구조체의 총액 저장
			if (tableInfo[tableNum].menuList[i][j] != 0) {/*주문된 메뉴의 수량이 0이 아닌 경우, 즉 주문을 1개 이상 한 경우*/
				tableInfo[tableNum].sizeofMenu++;/*주문한 메뉴의 종류 값을 추가*/
				myStat.sizeofMenu[i * 5 + j]++; // 서버에 보낼 메뉴의 수량 저장
			}
		}
	}




	if (key == 27) {/*ESC 눌렀을 경우 27 반환*/
		return 27;
	}
	else if (key == 0) {/*'예'를 의미하는 0 눌렀을 경우 0 반환*/
		return 0;
	}
	else { /*'아니오'를 의미하는 1 눌렀을 경우 1 반환*/
		return 1;
	}
}
