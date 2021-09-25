#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu()
{
	printf("*******************\n");
	printf("*****  1.play   ***\n");
	printf("*****  0.exit   ***\n");
	printf("*******************\n");
}

void game()
{
	char mine[ROWS][COLS] = {0};//存放雷的信息(布置雷)
	char show[ROWS][COLS] = {0};//存放周围有多少雷 的信息
	//初始化界面
	InitBoard(mine, ROWS, COLS,'0'); 
	InitBoard(show, ROWS, COLS,'*');

	//输出显示界面
	DisplayBoard(show,ROW,COL);
	
	//布置雷

	setmine(mine, ROW, COL);
	//DisplayBoard(mine,ROW,COL);

	//扫雷
	finemine(mine,show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{ 
		menu();
		printf("请选择：>\n");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				game();//扫雷游戏
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
		}

	} while (input);
	return 0;
}