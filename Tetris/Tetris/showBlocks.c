#include<stdio.h>
#include<Windows.h>

void ShowBlock(char blockInfo[][4]);
void SetCurrentCursorPos(int x, int y);
COORD GetCurrentCursorPos(void);
void RemoveCursor(void);

char blockModel[][4][4]=
{
	/*	■
		■■■*/
	{
		{0,0,0,0},
		{1,0,0,0},
		{1,1,1,0},
		{0,0,0,0}
	},
	{
		{0,1,0,0},
		{0,1,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0}
	},
	{
		{1,1,0,0},
		{1,0,0,0},
		{1,0,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,0,1,0},
		{1,1,1,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,0,0},
		{0,1,0,0},
		{0,1,0,0}
	},
	{
		{0,0,0,0},
		{0,0,0,0},
		{1,1,1,0},
		{1,0,0,0}
	},
	{
		{1,0,0,0},
		{1,0,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,1,0,0},
		{1,1,1,0},
		{0,0,0,0}
	},
	{
		{0,1,0,0},
		{1,1,0,0},
		{0,1,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,1,0},
		{0,1,0,0},
		{0,0,0,0}
	},
	{
		{0,1,0,0},
		{0,1,1,0},
		{0,1,0,0},
		{0,0,0,0}
	},
	{
		{1,0,0,0},
		{1,0,0,0},
		{1,0,0,0},
		{1,0,0,0}
	},
	{
		{0,0,0,0},
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0}
	},
	{
		{1,0,0,0},
		{1,0,0,0},
		{1,0,0,0},
		{1,0,0,0}
	},
	{
		{0,0,0,0},
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,0,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{1,0,0,0},
		{1,1,0,0},
		{0,1,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0}
	},
	{
		{1,0,0,0},
		{1,1,0,0},
		{0,1,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0}
	},
	{
		{0,0,1,0},
		{0,1,1,0},
		{0,1,0,0},
		{0,0,0,0}
	},
	{
		{0,0,0,0},
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0}
	},
	{
		{0,0,1,0},
		{0,1,1,0},
		{0,1,0,0},
		{0,0,0,0}
	}
};
int blank[4][4] = {
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
};
int main(void)
{
	RemoveCursor();
	for (int i = 0; i < 5; i++) {
		SetCurrentCursorPos(0, i);
		ShowBlock(blockModel[0]);
		//getchar();
		Sleep(1000);
		ShowBlock(blank);
		//getchar();
	}
	//RemoveCursor();
	return 0;
}
void ShowBlock(char blockInfo[][4])
{
	int y, x;
	COORD curPos = GetCurrentCursorPos();

	for(y=0; y<4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);

			if (blockInfo[y][x] == 1)
				printf("■");//콘솔에서 특수문자 출력은 두칸을 차지한다.
			if (blockInfo[y][x] == 0)
			{
				printf(" ");
			}
		}
		SetCurrentCursorPos(curPos.X, curPos.Y);
	}
}
void SetCurrentCursorPos(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
COORD GetCurrentCursorPos(void)
{
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;

	return curPoint;
}
void RemoveCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}