#include<stdio.h>

int main(void)
{
	char c='s';
	int count=0;
	while(1)
	{
		fputs("Data input (Ctrl+Z to exit) :",stdout);
		c=getchar();
		if(c==EOF)
			break;
		scanf("%c",&c);
		fflush(stdin);
		count++;
	}
	printf("%d\n",count);
	return 0;
}

