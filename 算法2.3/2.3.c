#include<stdio.h>
#include<stdlib.h>
void insert_sort_rec(int A[],int n,int m)
{
	int k;
	int a;
	int i;
	n=n-1;
	if(n>0)
	{
		insert_sort_rec(A,n,m);
		a=A[n];
		k=n-1;
		while((k>=0)&&(A[k]>a)){
			A[k+1]=A[k];
			k=k-1;
		}
		A[k+1]=a;
	}
    for(i=0;i<m;i++)
	printf("%d",A[i]);
	printf("\n");
}
int main()
{
	 int i, n,m;
	 printf("Please input a integer n:");
	 scanf("%d", &n);
	 m = n;
	 int *A = (int *)malloc(n * sizeof(int));
	 printf("Please input an array A[n]:\n");
	 for (i = 0; i < n;i++)
	 {
		 scanf("%d", &A[i]);
	 }
	 printf("The run result is:\n");
	 insert_sort_rec(A,n,m);
	 free(A);
	 getchar();
     getchar();
}