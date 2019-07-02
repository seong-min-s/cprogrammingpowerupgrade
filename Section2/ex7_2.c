#include<stdio.h>

int main(void)
{
	int a, b, c, max;

	scanf("%d %d %d",&a,&b,&c);
	//max=((max=a<b?b:a)<c?c:max);
	//max=a<b?b:a;
	//max=max<c?c:max;
	//
	max=
		(a<b)?
			(b<c)?c:b : (a<c)?c:a;
	printf("max:%d\n",max);
	return 0;
}
	
