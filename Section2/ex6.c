#include<stdio.h>

int main(void)
{
	int num=0;
	int max=0;
	int min=10000;
	int sum=0;
	double avg;
	for(int i=0; i<7; i++)
	{
		scanf("%d",&num);
		if(max<num)
			max=num;
		if(min>num)
			min=num;
		sum+=num;
	}
	printf("max : %d, min : %d, sum : %d, avg : %f \n",max,min,sum,sum/7.0);
	return 0;
}
