#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int *a=(int*)malloc(sizeof(int)*5);
	for(int i=0; i< 5;i++)
	{
		a[i]=i;
	}
	a=(int*)realloc(a,sizeof(int)*10);
	for(int i=5; i<10; i++)
	{
		a[i]=i;
	}

	for(int i=0; i<10; i++)
	{
		printf("%d ",a[i]);
	}
	free(a);
	return 0;
}
