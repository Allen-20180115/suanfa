#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[],int low,int high)
{
    int k, i = low;
    int x = A[low];
    for (k = low + 1; k <= high;k++)
    {
        if(A[k]<=x)
        {
            i += 1;
            if(i!=k)
            swap(&A[i], &A[k]);
        }
    }
    swap(&A[low], &A[i]);
    return i;
}

void quicksort(int A[],int n,int low,int high)
{
    int k,j;
    if(low<=high)
    {
        k = partition(A, low, high);
        for(j=0;j<n;j++)
        {
            if(j==k)
            printf("*%d ",A[j]);
            else
            printf("%d ",A[j]);
        }
        printf("\n");
        quicksort(A, n,low, k - 1);
        quicksort(A, n,k + 1, high);
    }
}

int main()
{
    int i,low,high;
    low = 0;
    high = N - 1;
    int *A = (int *)malloc(N * sizeof(int));
    srand((unsigned int)time(NULL));
    printf("随机生成20个100以内的自然数:\n");
    for (i = 0; i < N;i++)
    {
        A[i]=rand()%100;
        printf("%d ",A[i]);
    }
    printf("\n");
    printf("\n");
    printf("快速排序结果如下:\n");
    quicksort(A,N,low,high);
    free(A);
    getchar();
    getchar();
    return 0;
}