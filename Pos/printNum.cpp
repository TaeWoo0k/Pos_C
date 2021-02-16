#include"Header.h"
void printNum(int width, int length, int x, int y, Info* tableInfo)/*출력된 각 테이블 칸에 번호, 사용목적, 주문내역 등을 출력할 함수*/
{
	int i, j, k, p, q, r, s;
	int a = x, b = y;/*x,y 좌표를 a, b에 저장*/
	int xy;/*x, y 좌표를 연산을 통해서 n번째 테이블 인덱스를 나타낼 변수*/
	char LMC[um][lm][13] = {
		{ "삼겹살", "항정살", "꽃등심", "안창살", "갈매기살" },
		{ "콜라", "사이다", "매화주", "소주", "맥주" },
		{ "된장찌개", "물냉면", "비빔냉면" }/*메뉴의 이름을 초기화*/
	};
	a += 2;/*초기 커서 위치 설정*/
	b++;
	gotoxy(a, ++b);
	for (i = 0; i < length; i++) {/*가로 x 세로 수 만큼 반복*/
		for (j = 0; j < width; j++) {
			xy = j + i * 5;/*x, y 좌표로부터 인덱스를 도출*/
			printf("  %d", xy + 1);/*테이블 번호 출력*/
			if (tableInfo[xy].purpose == 1 || tableInfo[xy].purpose == 4) {
				/*사용중이거나 단체 테이블로 사용중인 경우*/
				if (tableInfo[xy].purpose == 4) {/*단체 테이블로 사용중일 경우 색깔로 구분*/
					gotoxy(a + 8, b);
					printf("단체 %d", tableInfo[xy].partyInfo);/*n번째 단체 테이블임을 의미*/
					gotoxy(a + 2, b + 1);
					setColor((tableInfo[xy].partyInfo) * 16, 15);/*n번째 단체 테이블에 16을 곱한 값을 배경 색깔로 지정*/
					for (k = 0; k < 8; k++) {
						printf("\t\t      ");/*정해진 색을 칠함*/
						gotoxy(a + 2, b + 2 + k);
					}
				}
				gotoxy(a + 2, b + 1);
				printf("%d원", tableInfo[xy].totalCoast);/*총액을 출력*/
				gotoxy(a + 2, b + 2);
				printf("%d명", tableInfo[xy].number);/*인원수를 출력*/
				for (p = um - 1; p >= 0; p--) {/*상위 메뉴 개수 만큼 반복하되, 높은 값에서 낮은 값으로 변화*/
					for (q = lm - 1; q >= 0; q--) {/*하위 메뉴 개수 만큼 반복하되, 높은 값에서 낮은 값으로 변화*/
						if (tableInfo[xy].menuList[p][q] != 0) {/*주문된 내역이 존재하여, 수량이 0이 아닌 경우*/
							r = p; /*인덱스 p를 r에 저장*/
							s = q;/*인덱스 q를 s에 저장*/
						}/*이 반복문을 통해서 주문된 내역들 중에서 가장 낮은 메뉴 번호를 가진 음식을 도출해냄
						 또한 이것을 통해서 출력된 table칸에 가장 낮은 메뉴 번호를 가진 메뉴가 출력될 것임*/
					}
				}
				gotoxy(a + 2, b + 3);
				printf("%.8s 외 %d개", LMC[r][s], tableInfo[xy].sizeofMenu - 1);/*주문된 메뉴 중에서 가장 낮은 메뉴 번호를 가진 메뉴 이름이 출력되고, 주문한 메뉴의 종류 역시 출력*/
				setColor(240, 0);/*색깔을 원래대로 돌림*/
			}
			else if (tableInfo[xy].purpose == 2) {/*예약석일 경우*/
				gotoxy(a + 8, b);
				printf("예약 %02d:%02d", tableInfo[xy].hour, tableInfo[xy].minute);/*예약석임을 명시하고 시간을 출력*/
			}
			else if (tableInfo[xy].purpose == 3) {/*빈 단체 테이블일 경우*/
				gotoxy(a + 8, b);
				printf("단체 %d", tableInfo[xy].partyInfo);/*지정된 단체 번호를 출력*/
				gotoxy(a + 2, b + 1);
				setColor((tableInfo[xy].partyInfo) * 16, 0);/*배경 색을 지정된 단체 번호에 16을 곱한 값으로 정함*/
				for (k = 0; k < 8; k++) {
					printf("\t\t      ");/*색깔을 칠함*/
					gotoxy(a + 2, b + 2 + k);
				}
				setColor(240, 0);/*색을 원래대로 돌림*/
			}
			a += 2 * garo + 2;
			gotoxy(a, b);
		}
		a = x + 2;/*커서 위치를 조정함*/
		b += sero + 1;
		gotoxy(a, b);
	}
}