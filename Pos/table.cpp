#include"Header.h"

int table(Info* tableInfo)/*���̺� ĭ ��°� ���༮���� ���θ� �Ǵ��Ͽ� �� ���̺����� Ȯ�ǽ� �Ǹ� �ο����� �Է¹ް� ���� �Լ��� �Ѿ
						   ���̺� �Լ�. �����Լ��κ��� ����ü tableInfo�� �޾ƿ´�.*/
{
	int tableNum = 0;/*gotoCursor�� ���� ��ȯ�� ���� ������ ����*/
	int number = 0;/*�ο����� �Է¹��� �� �� ����. 0���� �ʱ�ȭ �Ǿ� �ִ�.*/

	for (; number == 0;)/*�ο����� �Է��Ͽ� �����ϱ� �� ���� �ݺ�*/
	{
		system("cls");
		nowTime();/*���� �ð� ���*/
		gotoxy(1, 5);
		printBox(5, 4, 1, 5);/*���� 5ĭ, ���� 4ĭ�� �ڽ��� x��ǥ 1, y��ǥ 5 ��ġ���� ���� ����*/
		printNum(5, 4, 1, 5, tableInfo);/*���� 5ĭ, ���� 4ĭ�� �ڽ��� x��ǥ 1, y��ǥ 5 ��ġ�������� 1���� 20(5*4)���� �ѹ���*/
		tableNum = gotoCursor(5, 4, 1, 5);
		if (tableNum == 27) {
			return 27;
		}
		else {
			if (tableInfo[tableNum].purpose == 0)/*�ش� ���̺��� �� ���̺��� ���*/
			{
				printBox3(22, 15, 40, 15);
				gotoxy(44, 20);
				printf("�ο����� �Է��Ͻÿ� : ");
				scanf("%d", &number);
				if (number <= 0 || 6 < number) {/*0�� ���ϰų� 6�� �ʰ��� ���*/
					gotoxy(44, 22);
					printf("�� ���̺��� �ο��� 6���� �ʰ��� �� �����ϴ�.");
					number = 0;
					Sleep(900);/*0.9�� ���� ����*/
				}
				else {/*�ο����� �˸°� �Է��� ���*/
					gotoxy(44, 25);
					printf("%d�� ���̺��� �ο����� %d�� �Դϴ�.", tableNum + 1, number);/*�ο����� �Է¹ް� ����*/
					Sleep(1000);
				}
			}
			else if (tableInfo[tableNum].purpose == 1) {/*�ش� ���̺��� ������� ���̺��� ���*/
				number = tableInfo[tableNum].number;/*������̶�� ���� �ο����� ���� �Ǿ��ٴ� ���̴�. �̶� �ο����� �޾ƿ��� �ݺ����� ����ȴ�*/
			}
			else if (tableInfo[tableNum].purpose == 2)/*�ش� ���̺��� ���༮�� ���*/
			{
				printBox3(22, 15, 40, 15);/*22*15ũ���� �ڽ��� 40, 15 ��ġ�� �ϳ� ����*/
				gotoxy(44, 20);
				printf("����� ���̺� �Դϴ�.");/*���༮���� ����ϰ� 1�ʵ��� ����*/
				Sleep(1000);
			}
			else if (tableInfo[tableNum].purpose == 3)/*�ش� ���̺��� ��ü�� ������� ���*/
			{
				tableNum = tableInfo[tableNum].masterParty;/*���̺� ��ȣ�� '��ü ������' ���̺� ��ȣ�� �޾ƿ�. �̴� ���� ��ü ������ �� �η��� ������ ������ ����� �Ǵ� ���� �����ϱ� ����*/
				printBox3(22, 15, 40, 15);/*22*15ũ���� �ڽ��� 40,15 ��ġ�� ����*/
				gotoxy(44, 20);
				printf("�ο����� �Է��Ͻÿ� : ");/*�ο����� �Է��϶�� ����� �� �Է¹���*/
				scanf("%d", &number);
				gotoxy(55, 25);
				printf("<  ��ü  >");
				gotoxy(44, 26);
				printf("���̺��� �ο����� %d�� �Դϴ�.", number);/*�ο����� �Է¹ް� ����*/
				Sleep(1000);
			}
			else if (tableInfo[tableNum].purpose == 4) {/*������� ��ü ���̺��� ���*/
				tableNum = tableInfo[tableNum].masterParty;/*���̺� ��ȣ�� '��ü ������' ��ȣ��, */
				number = tableInfo[tableNum].number;/*�ο����� �ش� ���̺� ����� �ο����� �޾ƿ�*/
			}
		}
		system("cls");
	}
	return (100 * number + tableNum);/*�ο����� ���̺� ��ȣ���� ���갪�� ��ȯ��. �� ���� �� ���� return �� �� ���� ������ �� ����� ����*/
}