#include<time.h>
#include "common.h"
#include "point.h"
#include "blockInfo.h"
#include "keyCurControl.h"
#include "mapInfo.h"

static int currentBlockModel;
static int rotateSte;
static int curPosX, curPosY;

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
void BlockDown(void)
{
	//checkCollision(); Ãæµ¹°Ë»ç
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY += 1;

	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

void ShiftLeft(void)
{
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX -= 2;
	SetCurrentCursorPos(curPosX, curPosY);
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}
void ShiftRight(void)
{
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
int CheckCollision()
{
	/*if ((curPosX + blockDetails[currentBlockModel].row < 0 && curPosX + blockDetails[currentBlockModel].col>99))
		return 0;*/
	if (curPosY + blockDetails[currentBlockModel].col > 30)//¹Ù´ÚÃæµ¹
	{
		for (int i = curPosY + 0; i < curPosY + blockDetails[currentBlockModel].row; i++)
		{
			for (int j = curPosX + 0; j < curPosX + blockDetails[currentBlockModel].col; j++)
			{
				if (blockModel[GetCurrentBlockIdx()][i - curPosY][j - curPosX] == 1)
				{
					mapInfo[i][j] = 1;
				}
			}
		}
		return 0;
	}
	for (int i = curPosY + 0; i < curPosY + blockDetails[currentBlockModel].row; i++)
	{
		for (int j = curPosX + 0; j < curPosX + blockDetails[currentBlockModel].col; j++)
		{
			if (blockModel[GetCurrentBlockIdx()][i - curPosY][j - curPosX] == 1 && mapInfo[i][j] != 0)
			{
				for (int i = curPosY + 0; i < curPosY + blockDetails[currentBlockModel].row; i++)
				{
					for (int j = curPosX + 0; j < curPosX + blockDetails[currentBlockModel].col; j++)
					{
						if (blockModel[GetCurrentBlockIdx()][i - curPosY][j - curPosX] == 1)
						{
							mapInfo[i][j] = 1;
						}
					}
				}
				return 1;
			}//¸ÊÃæµ¹

		}
	}
	return 3;
}