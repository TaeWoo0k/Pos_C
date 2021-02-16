#include"Header.h"

// ���� �Լ� ���� ��� �� ����
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

//���� �Լ� ���� ���
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
	Info* tableInfo;/*���̺� ������ ��Ÿ�� ����ü ����*/
	tableInfo = (Info*)malloc(sizeof(Info) * 20);/*20���� ���̺� �� ��ŭ ����*/
	for (i = 0; i < 20; i++) {
		tableInfo[i].purpose = 0;/*����ü ������ ��� �׸���� �ʱ�ȭ*/
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

	//���� �ʱ�ȭ
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
			printBox(2, 1, 1, 5);/*���̺� �κа� ���Ű �κ��� ������ ���*/
			gotoxy(31, 7);
			printf("���Ű");
			gotoxy(7, 7);
			printf("���̺�");


			key = gotoCursor(2, 1, 1, 5);

			if ((key == 54) || (key == 1))/*TabŰ �� ��� ���Ű �Լ��� �̵�*/
			{
				paragraph = 50;
			}
			else/*�׷��� ���� ��� ���̺� �Լ��� �̵�*/
			{
				paragraph = 1;
			}
		}
		else if (paragraph == 1) {/*���̺� �Լ�*/
			Return = table(tableInfo);/*���̺� �Լ��� �����Ű�� ��ȯ���� �޾ƿ�*/
			if (Return == 27 || Return == 0) {/*ESC�̸� ���� �������� �̵�*/
				paragraph = 0;
			}
			else {/*�ο����� ���̺� ��ȣ�� �޾ƿ� ��� �޴��Լ��� �̵�*/
				number = Return / 100;
				tableNum = Return % 100;
				paragraph = 2;
			}
		}
		else if (paragraph == 2) {/*�޴��Լ�*/
			Return = menu(number, tableNum, tableInfo);/*�޴��Լ��� �����Ű�� ��ȯ���� �޾ƿ�*/
			if (Return == 27) {/*ESC�̸� ���� �������� �̵�*/
				paragraph = 1;
			}
			else if (Return == 0) {/*�׷��� ������ ������ �Լ��� �̵�*/
				paragraph = 3;
			}
			else if (Return == 1) {
				paragraph = 0;
			}
		}
		else if (paragraph == 3) {/*������ �Լ�*/
			Return = bill(number, tableNum, tableInfo);/*������ �Լ��� �����Ű�� ��ȯ���� �޾ƿ�*/
			if (Return == 27) {/*ESC�̸� ���� �������� �̵�*/
				paragraph = 2;
			}
			else {/*�׷��� ������ �Ѿ��� �޾ƿͼ� �������� �Լ��� �̵�*/
				paragraph = 4;
			}
		}
		else if (paragraph == 4) {/*������ ���������� �Լ�*/

			int retval;
			// ������ ������( ����üS ������. )
			int len = sizeof(Stat);
			retval = send(sock, (const char*)&myStat, 13 * sizeof(Stat), 0);
			if (retval == SOCKET_ERROR) {
				err_display("send()");
				exit(1);
			}




			paragraph = 0;/*�ʱ� ȭ������ ���ư�*/
		}


		else if (paragraph == 50) {/*���Ű �Լ�*/
			func(tableInfo);
			paragraph = 0;/*���� ����� �ʱ�ȭ������ ���ư�*/
		}
	}
}
