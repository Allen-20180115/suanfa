#include<stdio.h>
	int power(int x,int n)
	{
		int y;
		if(n==0)
		y=1;
		else
		{
            y=power(x,n/2);
			y=y*y;
			if(n%2==1)
			y=y*x;
		}
		printf("%d", y);
		printf("\n");
		return y;
	}
int main()
{
	int a,b,c;
	printf("Please input x and n:\n");
	scanf("%d%d",&a,&b);
    c=power(a,b);
	printf("The result is:%d\n",c);
    getchar();
    getchar();
}