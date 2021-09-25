#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"



//��ʼ������
 void InitBoard(char board[ROWS][COLS], int row, int col,char set)
{
	 int i, j;
	 for (i = 0; i < row; i++)
	 {
		 for (j = 0; j < col; j++)
		 {
			 board[i][j] = set;
		 }

	 }

}

 //�����ʾ����
 void DisplayBoard(char board[ROWS][COLS], int row, int col)
 {
	 int i, j;
	 printf("����ɨ����Ϸ-����\n");
	 for (i = 0; i <= col; i++)
	 {
		 printf("%d ", i);
	 }
	 printf("\n");
	 for (i = 1; i <= row; i++)
	 {
		 printf("%d", i);
		 for (j = 1; j <= col; j++)
		 {
			 printf(" %c", board[i][j]); 
		 }
		 printf("\n");
		 
	 }
	 printf("����ɨ����Ϸ������\n");
 }

 //������

 void setmine(char board[ROWS][COLS], int row, int col)
 {
	 int count = EASY_COUNT;
	 
	 while (count)
	 {
		 int x = rand() % row + 1;
		 int y= rand() % col + 1;
		 if (board[x][y] == '0')
		 {
			 board[x][y] = '1';
			 count--;
		 }

	 }
 }

 //ɨ��
static int get_mine_count(char mine[ROWS][COLS],int x ,int y )
 {
	 return mine[x - 1][y - 1]
		+ mine[x - 1][y]
		+ mine[x - 1][y + 1]
		 + mine[x][y - 1]
		+ mine[x][y + 1]
		 + mine[x + 1][y - 1]
		+ mine[x + 1][y]
		+ mine[x + 1][y + 1]
		 -8*'0';
 }

 void finemine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
 {
	 int x = 0;
	 int y = 0;
	 int win =0 ;
	 while (win < row * col - EASY_COUNT)
	 {

		 printf("���������꣺��");
		 scanf("%d %d", &x, &y);

		 if (x > 0 && x <= row && y >= 0 && y <= col)
		 {
			 if (mine[x][y] == '1')
			 {
				 printf("��ϲ�㣬�ȵ����ˣ���Ϸ����\n");
				 DisplayBoard(mine, ROW, COL);
				 break;
			 }
			 else
			 {
				 int count = get_mine_count(mine, x, y);
				 show[x][y] = count + '0';
				 DisplayBoard(show, ROW, COL);
				 win++;
			 }

		 }
		 else
		 {
			 printf("���겻�Ϸ�������������\n");
		 }
	 }
	 if (win== row * col - EASY_COUNT)
	 {
		 printf("���׳ɹ���ţ��\n");
		 DisplayBoard(mine, ROW, COL);
	 }
 }

 