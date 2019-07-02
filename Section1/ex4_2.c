#include<stdio.h>

int main(void)
{
	int c;
	int temp=0;
	int sum=0;
	while(1)
	{
		fputs("Data input (Ctrl+Z to exit) :",stdout);
		temp=scanf("%d",&c);
		if(temp==-1)
			break;
		sum+=c;
	}
	printf("\n총합 : %d\n",sum);
	return 0;
}

