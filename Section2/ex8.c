#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int num;
	int *arr;
	int count=0;
	int de;
	scanf("%d",&num);
	de=num;
	while(num!=0)
	{
		count++;
		num=num/2;
	}
	arr=(int*)malloc(sizeof(int)*count);
	for(int i=0; i< count; i++)
	{
		arr[i]=de%2;
		de=de/2;
	}

	for(int i=count-1; i>=0; i--)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}
