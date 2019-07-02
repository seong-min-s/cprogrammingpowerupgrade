#include<stdio.h>

int main(void)
{

	int a, b;
	int add;
	fputs("두 수를 16진수로 입력 : ", stdout);
	scanf("%x %x",&a,&b);
	add=a+b;

	printf("연산결과 8진수 %o\n",add);
	printf("연산결과 10진수 %d\n",add);
	printf("연산결과 16진수 %x\n",add);

	return 0;
}
