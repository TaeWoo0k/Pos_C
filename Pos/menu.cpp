#include"Header.h"
int menu(int number, int tableNum, Info* tableInfo)/*�޴����� ����Ͽ� �� �� �մ��� ���ϴ� �޴��� �����Ͽ� ����, ����� �Լ�.*/
{
	int i, j, k, p, q = 0, r, key;
	int a, b, x = 3, y = 7;
	int sign = 0, location = 0;
	Stat myStat;
	myStat.totalCoast = 0; // ������ ���� �Ѿ�
	myStat.sizeofMenu[13]; // ������ ���� �޴� ����
	int i_umc, i_lmc;/*int_UpperMenuCategory :  ���� �޴� ī�װ����� ���õ� ī�װ��� ��ȣ
					 int_LowerMenuCategory : ���� �޴� ī�װ����� ���õ� ī�װ��� ��ȣ*/
	int paragraph = 0;/*�ܶ�. ���⼭�� �� paragraph�� ���� ���� ���� ������, �̵� ������ ������ �޶�����.
					  paragraph = 0 : ���� �޴� ī�װ��� ������ �����ϴ�.
					  paragraph = 1 : ���� �޴� ī�װ��� ������ �����ϴ�.
					  paragraph = 2 : ���ݱ��� ���õ� �޴����� ����Ʈ �κп� ������ �����ϴ�.
					  paragraph = 3 : "�ֹ� �Ϸ�"�� �����ϱ� ���� ���̴�.
					  paragraph = 4 : �޴��Լ��� �ݺ��� ���� �˸���, ���� �Լ��� ���������� �Ѿ �غ� ���� ���Ѵ�.*/
	char UMC[um][14] = { { "����" }, { "����/�ַ�" }, { "�Ľ�" } };/*UpperMenuCategory. ���� �޴� ī�װ� �̴�.*/
	char LMC[um][lm][13] = {
		{ "����", "������", "�ɵ��", "��â��", "���ű��" },
		{ "�ݶ�", "���̴�", "��ȭ��", "����", "����" },
		{ "�����", "���ø�", "����ø�" }
	};/*LowerMenuCategory, ���� �޴� ī�װ��μ�, ���� ���� �޴��鿡 ���ӵ� �޴����̴�.*/
	int menuCoast[um][lm] = {
		{ 9000, 12000, 30000, 13000, 10000 },
		{ 1500, 1500, 3000, 3000, 4000 },
		{ 3000, 4500, 4500 } };/*�� �޴����� ������ ����*/

	system("cls");
	nowTime();
	gotoxy(20, 1);
	printf("���̺� ��ȣ : %d", tableNum + 1);
	gotoxy(20, 2);
	printf("�ο��� : %d ��", number);
	printBox(3, 1, 1, 5);/*���� �޴� ĭ�� ���*/
	printBox(5, 1, 1, 18);/*���� �޴� ĭ�� ���*/
	printBox(1, 1, 80, 39);
	gotoxy(84, 41);
	printf("\t���ÿϷ�");
	do
	{
		switch (paragraph)
		{
		case 0:/*���� �޴� ī�װ� ����*/
			a = x;
			b = y;
			for (i = 0; i < 3; i++)
			{
				gotoxy(a, b);
				printf("%12s", UMC[i]);/*�̸� �����ص� ���� ī�װ� �̸����� ����Ѵ�*/
				a += 2 * (garo + 1);
			}
			a = x - 2;
			b = y + 13 * 2;
			k = 0;
			gotoxy(a, b);
			for (i = 0; i < um; i++) {/*���õ� �޴��� ������ŭ �ݺ�*/
				for (j = 0; j < lm; j++) {
					if (tableInfo[tableNum].menuList[i][j] != 0) {
						k++;
						q = k > q ? k : q;
						printf("\t%9s\t", LMC[i][j]);/*���õ� ���� �޴����� ����Ѵ�.*/
						printf("%4d��\t", tableInfo[tableNum].menuList[i][j]);/*���õ� ���� �޴��� ���� ���*/
						printf("%7d��\n", tableInfo[tableNum].menuList[i][j] * menuCoast[i][j]);/*���õ� �����޴��� ���� ���*/
					}
				}
			}
			for (r = k; r < q; r++) {/*�޴��� ��Ҹ� ���ؼ� ���� ��µǴ� ���� ���� ���뺸�� ��� �ܻ��� ���� ���*/
				printf("\t\t\t\t\n");/*������ �����Ͽ� �����*/
			}
			i_umc = gotoCursor(3, 1, 1, 5);/*���� �޴��� �����Ѵ�.*/
			if (i_umc == 27) {
				return 27;
			}
			else {
				paragraph = 1;/*���� �޴� ������ ������ �ܶ��� 1, �� �����޴��� �̵���Ų��.*/
			}
		case 1:/*���� �޴� ī�װ� ����*/
			a = x;
			b = y + 13;
			for (i = 0; i < 5; i++)
			{
				gotoxy(a, b);
				printf("%10s", LMC[i_umc][i]);/*�̸� �����ص� ���� �޴� �̸����� ����Ѵ�.*/
				gotoxy(a, b + 2);
				if (menuCoast[i_umc][i] != 0) {
					printf("%10d", menuCoast[i_umc][i]);
				}
				else {
					printf("\t\t");
				}
				a += 2 * (garo + 1);
			}
			while (paragraph == 1)/*�ܶ��� ������ �����޴��� �ӹ��� ����� �ݺ���*/
			{
				i_lmc = gotoCursor2(5, 1, 1, 18);/*���� �޴� ī�װ��� ���� ������ ���� �Ѱܹ޴´�*/
				if (i_lmc == 27) {
					return 27;
				}
				else {
					fflush(stdin);
					if (i_lmc == 72)/*���� ȭ��ǥ ����Ű�� ���*/
					{
						paragraph = 0;/*�����޴��� �̵���Ų��.*/
					}
					else if (i_lmc == 80)/*�Ʒ� ȭ��ǥ ����Ű�� ���*/
					{
						paragraph = 2;/*���� �޴��� �̵���Ų��.*/
					}
					else if (0 <= i_lmc && i_lmc <= lm)/*�Ѱܹ��� ���� ���� �޴��� �ε��� �� �ϳ��� ���*/
					{
						tableInfo[tableNum].menuList[i_umc][i_lmc]++;
						a = x - 2;
						b = y + 13 * 2;
						k = 0;
						gotoxy(a, b);
						for (i = 0; i < um; i++) {/*���õ� �޴��� ������ŭ �ݺ�*/
							for (j = 0; j < lm; j++) {
								if (tableInfo[tableNum].menuList[i][j] != 0) {
									k++;
									q = k > q ? k : q;
									printf("\t%9s\t", LMC[i][j]);/*���õ� ���� �޴����� ����Ѵ�.*/
									printf("%4d��\t", tableInfo[tableNum].menuList[i][j]);/*���õ� ���� �޴��� ���� ���*/
									printf("%7d��\n", tableInfo[tableNum].menuList[i][j] * menuCoast[i][j]);/*���õ� �����޴��� ���� ���*/
								}
							}
						}
						for (r = k; r < q; r++) {/*�޴��� ��Ҹ� ���ؼ� ���� ��µǴ� ���� ���� ���뺸�� ��� �ܻ��� ���� ���*/
							printf("\t\t\t\t\n");/*������ �����Ͽ� �����*/
						}
					}
				}
			}
		case 2:/*���õ� �޴� ����Ʈ�� �����ϴ� ����*/
			a = x;
			b = y + 13 * 2;
			gotoxy(a, b);
			while (paragraph == 2) {
				key = gotoCursor3(1, k, a, b);
				if (key == 72) {/*�� ����Ű�� ���� �޴�, �Ʒ� ����Ű�� '���ÿϷ�' �� �̵�*/
					paragraph = 1;
				}
				else if (key == 80) {
					paragraph = 3;
				}
				else if (key == 27) {
					printf("\b ");
					paragraph = 3;
				}
				else if ((1000 <= key) && (key <= 3000)) {/*'+' �Ǵ� '-'�� �Է¹޾��� ���*/
					location = key % 1000;/*������ ���� ��ȯ�� ���� ���ڴ��Ͽ� n��° ��ġ�� ��ȣ�� ���� ����*/
					sign = key / 1000;
					p = 0;
					for (i = 0; i < um && p <= location; i++) {/*���õ� �޴����� n��° (location�� ��ŭ)�� �޴��� ����*/
						for (j = 0; j < lm && p <= location; j++) {
							if (tableInfo[tableNum].menuList[i][j] != 0) {
								p++;
							}
						}
					}
					i--;
					j--;
					if (sign == 2) {/*'+'�� ���*/
						tableInfo[tableNum].menuList[i][j]++;/*������ ����������*/
					}
					else if (sign == 1) {/*'-'�� ���*/
						if (tableInfo[tableNum].menuList[i][j] > 0) {/*������ ���ҽ�����*/
							tableInfo[tableNum].menuList[i][j]--;
						}
					}
				}
				a = x - 2;
				b = y + 13 * 2;
				k = 0;
				gotoxy(a, b);
				for (i = 0; i < um; i++) {/*���õ� �޴��� ������ŭ �ݺ�*/
					for (j = 0; j < lm; j++) {
						if (tableInfo[tableNum].menuList[i][j] != 0) {
							k++;
							q = k > q ? k : q;
							printf("\t%9s\t", LMC[i][j]);/*���õ� ���� �޴����� ����Ѵ�.*/
							printf("%4d��\t", tableInfo[tableNum].menuList[i][j]);/*������ ���ݵ� ���*/
							printf("%7d��\n", tableInfo[tableNum].menuList[i][j] * menuCoast[i][j]);
						}
					}
				}
				for (r = k; r < q; r++) {
					printf("\t\t\t\t\t\t\n");
				}
			}
		case 3:/*'���� �Ϸ� â*/
			gotoxy(80, 39);
			while (paragraph == 3)
			{
				key = gotoCursor2(1, 1, 80, 39);
				switch (key)
				{
				case 27:/*ESC�̸� ���� �Լ��� �̵�*/
					return 27;
				case 72:/*�� ����Ű�̸� '���õ� �޴� ����Ʈ'�� �̵�*/
					paragraph = 2;
					break;
				case 0:/*���͸� ���� ��� �ݺ� ������ �Ҹ����� ���� �ݺ����� ����*/
					paragraph = 4;
					break;
				case 80:/*�Ʒ� ����Ű�� ���� ��� �ݺ� ������ �Ҹ����� ���� �ݺ����� ����*/
					paragraph = 4;
					break;
				}
			}
		}
	} while (paragraph != 4);/*�� �ݺ��� ��� �ֹ��� �Ϸ�� �� ���� �ݺ�*/




	printBox3(22, 10, 40, 15);
	gotoxy(44, 20);
	printf("����� �����Ͻðڽ��ϱ�?");
	printBox(2, 1, 41, 28);
	gotoxy(44, 30);
	printf("%12s", "��");
	gotoxy(44 + 2 * (garo + 1), 30);
	printf("%12s", "�ƴϿ�");
	key = gotoCursor(2, 1, 41, 28);



	tableInfo[tableNum].totalCoast = 0;/*�ش� ���̺��� �Ѿ��� �ʱ�ȭ*/
	tableInfo[tableNum].sizeofMenu = 0;/*�ش� ���̺��� �޴� �������� �ʱ�ȭ*/
	tableInfo[tableNum].number = number;/*�ش� ���̺��� �ο����� �ԷµǾ��� �ο����� ����*/
	if (tableInfo[tableNum].purpose == 0) {/*���̺� ��� ������ '�� ���̺�' �� ���*/
		tableInfo[tableNum].purpose = 1;/*������� ���̺�� ������ ����*/
	}
	else if (tableInfo[tableNum].purpose == 3) {/*���̺��� ��� ������ '��ü' �� ���*/
		tableInfo[tableNum].purpose = 4;/*������� ��ü ���̺�� ���� ����*/
	}
	for (i = 0; i < um; i++) {
		for (j = 0; j < lm; j++) {
			tableInfo[tableNum].totalCoast += menuCoast[i][j] * tableInfo[tableNum].menuList[i][j];/*�ش� ���̺��� �Ѿ��� ����*/
			myStat.totalCoast += tableInfo[tableNum].totalCoast;                                 // ���������� ����ü�� �Ѿ� ����
			if (tableInfo[tableNum].menuList[i][j] != 0) {/*�ֹ��� �޴��� ������ 0�� �ƴ� ���, �� �ֹ��� 1�� �̻� �� ���*/
				tableInfo[tableNum].sizeofMenu++;/*�ֹ��� �޴��� ���� ���� �߰�*/
				myStat.sizeofMenu[i * 5 + j]++; // ������ ���� �޴��� ���� ����
			}
		}
	}




	if (key == 27) {/*ESC ������ ��� 27 ��ȯ*/
		return 27;
	}
	else if (key == 0) {/*'��'�� �ǹ��ϴ� 0 ������ ��� 0 ��ȯ*/
		return 0;
	}
	else { /*'�ƴϿ�'�� �ǹ��ϴ� 1 ������ ��� 1 ��ȯ*/
		return 1;
	}
}
