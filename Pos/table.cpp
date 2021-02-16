#include"Header.h"

int table(Info* tableInfo)/*테이블 칸 출력과 예약석인지 여부를 판단하여 빈 테이블임이 확실시 되면 인원수를 입력받고 다음 함수로 넘어갈
						   테이블 함수. 메인함수로부터 구조체 tableInfo를 받아온다.*/
{
	int tableNum = 0;/*gotoCursor로 부터 반환된 값을 저장할 변수*/
	int number = 0;/*인원수를 입력받을 때 쓸 변수. 0으로 초기화 되어 있다.*/

	for (; number == 0;)/*인원수를 입력하여 저장하기 전 까지 반복*/
	{
		system("cls");
		nowTime();/*현재 시간 출력*/
		gotoxy(1, 5);
		printBox(5, 4, 1, 5);/*가로 5칸, 세로 4칸의 박스를 x좌표 1, y좌표 5 위치에서 부터 생성*/
		printNum(5, 4, 1, 5, tableInfo);/*가로 5칸, 세로 4칸의 박스에 x좌표 1, y좌표 5 위치에서부터 1부터 20(5*4)까지 넘버링*/
		tableNum = gotoCursor(5, 4, 1, 5);
		if (tableNum == 27) {
			return 27;
		}
		else {
			if (tableInfo[tableNum].purpose == 0)/*해당 테이블이 빈 테이블일 경우*/
			{
				printBox3(22, 15, 40, 15);
				gotoxy(44, 20);
				printf("인원수를 입력하시오 : ");
				scanf("%d", &number);
				if (number <= 0 || 6 < number) {/*0명 이하거나 6명 초과인 경우*/
					gotoxy(44, 22);
					printf("한 테이블의 인원은 6명을 초과할 수 없습니다.");
					number = 0;
					Sleep(900);/*0.9초 동안 멈춤*/
				}
				else {/*인원수를 알맞게 입력한 경우*/
					gotoxy(44, 25);
					printf("%d번 테이블의 인원수는 %d명 입니다.", tableNum + 1, number);/*인원수를 입력받고 저장*/
					Sleep(1000);
				}
			}
			else if (tableInfo[tableNum].purpose == 1) {/*해당 테이블이 사용중인 테이블일 경우*/
				number = tableInfo[tableNum].number;/*사용중이라는 것은 인원수가 저장 되었다는 뜻이다. 이때 인원수를 받아오면 반복문이 종료된다*/
			}
			else if (tableInfo[tableNum].purpose == 2)/*해당 테이블이 예약석일 경우*/
			{
				printBox3(22, 15, 40, 15);/*22*15크기의 박스를 40, 15 위치에 하나 생성*/
				gotoxy(44, 20);
				printf("예약된 테이블 입니다.");/*예약석임을 명시하고 1초동안 멈춤*/
				Sleep(1000);
			}
			else if (tableInfo[tableNum].purpose == 3)/*해당 테이블이 단체로 사용중일 경우*/
			{
				tableNum = tableInfo[tableNum].masterParty;/*테이블 번호는 '단체 관리자' 테이블 번호를 받아옴. 이는 같은 단체 내에서 두 부류로 나눠서 별개의 계산이 되는 것을 방지하기 위함*/
				printBox3(22, 15, 40, 15);/*22*15크기의 박스를 40,15 위치에 생성*/
				gotoxy(44, 20);
				printf("인원수를 입력하시오 : ");/*인원수를 입력하라고 출력한 뒤 입력받음*/
				scanf("%d", &number);
				gotoxy(55, 25);
				printf("<  단체  >");
				gotoxy(44, 26);
				printf("테이블의 인원수는 %d명 입니다.", number);/*인원수를 입력받고 저장*/
				Sleep(1000);
			}
			else if (tableInfo[tableNum].purpose == 4) {/*사용중인 단체 테이블인 경우*/
				tableNum = tableInfo[tableNum].masterParty;/*테이블 번호는 '단체 관리자' 번호로, */
				number = tableInfo[tableNum].number;/*인원수는 해당 테이블에 저장된 인원수를 받아옴*/
			}
		}
		system("cls");
	}
	return (100 * number + tableNum);/*인원수와 테이블 번호와의 연산값을 반환함. 두 값을 한 번에 return 할 수 없기 때문에 이 방법을 택함*/
}