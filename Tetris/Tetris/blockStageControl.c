#include "blockInfo.h"
#include<time.h>
#include "point.h"
#include "keyCurControl.h"
#include "common.h"
//#include "boardInfo.h"
extern int boardInfo[11][12];
extern void MarkToMap();
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
				printf("¡á");
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
				printf("  "); //°ø¹éµÎÄ­
		}
	}
	SetCurrentCursorPos(curPos.x, curPos.y);
}
int BlockDown(void)
{
	curPosY += 1;
	if(CheckCollision())
	{
		curPosY -= 1;
		MarkToMap();
		return 1;
	}
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
	return 0;
}

void ShiftLeft(void)
{
	curPosX -= 2;
	if (CheckCollision())
	{
			curPosX += 2;
			return;
	}
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}
void ShiftRight(void)
{
	curPosX += 2;
	if(CheckCollision())
	{
			curPosX -= 2;
			return;
	}
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}
void RotateBlock(void)
{
	int afterRotSte,deficiency = 0;
	int beforeRotSte = rotateSte;
	point beforePos = { curPosX,curPosY };

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);

	afterRotSte = rotateSte + 1;
	afterRotSte %= 4;
	rotateSte = afterRotSte;
	deficiency = CheckCollision();
	curPosX -= 2 * deficiency;

	if (CheckCollision())
	{	
		rotateSte = beforeRotSte;
		curPosX = beforePos.x;
		ShowBlock(blockModel[GetCurrentBlockIdx()]);
		return;
	}
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
int CheckCollision(void)
{
	int num=GetCurrentBlockIdx();
	point boardPos = { (curPosX - 10) / 2, curPosY };

	for (int i = 0; i < blockDetails[num].row; i++)
	{
		for (int j = 0; j < blockDetails[num].col; j++)
		{
			if (blockModel[num][i][j ] == 1 && boardInfo[boardPos.y+i][boardPos.x+j] == 1)
				return blockDetails[num].col-j;
		}
	}
	return 0;
}
