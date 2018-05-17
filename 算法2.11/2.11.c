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
    printf("随机生成按递增次序的100个1000以内的自然数:\n");
    printf("\n");
    srand((unsigned int)time(NULL));
    for (i = 0; i < N;i++)
        a[i] = rand() % 1000;
    quicksort(a, N, 0, 99);
    for (i = 0;i<N;i++)
        printf("%3d ", a[i]);
    printf("\n");
    printf("\n");
    printf("请输入要查找的元素x:");
    scanf("%d", &x);
    printf("每次查找过程如下:\n");
    res=BinarySearch(a, x, N);
    if(res==-1)
        printf("查找结果:查找失败!\n");
    else
        printf("查找结果:查找成功！该元素为数组a[n]中下标为%d的元素\n",res);
    printf("\n");
    printf("请再次输入要查找的元素x:");
    scanf("%d", &x);
    printf("每次查找过程如下:\n");
    res=BinarySearch(a, x, N);
    if(res==-1)
        printf("查找结果:查找失败!\n");
    else
        printf("查找结果:查找成功！该元素为数组a[n]中下标为%d的元素\n",res);
    free(a);
    getchar();
    getchar();
    return 0;
}