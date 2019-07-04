#include<stdio.h>
#include<Windows.h>

int main(void)
{
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	printf("[%d, %d] \n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);

	puts("First Hello world");

	GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &curInfo
	);
	printf("[%d, %d]\n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);

	puts("Second Hello world");
	puts("Second Hello world");


	GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &curInfo
	);
	printf("[%d, %d]\n", curInfo.dwCursorPosition.X, curInfo.dwCursorPosition.Y);

	return 0;
}