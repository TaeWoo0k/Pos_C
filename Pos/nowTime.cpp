#include"Header.h"
void nowTime()/*���� �ð��� �д��� ������ ����� �Լ�*/
{
	time_t curr;
	struct tm* d;
	curr = time(NULL);
	d = localtime(&curr);
	gotoxy(1, 1);
	printf("�����\n");
	printf("%.16s", asctime(d));/*�� ���� ���� �ð��� �� �������� ���*/
}