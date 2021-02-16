#include"Header.h"
void printNum(int width, int length, int x, int y, Info* tableInfo)/*��µ� �� ���̺� ĭ�� ��ȣ, ������, �ֹ����� ���� ����� �Լ�*/
{
	int i, j, k, p, q, r, s;
	int a = x, b = y;/*x,y ��ǥ�� a, b�� ����*/
	int xy;/*x, y ��ǥ�� ������ ���ؼ� n��° ���̺� �ε����� ��Ÿ�� ����*/
	char LMC[um][lm][13] = {
		{ "����", "������", "�ɵ��", "��â��", "���ű��" },
		{ "�ݶ�", "���̴�", "��ȭ��", "����", "����" },
		{ "�����", "���ø�", "����ø�" }/*�޴��� �̸��� �ʱ�ȭ*/
	};
	a += 2;/*�ʱ� Ŀ�� ��ġ ����*/
	b++;
	gotoxy(a, ++b);
	for (i = 0; i < length; i++) {/*���� x ���� �� ��ŭ �ݺ�*/
		for (j = 0; j < width; j++) {
			xy = j + i * 5;/*x, y ��ǥ�κ��� �ε����� ����*/
			printf("  %d", xy + 1);/*���̺� ��ȣ ���*/
			if (tableInfo[xy].purpose == 1 || tableInfo[xy].purpose == 4) {
				/*������̰ų� ��ü ���̺�� ������� ���*/
				if (tableInfo[xy].purpose == 4) {/*��ü ���̺�� ������� ��� ����� ����*/
					gotoxy(a + 8, b);
					printf("��ü %d", tableInfo[xy].partyInfo);/*n��° ��ü ���̺����� �ǹ�*/
					gotoxy(a + 2, b + 1);
					setColor((tableInfo[xy].partyInfo) * 16, 15);/*n��° ��ü ���̺� 16�� ���� ���� ��� ����� ����*/
					for (k = 0; k < 8; k++) {
						printf("\t\t      ");/*������ ���� ĥ��*/
						gotoxy(a + 2, b + 2 + k);
					}
				}
				gotoxy(a + 2, b + 1);
				printf("%d��", tableInfo[xy].totalCoast);/*�Ѿ��� ���*/
				gotoxy(a + 2, b + 2);
				printf("%d��", tableInfo[xy].number);/*�ο����� ���*/
				for (p = um - 1; p >= 0; p--) {/*���� �޴� ���� ��ŭ �ݺ��ϵ�, ���� ������ ���� ������ ��ȭ*/
					for (q = lm - 1; q >= 0; q--) {/*���� �޴� ���� ��ŭ �ݺ��ϵ�, ���� ������ ���� ������ ��ȭ*/
						if (tableInfo[xy].menuList[p][q] != 0) {/*�ֹ��� ������ �����Ͽ�, ������ 0�� �ƴ� ���*/
							r = p; /*�ε��� p�� r�� ����*/
							s = q;/*�ε��� q�� s�� ����*/
						}/*�� �ݺ����� ���ؼ� �ֹ��� ������ �߿��� ���� ���� �޴� ��ȣ�� ���� ������ �����س�
						 ���� �̰��� ���ؼ� ��µ� tableĭ�� ���� ���� �޴� ��ȣ�� ���� �޴��� ��µ� ����*/
					}
				}
				gotoxy(a + 2, b + 3);
				printf("%.8s �� %d��", LMC[r][s], tableInfo[xy].sizeofMenu - 1);/*�ֹ��� �޴� �߿��� ���� ���� �޴� ��ȣ�� ���� �޴� �̸��� ��µǰ�, �ֹ��� �޴��� ���� ���� ���*/
				setColor(240, 0);/*������ ������� ����*/
			}
			else if (tableInfo[xy].purpose == 2) {/*���༮�� ���*/
				gotoxy(a + 8, b);
				printf("���� %02d:%02d", tableInfo[xy].hour, tableInfo[xy].minute);/*���༮���� ����ϰ� �ð��� ���*/
			}
			else if (tableInfo[xy].purpose == 3) {/*�� ��ü ���̺��� ���*/
				gotoxy(a + 8, b);
				printf("��ü %d", tableInfo[xy].partyInfo);/*������ ��ü ��ȣ�� ���*/
				gotoxy(a + 2, b + 1);
				setColor((tableInfo[xy].partyInfo) * 16, 0);/*��� ���� ������ ��ü ��ȣ�� 16�� ���� ������ ����*/
				for (k = 0; k < 8; k++) {
					printf("\t\t      ");/*������ ĥ��*/
					gotoxy(a + 2, b + 2 + k);
				}
				setColor(240, 0);/*���� ������� ����*/
			}
			a += 2 * garo + 2;
			gotoxy(a, b);
		}
		a = x + 2;/*Ŀ�� ��ġ�� ������*/
		b += sero + 1;
		gotoxy(a, b);
	}
}