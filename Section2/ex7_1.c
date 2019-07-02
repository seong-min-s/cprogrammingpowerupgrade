#include<stdio.h>

int main(void)
{
	int a, b;
	int max;
	scanf("%d %d",&a,&b);

	//max=(a>b)?a:b;
	max=a>b?a:b;

	printf("큰수:%d\n",max);
	
	return 0;
}
