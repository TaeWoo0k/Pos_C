#include"Header.h"

// 소켓 함수 오류 출력 후 종료
void err_quit(char* msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
	exit(1);
}

//소켓 함수 오류 출력
void err_display(char* msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf, 0, NULL);
	MessageBox(NULL, (LPCTSTR)lpMsgBuf, msg, MB_ICONERROR);
	printf("[%s} %s", msg, (char*)lpMsgBuf);
	LocalFree(lpMsgBuf);
}

int main()
{
	Stat myStat;
	myStat.sizeofMenu[13];
	myStat.totalCoast;
	int retval;

	int i, j, k;
	char key;
	int paragraph = 0;
	int Return = 0;
	int number = 0, tableNum = 0;
	int** menuList;
	Info* tableInfo;/*테이블 정보를 나타낼 구조체 설정*/
	tableInfo = (Info*)malloc(sizeof(Info) * 20);/*20개의 테이블 수 만큼 생성*/
	for (i = 0; i < 20; i++) {
		tableInfo[i].purpose = 0;/*구조체 내부의 모든 항목들을 초기화*/
		tableInfo[i].totalCoast = 0;
		tableInfo[i].hour = 0;
		tableInfo[i].minute = 0;
		tableInfo[i].sizeofMenu = 0;
		tableInfo[i].partyInfo = 0;
		tableInfo[i].masterParty = 20;
		tableInfo[i].number = 0;
		tableInfo[i].menuList = (int**)malloc(sizeof(int*) * um);
		for (j = 0; j < um; j++) {
			tableInfo[i].menuList[j] = (int*)malloc(sizeof(int) * lm);
			for (k = 0; k < lm; k++) {
				tableInfo[i].menuList[j][k] = 0;
			}
		}
	}

	//윈속 초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	//socket()
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) err_quit("socket()");

	//connect()
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(SERVERIP);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = connect(sock, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) err_quit("connect()");


	for (paragraph = 0; paragraph < 100;)
	{
		if (paragraph == 0) {
			system("cls");
			nowTime();
			printBox(2, 1, 1, 5);/*테이블 부분과 기능키 부분을 나눠서 출력*/
			gotoxy(31, 7);
			printf("기능키");
			gotoxy(7, 7);
			printf("테이블");


			key = gotoCursor(2, 1, 1, 5);

			if ((key == 54) || (key == 1))/*Tab키 일 경우 기능키 함수로 이동*/
			{
				paragraph = 50;
			}
			else/*그렇지 않을 경우 테이블 함수로 이동*/
			{
				paragraph = 1;
			}
		}
		else if (paragraph == 1) {/*테이블 함수*/
			Return = table(tableInfo);/*테이블 함수를 실행시키고 반환값을 받아옴*/
			if (Return == 27 || Return == 0) {/*ESC이면 이전 수행으로 이동*/
				paragraph = 0;
			}
			else {/*인원수와 테이블 번호를 받아온 경우 메뉴함수로 이동*/
				number = Return / 100;
				tableNum = Return % 100;
				paragraph = 2;
			}
		}
		else if (paragraph == 2) {/*메뉴함수*/
			Return = menu(number, tableNum, tableInfo);/*메뉴함수를 실행시키고 반환값을 받아옴*/
			if (Return == 27) {/*ESC이면 이전 수행으로 이동*/
				paragraph = 1;
			}
			else if (Return == 0) {/*그렇지 않으면 영수증 함수로 이동*/
				paragraph = 3;
			}
			else if (Return == 1) {
				paragraph = 0;
			}
		}
		else if (paragraph == 3) {/*영수증 함수*/
			Return = bill(number, tableNum, tableInfo);/*영수증 함수를 실행시키고 반환값을 받아옴*/
			if (Return == 27) {/*ESC이면 이전 수행으로 이동*/
				paragraph = 2;
			}
			else {/*그렇지 않으면 총액을 받아와서 파일저장 함수로 이동*/
				paragraph = 4;
			}
		}
		else if (paragraph == 4) {/*서버에 데이터전송 함수*/

			int retval;
			// 데이터 보내기( 구조체S 보낸다. )
			int len = sizeof(Stat);
			retval = send(sock, (const char*)&myStat, 13 * sizeof(Stat), 0);
			if (retval == SOCKET_ERROR) {
				err_display("send()");
				exit(1);
			}




			paragraph = 0;/*초기 화면으로 돌아감*/
		}


		else if (paragraph == 50) {/*기능키 함수*/
			func(tableInfo);
			paragraph = 0;/*실행 종료시 초기화면으로 돌아감*/
		}
	}
}
