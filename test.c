#define _CRT_SECURE_NO_WARNINGS 

#include"contact.h"  // �����Լ�������ͷ�ļ�ʹ�õ���˫���š��� 

void menu()
{
	printf("***************************\n");
	printf("***** 1.add    2.del  *****\n");
	printf("***** 3.modify 4.ser  *****\n");
	printf("***** 5.sort   6.pri  *****\n");
	printf("*****      0.exit     *****\n");
	printf("***************************\n");
	printf("��ѡ��->");
	
}
//ö�ٳ���
enum option
{
	EXIT,
	ADD,
	DEL,
	MODIFY,
	SER,
	SORT,
	PRI
};//��������֮���ö��Ÿ���

int main()
{
	Contact con;//����һ��ͨѶ¼
	int input = 0;
	InitContact(&con);
	do
	{
		menu();	
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Addpeoinfo(&con);
			break;
		case DEL:
			Delpeoinfo(&con);
			break;
		case MODIFY:
			Modpeoinfo(&con);
			break;
		case SER:
			Serpeoinfo(&con);
			break;
		case SORT:
			break;
		case PRI:
			Pricontact(&con);
			break;
		case EXIT:
			DestoryContact(&con);
			break;
		default:
			printf("ѡ�����������ѡ��\n");
		}
	} while (input);
	return 0;
}