#define _CRT_SECURE_NO_WARNINGS 

#include"contact.h"  // 引用自己创建的头文件使用的是双引号“” 

void menu()
{
	printf("***************************\n");
	printf("***** 1.add    2.del  *****\n");
	printf("***** 3.modify 4.ser  *****\n");
	printf("***** 5.sort   6.pri  *****\n");
	printf("*****      0.exit     *****\n");
	printf("***************************\n");
	printf("请选择：->");
	
}
//枚举常量
enum option
{
	EXIT,
	ADD,
	DEL,
	MODIFY,
	SER,
	SORT,
	PRI
};//各个常量之间用逗号隔开

int main()
{
	Contact con;//创建一个通讯录
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
			printf("选择错误，请重新选择\n");
		}
	} while (input);
	return 0;
}