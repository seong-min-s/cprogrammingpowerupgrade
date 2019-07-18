#include "blockInfo.h"
#include<time.h>
#include "point.h"
#include "keyCurControl.h"
#include "common.h"
//#include "boardInfo.h"
extern int boardInfo[11][12];

static int currentBlockModel;
static int rotateSte;
static int curPosX, curPosY;

enum{LEFT,RIGHT,UP,DOWN};

void InitNewBlockPos(int x, int y)
{
	if (x < 0 || y < 0)
		return 0;

	curPosX = x;
	curPosY = y;

	SetCurrentCursorPos(x, y);
}

void ChooseBlock(void)
{
	srand((unsigned int)time(NULL));
	currentBlockModel = (rand() % NUM_OF_BLOCK_MODEL) * 4;
}

int GetCurrentBlockIdx(void)
{
	return currentBlockModel+rotateSte;
}

void ShowBlock(char blockInfo[][4])
{
	int y, x;
	point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos(curPos.x + (x*2), curPos.y+y);

			if (blockInfo[y][x] == 1)
				printf("■");
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y);
}

void DeleteBlock(char blockInfo[][4])
{
	int y, x;
	point curPos = GetCurrentCursorPos();

	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos(curPos.x + x * 2, curPos.y + y);
			if (blockInfo[y][x] == 1)
				printf("  "); //공백두칸
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y);
}
void BlockDown(void)
{
	if(CheckCollision(DOWN))
	{
		InitNewBlockPos(14,0);
		ChooseBlock();
		return;
	}
	
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY += 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

void ShiftLeft(void)
{
	/*int check = checkCollision(); 충돌검사
		if(충돌)
		{
			return;
		}
	*/
	if (CheckCollision(LEFT))
	{
		//InitNewBlockPos(10,0);
		//ChooseBlock();
			return;
	}
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX -= 2;
	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}
void ShiftRight(void)
{
	if(CheckCollision(RIGHT))
	{
		return;
	}
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX += 2;
	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}
void RotateBlock(void)
{
	int nextRotSte;

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);

	nextRotSte = rotateSte + 1;
	nextRotSte %= 4;
	rotateSte = nextRotSte;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}
void MarkToMap(void)
{
	int cur_model = GetCurrentBlockIdx();
	point curPos = GetCurrentCursorPos();
	int i, j;


	for (i = curPos.y; i < curPos.y + blockDetails[cur_model].row; i++)
	{
		for (j = (curPos.x - 10) / 2; j < (curPos.x - 10) / 2 + blockDetails[cur_model].col; j++)
		{
			if (blockModel[cur_model][i - curPos.y][j - (curPos.x - 10) / 2] == 1 && boardInfo[i][j] == 0)
			{
				boardInfo[i][j] = 1;
			}
		}
	}
}
int CheckCollision(int dir)
{
	int cur_model = GetCurrentBlockIdx();
	point curPos = GetCurrentCursorPos();
	int i, j;
	int dream = 0;
	switch (dir)
	{
	case LEFT :
		dream = (curPos.x-10 )/2-1;
		for (i = curPos.y; i < curPos.y+blockDetails[cur_model].row; i++)
		{
			for ((j = dream); j < dream+blockDetails[cur_model].col; j++)
			{
				if (blockModel[cur_model][i - curPos.y][j - dream] == 1 && boardInfo[i][j] == 1)
					return 1;
			}
		}
		return 0;
		break;

	case RIGHT :
		dream =(curPos.x -10)/ 2+1;
		for (i = curPos.y; i < curPos.y + blockDetails[cur_model].row; i++)
		{
			for ((j = dream); j < dream + blockDetails[cur_model].col; j++)
			{
				if (blockModel[cur_model][i - curPos.y][j - dream] == 1 && boardInfo[i][j] == 1)
					return 1;
			}
		}
		return 0;
		break;

	case DOWN:
		dream = curPos.y+1 ;
		for (i = dream; i < dream + blockDetails[cur_model].row; i++)
		{
			for ( j=(curPos.x - 10) / 2;  j < (curPos.x - 10) / 2 + blockDetails[cur_model].col; j++)
			{
				if (blockModel[cur_model][i - dream][j - (curPos.x - 10) / 2] == 1 && boardInfo[i][j] == 1)
				{	
					MarkToMap();
					return 1;
				}
			}
		}
		return 0;
		break;
	default:
		break;
	}
}
