
#include"Header.h"
int bill(int number, int tableNum, Info* tableInfo)
{
	int i, j, key;
	int innerMoney = 0;
	int totalCoast = 0;
	int sizeofMenu = 0;
	char LMC[um][lm][13] = {
		{ "����", "������", "�ɵ��", "��â��", "���ű��" },
		{ "�ݶ�", "���̴�", "��ȭ��", "����", "����" },
		{ "�����", "���ø�", "����ø�" }
	};/*�޴��� �̸��� ����*/
	int menuCoast[um][lm] = {
		{ 9000, 12000, 30000, 13000, 10000 },
		{ 1500, 1500, 3000, 3000, 4000 },
		{ 3000, 4500, 4500 } };/*�޴��� ������ ����*/

	for (i = 0; i < um; i++) {
		for (j = 0; j < lm; j++) {
			if (tableInfo[tableNum].menuList[i][j] != 0) {
				totalCoast += (menuCoast[i][j] * tableInfo[tableNum].menuList[i][j]);
			}/*�Ѿ��� ����*/
		}
	}
	time_t curr;
	struct tm* d;
	curr = time(NULL);
	d = localtime(&curr);

	system("cls");
	printf("�����\n");
	while (innerMoney < totalCoast) {/*�ݾ��� �Է¹޴� �κ�*/
		printf("�� �� : %d\n���� �� : ", totalCoast);
		scanf("%d", &innerMoney);
		if (innerMoney < totalCoast) {
			printf("�ݾ��� �����ϴ�.\n");
		}
		else {
			printf("������ : %d\n", innerMoney);
		}
	}
	printf("�Ž��� �� : %d\n", innerMoney - totalCoast);
	printBox(1, 1, 5, 20);
	gotoxy(7, 21);
	printf("��������");/*������ ����� ���� �κ�*/
	gotoxy(7, 22);
	printf("����Ͻðڽ��ϱ�?");
	printBox(2, 1, 5, 34);
	gotoxy(9, 36);
	printf("��");
	gotoxy(34, 36);
	printf("�ƴϿ�");
	key = gotoCursor(2, 1, 5, 34);
	if (key == 27) {/*ESC�� ��� ���� �Լ��� �̵�*/
		return 27;
	}
	else if (key == 0) {
		system("cls");
		for (i = 0; i < um; i++) {
			for (j = 0; j < lm; j++) {
				if (tableInfo[tableNum].menuList[i][j] != 0) {
					sizeofMenu++;/*�ֹ��� ��ü �޴��� ���� ���*/
				}
			}
		}
		tableInfo[tableNum].sizeofMenu = sizeofMenu;
		printBox3(18, 25 + sizeofMenu, 33, 5);
		gotoxy(39, 8);
		printf("%19s", "�����");/*���� ���� ���*/
		gotoxy(39, 10);
		printf("�����No:123-45-67890");
		gotoxy(39, 11);
		printf("%30s", "��ǥ : ���̹�");
		gotoxy(39, 12);
		printf("��� �Ⱦ�� ���ȱ� ������з� 8");
		gotoxy(39, 13);
		printf("Tel:031-464-3392");
		gotoxy(39, 14);
		printf("-------------------------------");
		gotoxy(39, 15);
		printf("%-10s%-5s%6s%10s", "ǰ  ��", "�� ��", "�� ��", "�� ��"); /*�׸� ���*/
		gotoxy(39, 16);
		printf("-------------------------------");
		sizeofMenu = 0;
		for (i = 0; i < um; i++) {
			for (j = 0; j < lm; j++) {
				if (tableInfo[tableNum].menuList[i][j] != 0) {
					sizeofMenu++;
					gotoxy(39, 16 + sizeofMenu);
					printf("%-10s%5d%5d%11d", LMC[i][j], menuCoast[i][j], tableInfo[tableNum].menuList[i][j], menuCoast[i][j] * tableInfo[tableNum].menuList[i][j]);
				}/*ǰ��, �ܰ�, ����, �ݾ� ���*/
			}
		}
		gotoxy(39, sizeofMenu + 17);
		printf("-------------------------------");
		gotoxy(39, sizeofMenu + 18);
		printf("%-20s%11d", "�� ��", totalCoast);
		gotoxy(39, sizeofMenu + 19);
		printf("%-20s%11d", "�� ��", innerMoney);
		gotoxy(39, sizeofMenu + 20);
		printf("%-20s%11d", "���� ��", innerMoney);
		gotoxy(39, sizeofMenu + 21);
		printf("%-20s%11d", "�Ž��� ��", innerMoney - totalCoast);
		gotoxy(39, sizeofMenu + 22);
		printf("-------------------------------");
		gotoxy(39, sizeofMenu + 24);
		printf("%21s", "�����մϴ�");
		gotoxy(39, sizeofMenu + 26);
		printf("%s", asctime(d));
		gotoxy(39, sizeofMenu + 28);
		printf("���̺� ��ȣ : %2d", tableNum + 1);
		gotoxy(39, sizeofMenu + 29);
		printf("�ο��� : %2d\n\n", number);
		fflush(stdin);
		getch();
	}
	return 0;
}
