#include"Header.h"
void party(Info* tableInfo)/*'단체' 설정 함수*/
{
	int i = 0, j, key = 0;
	int partyNum[11] = { 0 };/*단체 테이블들에는 고유번호가 있고, 아직 사용되지 않은 고유번호중 가장 작은 수를 찾아내기 위한 배열.*/
	int leastParty;/*사용 가능 단체 고유번호 중 가장 작은 번호*/
	int tableNum[20] = { 0 }; /*단체로 설정할 테이블들을 임시 저장할 배열.*/
	int paragraph = 0;
	int masterParty;/*단체로 만들기 위해 선택한 테이블중 가장 작은 인덱스의 테이블을 그 단체의 '마스터'로 두어 관리*/

	system("cls");
	nowTime();/*현재 시간 출력*/
	gotoxy(1, 5);
	printBox(5, 4, 1, 5);/*가로 5칸, 세로 4칸의 박스를 x좌표 1, y좌표 5 위치에서 부터 생성*/
	printNum(5, 4, 1, 5, tableInfo);/*가로 5칸, 세로 4칸의 박스에 x좌표 1, y좌표 5 위치에서부터 1부터 20(5*4)까지 넘버링*/
	printBox(1, 1, 130, 40);
	gotoxy(134, 43);
	printf("단체 선택 완료");/*선택된 단체 테이블들의 번호를 출력할 박스 생성*/
	for (i = 0; i < 20; i++) {
		partyNum[tableInfo[i].partyInfo] = 1;
	}/*만약 어떤 테이블이 단체로 설정되어있고, 단체 고유번호가 존재한다면 그 고유번호를 인덱스로 취급한뒤 partyNum배열에 1을 저장*/
	for (i = 10; i > 0; i--) {/*가장 작은 번호를 추출하기 위해서 10부터 시작, 감소*/
		if (partyNum[i] == 0) {/*단체라면 1로 초기화했기 때문에 0은 단체가 아니라는 의미*/
			leastParty = i;/*가장 작은 인덱스를 '최저 단체' 변수로 저장*/
		}
	}
	while (paragraph != 2) {/*선택 완료시까지 반복*/
		if (paragraph == 0) {/*'테이블 칸' 부분의 동작*/
			nowTime();/*현재 시간 출력*/
			gotoxy(1, 5);
			printBox3(5, 12, 130, 4);
			for (i = 0, j = 0; i < 20; i++) {
				if (tableNum[i] != 0) {/*해당 테이블이 단체인 경우*/
					gotoxy(138, 6 + j);
					printf("%d번", i + 1);/*우측의 작은 상자 안에 테이블 번호가 출력되도록 설정*/
					j++;
				}
			}
			key = gotoCursor(5, 4, 1, 5);
			if (key == 54) {/*'텝'키 입력시 '선택 완료'부분으로 이동*/
				paragraph = 1;
			}
			else if (key == 27) {/*ESC 입력시 종료*/
				return;
			}
			else if (tableNum[key] == 100) {/*선택된 테이블을 재 선택시 임시 단체 번호인 100을 회수하고 초기값인 0을 저장*/
				tableNum[key] = 0;
			}
			else {/*선택된 테이블에게 임시 단체 번호인 100을 부여해줌*/
				tableNum[key] = 100;
			}
		}
		else if (paragraph == 1) {/*'선택 완료' 부분*/
			key = gotoCursor(1, 1, 130, 40);
			if (key == 54) {/*'탭' 키를 눌러서 '테이블 칸' 부분으로 이동하려 할시*/
				delBox2(130, 40);/*printBox2로 생성된 작은 상자를 지우고 paragraph를 0으로 바꿔서 '테이블 칸'으로 이동*/
				paragraph = 0;
			}
			else if (key == 0) {/*엔터 입력시 paragraph를 2로 바꿔서 반복문을 종료*/
				paragraph = 2;
			}
			else if (key == 27) {/*'ESC' 입력시 함수를 종료, 저장되지 않음*/
				return;
			}
		}
	}
	for (i = 0; tableNum[i] != 100; i++) {
	}/*임시 단체 테이블을 만나면 반복문을 종료. 0부터 시작했기 때문에 선택된 임시 단체 테이블중에 가장 낮은 인덱스의 i가 도출됨*/
	masterParty = i;/*가장 낮은 인덱스의 i를 '단체의 마스터 테이블'로 지정*/
	for (i = 0; i < 20; i++) {
		if (tableNum[i] == 100) {/*임시 단체 테이블로 지정된 경우*/
			tableInfo[i].purpose = 3;/*테이블의 목적을 단체를 의미하는 3으로 바꾸고*/
			tableInfo[i].partyInfo = leastParty;/*n 번째 단체 번호를 부여하며*/
			tableInfo[i].masterParty = masterParty;/*그 단체의 마스터가 될 테이블의 정보를 저장*/
		}
	}
}