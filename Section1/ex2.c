#include<stdio.h>

int main()
{
	char str[20];
	fgets(str,20,stdin);
	fputs(str,stdout);
	return 0;
}
