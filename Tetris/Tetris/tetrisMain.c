#define START_CURPOS_X		(5*2+4)
#define START_CURPOS_Y		(0)
#define SYS_DELAY			100
#include<stdio.h>
int main(void)
{
	DrawGameBoard();
	
	InitKeyDelayRate(20);
	

	while (1)
	{
		RemoveCursor();

		InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

		ChooseBlock();
		
		if (BlockDown())
		{
			printf("GAME OVER\n");
		}

		while (1)
		{
			if (BlockDown())
			{
				break;
			}
			ProcessKeyInput();
		}
	}
	
	return 0;
}