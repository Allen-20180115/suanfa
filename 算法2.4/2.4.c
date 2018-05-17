#include <stdio.h>
#include <stdlib.h>
float qinjiushao_alm(float x,double A[],int n)
{
	float p;
	if(n==0)
		p=A[0];
	else
		p=qinjiushao_alm(x,A,n-1)*x+A[n];
	printf("%.2f", p);
	printf("\n");
	return p;
}
int main()
{
	int i, n, m;
	float x,p;
	printf("Please input a floating point x:");
	scanf("%f", &x);
	printf("Please input a integer n:");
	scanf("%d", &n);
	m = n + 1;
	double *A = (double *)malloc(m * sizeof(double));
	printf("Please input array A[m]:\n");
	for (i = 0; i < m;i++)
	{
		scanf("%lf", &A[i]);
	}
	p = qinjiushao_alm(x, A, n);
	printf("The result is:\n");
	printf("%.2f", p);
	free(A);
	getchar();
	getchar();
}