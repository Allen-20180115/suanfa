#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50

typedef struct node{
    int num;
    float p;
    float w;
    float v;
}OBJECT;

void swap(OBJECT *x,OBJECT *y)
{
    OBJECT temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(OBJECT A[],int low,int high)
{
    int k, i = low;
    float x = A[low].v;
    for (k = low + 1; k <= high;k++)
    {
        if(A[k].v>=x)
        {
            i += 1;
            if(i!=k)
            swap(&A[i], &A[k]);
        }
    }
    swap(&A[low], &A[i]);
    return i;
}

void quicksort(OBJECT A[],int n,int low,int high)
{
    int k;
    if(low<=high)
    {
        k = partition(A, low, high);
        quicksort(A, n,low, k - 1);
        quicksort(A, n,k + 1, high);
    }
}

float knapsack_greedy(float M,OBJECT instance[],float x[],int n,int low,int high)
{
    int i;
    float m, p = 0;
    for (i = 0; i < n;i++)
    {
        instance[i].v = instance[i].p / instance[i].w;
        x[i] = 0;
    }
    quicksort(instance, n,low,high);
    m = M;
    for (i = 0; i < n;i++)
    {
        if(instance[i].w<=m)
        {
            x[i] = 1;
            m = m - instance[i].w;
            p = p + instance[i].p;
        }
        else
        {
            x[i] = m / instance[i].w;
            p = p + x[i] * instance[i].p;
            break;
        }
    }
    return p;
}

int main(void)
{
    int i;
    int low = 0;
    int high = N - 1;
    float M = 50;
    float max,*x;
    OBJECT instance[N];
    OBJECT *index;
    printf("***̰���㷨��ⱳ������***\n");
    printf("\n");
    printf("�����Ŀɳ�������:%.1f\n", M);
    printf("\n");
    printf("ʹ���������������Ʒ�ļ�ֵ������:\n");
    //for (index = instance; index < instance+N;index++)
        //scanf("%d%f%f",&(*index).num,&(*index).p,&(*index).w);
    srand((unsigned)time(NULL));
    for (i = 0; i < N;i++)
    {
        instance[i].num = i + 1;
        instance[i].p = rand() % 99 + 1;
        instance[i].w = rand() % 99 + 1;
    }
    printf("\n");
    for (index = instance; index < instance+N; index++)
    {
        if(((index->num)-1)%10==0)
        printf("��Ʒ  ��ֵ  ����\n");
        printf("%2d    %.1f  %.1f", index->num, index->p, index->w);
        printf("\n");
    }
    printf("\n");
    if (!(x = (float *)malloc((size_t)N * sizeof(float))))
        exit(EXIT_FAILURE);
    max = knapsack_greedy(M, instance, x, N, low, high);
    printf("ֻ��ʾ������������ʱ��Ʒ�ı�ż����Ӧ������\n");
    printf("\n");
    printf("��Ʒ  �ݶ�\n");
    for (i = 0; i < N;i++)
    {   
        if(x[i]!=0)
        printf("%2d    %.1f\n", instance[i].num, x[i]);
    }
    printf("\n");
    printf("�����е���Ʒ��Ч��ֵΪ:%.1f\n", max);
    printf("\n");
    free(x);
    system("PAUSE");
    return 0;
}


