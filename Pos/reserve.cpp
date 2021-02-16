#include"Header.h"
void reserve(Info* tableInfo)
{
	int hour, minute; // �ð�, ��
	int number = 0; //�ο���
	int yesNo;
	char key = 0;

	system("cls");
	nowTime();/*���� �ð� ���*/
	gotoxy(1, 5);
	printBox(5, 4, 1, 5);
	printNum(5, 4, 1, 5, tableInfo);
	key = gotoCursor(5, 4, 1, 5);
	if (key == 27) {/*ESC�Է½� ����*/
		return;
	}
	if (tableInfo[key].purpose == 0) {/*���õ� ���̺��� ���༮�� �ƴ� ���. ��, ���� ������ ���*/
		printBox3(22, 15, 40, 15);
		gotoxy(44, 20);
		printf("���� �ð��� �Է��Ͻÿ� :  ");
		scanf("%d %d", &hour, &minute);/*�ð��� ���� ����*/
		gotoxy(44, 21);
		printf("���� �ο����� �Է½ÿ� : ");
		scanf("%d", &number);
		gotoxy(44, 25);
		printf("���� �ð� %02d:%02d\n", hour, minute);/*����� �ð��� �ο����� ���*/
		gotoxy(44, 26);
		printf("%d�� ���̺� ���� �ο��� : %d", key + 1, number);
		tableInfo[key].purpose = 2;/*���̺��� ���¸� '����'���� ����*/
		tableInfo[key].number = number;/*�ο����� �Էµ� �ο����� ����*/
		tableInfo[key].hour = hour;/*�ð��� ���� �Էµ� ������ ����*/
		tableInfo[key].minute = minute;
		getch();
	}
	else if (tableInfo[key].purpose == 2) {/*���õ� ���̺��� ���༮�� ���. ��, ��������� ���*/
		printBox3(22, 10, 40, 15);
		gotoxy(44, 20);
		printf(" ������ ����Ͻðڽ��ϱ�?");
		printBox(2, 1, 41, 28);
		gotoxy(44, 30);
		printf("%12s", "��");
		gotoxy(44 + 2 * (garo + 1), 30);
		printf("%12s", "�ƴϿ�");
		yesNo = gotoCursor(2, 1, 41, 28);
		if (yesNo == 0) {
			tableInfo[key].purpose = 0;/*���̺��� ���¸� '�̻��'���� ����*/
			tableInfo[key].number = 0;/*����Ǿ��� �ο����� 0���� �ʱ�ȭ*/
			tableInfo[key].hour = 0;/*����Ǿ��� �ð��� ���� 0���� �ʱ�ȭ*/
			tableInfo[key].minute = 0;
		}
		else if (key == 27) {/*ESC�� �Է¹��� ���*/
			return;/*�Լ��� ����*/
		}
	}
	else if (tableInfo[key].purpose == 1 || tableInfo[key].purpose == 3 || tableInfo[key].purpose == 4) {/*������ ���̺��� ������� ���*/
		printBox3(22, 10, 40, 15);/*22x10 ũ���� �簢�� 1���� 40, 15 ��ġ�� ����*/
		gotoxy(44, 20);
		printf(" �̹� ������� ���̺� �Դϴ�.");/*������� ���̺��̶� ����ϰ� ����*/
		getch();
	}
}