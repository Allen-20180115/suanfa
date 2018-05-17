#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"
#define N 100

int BinarySearch(int a[],int x,int n)
{
    int mid;
    int left = 0;
    int right = n - 1;
    while(left<=right)
    {
        mid = (left + right) / 2;
        printf("left=%2d,right=%2d,mid=%2d", left, right, mid);
        printf("\n");
        if(x==a[mid])
            return mid;
        else if(x<a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    int i,x,res;
    int *a = (int *)malloc(N * sizeof(int));
    printf("������ɰ����������100��1000���ڵ���Ȼ��:\n");
    printf("\n");
    srand((unsigned int)time(NULL));
    for (i = 0; i < N;i++)
        a[i] = rand() % 1000;
    quicksort(a, N, 0, 99);
    for (i = 0;i<N;i++)
        printf("%3d ", a[i]);
    printf("\n");
    printf("\n");
    printf("������Ҫ���ҵ�Ԫ��x:");
    scanf("%d", &x);
    printf("ÿ�β��ҹ�������:\n");
    res=BinarySearch(a, x, N);
    if(res==-1)
        printf("���ҽ��:����ʧ��!\n");
    else
        printf("���ҽ��:���ҳɹ�����Ԫ��Ϊ����a[n]���±�Ϊ%d��Ԫ��\n",res);
    printf("\n");
    printf("���ٴ�����Ҫ���ҵ�Ԫ��x:");
    scanf("%d", &x);
    printf("ÿ�β��ҹ�������:\n");
    res=BinarySearch(a, x, N);
    if(res==-1)
        printf("���ҽ��:����ʧ��!\n");
    else
        printf("���ҽ��:���ҳɹ�����Ԫ��Ϊ����a[n]���±�Ϊ%d��Ԫ��\n",res);
    free(a);
    getchar();
    getchar();
    return 0;
}