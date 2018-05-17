#include <stdio.h>
#include <stdlib.h>

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
    int k;
    if(low<=high)
    {
        k = partition(A, low, high);
        //for(j=0;j<n;j++)
        //{
            //if(j==k)
            //printf("*%d ",A[j]);
            //else
            //printf("%d ",A[j]);
        //}
        //printf("\n");
        quicksort(A, n,low, k - 1);
        quicksort(A, n,k + 1, high);
    }
}