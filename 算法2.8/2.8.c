#include<stdio.h>
int GCD(unsigned int a,unsigned int b)
{
    int res = 0;
    if(a<b)
    {
        int t = a;
        a = b;
        b = t;
    }
    L1:
    if(b==0)
    {
        res = a;
    }
    else
    {
        int t = b;
        b = a % b;
        a = t;
        printf("%d", a);
        printf("\n");
        goto L1;
    }
    return res;
}
int main()
{
    int res;
	res = GCD(5723, 2537);
    printf("非递归算法求解两整数的最大公约数:\n");
	printf("The result is:%d\n",res);
	getchar();
	getchar();
}
 