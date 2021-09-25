#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10


//初始化界面
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);

//输出显示界面
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//布置雷
void setmine(char board[ROWS][COLS], int row, int col);

//扫雷
void finemine(char mine[ROWS][COLS], char [ROWS][COLS],int row, int col);