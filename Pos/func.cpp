#include"Header.h"
void func(Info* tableInfo)/*���Ű���� ������ �Լ�.*/
{
	int key;
	int x = 3, y = 7;
	for (key = 0; key != 27;) {
		system("cls");
		nowTime();/*���� �ð� ���*/
		gotoxy(1, 5);
		printBox(4, 1, 1, 5);
		gotoxy(x, y);
		printf("%12s", "�� ��");
		gotoxy(x + 2 * (garo + 1), y);
		printf("%12s", "�� ü");
		gotoxy(x + 4 * (garo + 1), y);
		printf("%12s", "�� �����");
		gotoxy(x + 6 * (garo + 1), y);
		printf("%12s", "�� ��");
		key = gotoCursor(4, 1, 1, 5);
		if (key == 0) {/*0�� ĭ�� ���ý� - �����Լ� ���ý�*/
			reserve(tableInfo);/*���� �Լ��� �̵�*/
		}
		else if (key == 1) {
			party(tableInfo);
		}
		else if (key == 2) {
			totalSell();
		}
		else if (key == 3) {/*�ý��� ���� ���ý�*/
			gotoxy(2, 50);
			exit(1);/*���α׷� ����*/
		}
	}
}