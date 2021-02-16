#include"Header.h"
void reserve(Info* tableInfo)
{
	int hour, minute; // 시간, 분
	int number = 0; //인원수
	int yesNo;
	char key = 0;

	system("cls");
	nowTime();/*현재 시간 출력*/
	gotoxy(1, 5);
	printBox(5, 4, 1, 5);
	printNum(5, 4, 1, 5, tableInfo);
	key = gotoCursor(5, 4, 1, 5);
	if (key == 27) {/*ESC입력시 종료*/
		return;
	}
	if (tableInfo[key].purpose == 0) {/*선택된 테이블이 예약석이 아닐 경우. 즉, 예약 가능한 경우*/
		printBox3(22, 15, 40, 15);
		gotoxy(44, 20);
		printf("예약 시간을 입력하시오 :  ");
		scanf("%d %d", &hour, &minute);/*시간과 분을 저장*/
		gotoxy(44, 21);
		printf("예약 인원수를 입력시오 : ");
		scanf("%d", &number);
		gotoxy(44, 25);
		printf("예약 시간 %02d:%02d\n", hour, minute);/*예약된 시간과 인원수를 출력*/
		gotoxy(44, 26);
		printf("%d번 테이블 예약 인원수 : %d", key + 1, number);
		tableInfo[key].purpose = 2;/*테이블의 상태를 '예약'으로 변경*/
		tableInfo[key].number = number;/*인원수를 입력된 인원수로 변경*/
		tableInfo[key].hour = hour;/*시간과 분을 입력된 값으로 저장*/
		tableInfo[key].minute = minute;
		getch();
	}
	else if (tableInfo[key].purpose == 2) {/*선택된 테이블이 예약석일 경우. 즉, 예약취소할 경우*/
		printBox3(22, 10, 40, 15);
		gotoxy(44, 20);
		printf(" 예약을 취소하시겠습니까?");
		printBox(2, 1, 41, 28);
		gotoxy(44, 30);
		printf("%12s", "예");
		gotoxy(44 + 2 * (garo + 1), 30);
		printf("%12s", "아니오");
		yesNo = gotoCursor(2, 1, 41, 28);
		if (yesNo == 0) {
			tableInfo[key].purpose = 0;/*테이블의 상태를 '미사용'으로 변경*/
			tableInfo[key].number = 0;/*저장되었던 인원수를 0으로 초기화*/
			tableInfo[key].hour = 0;/*저장되었던 시간과 분을 0으로 초기화*/
			tableInfo[key].minute = 0;
		}
		else if (key == 27) {/*ESC를 입력받은 경우*/
			return;/*함수를 종료*/
		}
	}
	else if (tableInfo[key].purpose == 1 || tableInfo[key].purpose == 3 || tableInfo[key].purpose == 4) {/*선택한 테이블이 사용중인 경우*/
		printBox3(22, 10, 40, 15);/*22x10 크기의 사각형 1개를 40, 15 위치에 생성*/
		gotoxy(44, 20);
		printf(" 이미 사용중인 테이블 입니다.");/*사용중인 테이블이라 출력하고 종료*/
		getch();
	}
}