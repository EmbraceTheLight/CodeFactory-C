//介绍：扫雷，分了三项，SL.h，扫雷.c，test.c（比鹏哥的更好，因为实现了他没有实现的一消一大片的功能。其中有些代码稍有更改），不过效率可能不太高。现在使用ACV（Ctrl+A Ctrl+C Ctrl+V）大法：
//********************************
//**************SL.h**************
//********************************
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2                              //当排查的位置处于边界时如果还是9X9的数组就会越界（边界之外没有定义）所以上下各增加一行，左右各增加一列，就避开了这个问题
#define Count 10                                //雷的个数,可以自己调
void Initboard(char board[ROWS][COLS], int rows, int cols, char set);
void displayboard(char board1[ROWS][COLS], int row, int col);
void setbomb(char board2[ROWS][COLS], int row, int col);
void search(char board[ROWS][COLS], char show[ROWS][COLS], int row, int  col);
void tongji(char board[ROWS][COLS],char show[ROWS][COLS], int x, int y,int iswin);
int scan(char show[ROWS][COLS], int row, int col);

//**********************************
//**************扫雷.c**************
//**********************************
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "SL.h"
int iswin = 0;
void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}
void displayboard(char board1[ROWS][COLS], int row, int col)
{
	int i, j;
	//打印列号
	printf("  ");
	for (i = 1; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		//打印行号
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board1[i][j]);
		}
		printf("\n");
	}
}
void setbomb(char board2[ROWS][COLS], int row, int col)
{
	int count = Count;
	while (count)
	{
		int i = rand() % row+1;//rand()随机数取值范围0-RAND-MAX，与编译器有关，最少为32767.rand（）% row（row值为9），rand（）% 9的范围为0-8，要想i的值为1-9，需要+1）
		int j = rand() % 9 + 1;
		if (board2[i][j] == '0')
		{
			board2[i][j] = '1';
			count--;//布置一个雷，减去1，直到count为0
		}
	}
}
void search(char board[ROWS][COLS], char show[ROWS][COLS], int row, int  col)
{	
	displayboard(show, ROW, COL);
	int x,y;
	while (iswin<row*col-Count)//Count表示雷的个数，row*col则是总的格子数
	{
		printf("输入排雷的坐标：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x][y] == '1')//踩雷
			{
				printf("YOU DIED!\n");
				displayboard(board, row, col);
				break;
			}
			else
			{
				tongji(board, show, x, y, iswin);
				iswin = scan(show, ROW, COL);			
			}
		}	
		else
		{
			printf("坐标非法，请重新输入");
		}
		if (iswin == row * col - Count)//可能有中途失败的情况，导致iswin<row*col-Count
		{
			printf("YOU WIN!\n");
			displayboard(show, ROW, COL);
			displayboard(board, row, col);
		}
	}
}
void tongji(char board[ROWS][COLS],char show[ROWS][COLS], int x, int y,int iswin)
{
	if (show[x][y] !='*') return;//避免重复搜索
	int count;
	
	count=board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + board[x][y - 1] + board[x][y + 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0';
	//统计周围8个格子的bomb个数。字符转数字：‘1’-‘0’=1；‘0’-‘0’=0，8个格子，每个减去一个‘0’，一共减去8个‘0’，这个是合在一起之后的写法，不用再减8次‘0’了。
	show[x][y] = count + '0';//数字转字符
	if (count == 0&&x<=ROW&&x>=1&&y<=COL&&y>=1)//递归搜索周围的一片区域
	{
		show[x][y] = ' ';	
			tongji(board, show, x - 1, y - 1, iswin);
			tongji(board, show, x - 1, y, iswin);
			tongji(board, show, x - 1, y + 1, iswin);
			tongji(board, show, x, y - 1, iswin);
			tongji(board, show, x, y + 1, iswin);
			tongji(board, show, x + 1, y - 1, iswin);
			tongji(board, show, x + 1, y, iswin);
			tongji(board, show, x + 1, y + 1, iswin);
	}
	displayboard(show, ROW, COL);
}
int scan(char show[ROWS][COLS], int row, int col)
{
	int i, j;
	int count = 0;
	for (i = 1; i <= row;i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] != '*') count++;
		}
	}
	return count;
}


*****************************************
*****************test.c******************
*****************************************
#define _CRT_SECURE_NO_WARNINGS 1
#include"SL.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
void menu()
{
	printf("******************************************************************\n");
	printf("***************            1.play            *********************\n");
	printf("***************            0.exit            *********************\n");
	printf("******************************************************************\n");
}
void game()
{
	                                                          
	char board[ROWS][COLS] = { 0 };                            //board[][]用来存储地雷(9X9大小），即布置好的雷的信息
	                                                          
	char show[ROWS][COLS] = { 0 };
	                                                           //show[][]存放并显示排查出来的地雷的信息（周围有几个雷）
	Initboard(board,ROWS ,COLS,'0');                           //初始化
	Initboard(show, ROWS, COLS, '*');
  //displayboard(board,ROW,COL);
  //displayboard(show, ROW, COL);测试用的打印
	
	setbomb(board,ROW,COL);                                    //放雷：board为11X11的表格，实际需要9X9（第一行第一列到第九行第九列）
	//displayboard(board, ROW, COL);
	//扫雷过程
	search(board,show,ROW,COL);
}
void test()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("Please sselect(1 or 0):");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit\n");
			break;
		default:
			printf("select error!select again!\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}

