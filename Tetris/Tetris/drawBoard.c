#include "boardInfo.h"
#define BOARD_ORIGIN_X 10
#define BOARD_ORIGIN_Y 0
void DrawGameBoard(void)
{
	//SetCurrentCursorPos(MAP_ORIGIN_X, MAP_ORIGIN_Y);
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		if (boardInfo[y][0] == 1)
		{
			SetCurrentCursorPos(BOARD_ORIGIN_X, y+ BOARD_ORIGIN_Y);
			printf("¦¢");
		}
	}

	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		if (boardInfo[y][BOARD_WIDTH + 1] == 1)
		{
			SetCurrentCursorPos(BOARD_ORIGIN_X+1+2*(BOARD_WIDTH)+1, y + BOARD_ORIGIN_Y);
			printf("¦¢");
		}
	}
	for (int x = 0; x < BOARD_WIDTH+2; x++)
	{
		if (boardInfo[BOARD_HEIGHT][x] == 1)
		{
			SetCurrentCursorPos(BOARD_ORIGIN_X + x, BOARD_ORIGIN_Y+BOARD_HEIGHT);
			if(x==0)
				printf("¦¦");
			else if(x== BOARD_WIDTH+1)
				printf("¦¥");
			else
				printf("¡á",x);
		}
	}
}