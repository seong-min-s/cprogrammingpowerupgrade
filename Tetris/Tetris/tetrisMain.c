#include <Windows.h>
#include "keyCurControl.h"
#include "blockStageControl.h"

#define START_CURPOS_X		(5*2)
#define START_CURPOS_Y		(0)
#define SYS_DELAY			100

int main(void)
{
	int collision;
	InitKeyDelayRate(20);

	/*Ä¿¼­ ±ôºýÀÓ Á¦°Å*/
	RemoveCursor();

	InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

	ChooseBlock();


	while (1)
	{
		collision = CheckCollision();
		if (collision == 0|| collision == 1) {
			InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

			ChooseBlock();
		}
		BlockDown();
		ProcessKeyInput();
	}
	return 0;
}