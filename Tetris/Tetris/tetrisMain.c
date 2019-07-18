#define START_CURPOS_X		(5*2+4)
#define START_CURPOS_Y		(0)
#define SYS_DELAY			100

int main(void)
{
	DrawGameBoard();
	
	int collision;
	InitKeyDelayRate(20);
	
	RemoveCursor();

	InitNewBlockPos(START_CURPOS_X, START_CURPOS_Y);

	ChooseBlock();


	while (1)
	{
		//collision = CheckCollision();
		BlockDown();
		ProcessKeyInput();
	}
	
	return 0;
}