#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

void Copy(int *x,int *y,int left,int right)
{
    for(int i=0;i<=(right-left);i++)
        x[left+i]=y[i];
}

void Merge(int a[],int b[],int l,int m,int r)
{
    int i=l,j=m+1,k=0;
    while((i<=m)&&(j<=r))         //��a[l:m]��a[m+1:r]�е�Ԫ������ȽϺ���b[r-l]�н�������ֱ������һ����Ԫ������Ϊֹ
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=m)                    //��a[l:m]��ʣ
        b[k++]=a[i++];
    while(j<=r)                    //��a[m+1:r]��ʣ
        b[k++]=a[j++];
}

void MergeSort(int a[],int b[],int n,int left,int right)
{
    if(left<right)
    {
        int i=(left+right)/2;
        MergeSort(a,b,n,left,i);
        MergeSort(a,b,n,i+1,right);
        Merge(a,b,left,i,right);
        Copy(a,b,left,right);
        for(int j=0;j<n;j++)
            printf("%d ",a[j]);
            printf("left=%2d,i=%2d,right=%2d",left,i,right);
        printf("\n");
    }
}

int main()
{
    int i,*a,*b,left,right;
    printf("***�����㷨���鲢��������***\n");
    printf("\n");
    left=0,right=N-1;
    if(!(a=(int *)malloc((size_t)N * sizeof(int))))
        exit(EXIT_FAILURE);
    if(!(b=(int *)malloc((size_t)N * sizeof(int))))
        exit(EXIT_FAILURE);
    printf("�������20��100���ڵ���Ȼ��:\n");
    printf("\n");
    srand((unsigned int)time(NULL));
    for (i = 0; i < N;i++)
    {
        a[i] = rand() % 100;
        printf("%2d ", a[i]);
    }
    printf("\n");
    printf("\n");
    printf("�����������:\n");
    MergeSort(a,b,N,left,right);
    free(a);
    free(b);
    getchar();
    getchar();
    return 0;
}