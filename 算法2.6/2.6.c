#include <stdio.h>
int GCD(unsigned int a,unsigned int b)
{
	int res;
	if(a<b)
	{
		res=GCD(b,a);
	}
	else if(b==0)
	{
		res=a;
	}
	else
	{
		res=GCD(b,a%b);
	}
	printf("%d", b);
	printf("\n");
	return res;
}
int main()
{
	int res;
	res = GCD(5723, 2537);
	printf("�ݹ��㷨��������������Լ��:\n");
	printf("The result is:%d\n",res);
	getchar();
	getchar();
}