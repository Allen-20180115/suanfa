#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#define MAXVEX 100

typedef struct enode{
    int adjvex;
    int len;
    struct enode *nextadj;
}EdgeNode;

typedef struct vnode{
    int vervex;
    EdgeNode *firstedge;
}VerNode;

typedef struct{
    VerNode adjlist[MAXVEX];
    int v_num;
    int e_num;
}ALGraph;

typedef struct nnode{
    int i;
    int j;
    int q;
}NewNode;

void fgraph(VerNode node[],int n)
{
    int i;
    int *route, *path;
    float *cost;
    EdgeNode *pnode;
    if(!(route=(int *)malloc((size_t)n*sizeof(int))))
        exit(EXIT_FAILURE);
    if(!(path=(int *)malloc((size_t)n*sizeof(int))))
        exit(EXIT_FAILURE);
    if(!(cost=(float *)malloc((size_t)n*sizeof(float))))
        exit(EXIT_FAILURE);
    for (i = 0; i < n; i++)
    {
        cost[i] = FLT_MAX;
        path[i] = -1;
        route[i] = 0;
    }
    cost[n - 1] = 0;
    for (i = n - 2; i >= 0; i--)
    {
        pnode = node[i].firstedge;
        while(pnode!=NULL)
        {
            if(pnode->len+cost[pnode->adjvex]<=cost[i])
            {
                cost[i] = pnode->len + cost[pnode->adjvex];
                path[i] = pnode->adjvex;
            }
            pnode = pnode->nextadj;
        }
    }
    i = 0;
    while((route[i]!=n-1)&&(path[i]!=-1))
    {
        i++;
        route[i] = path[route[i - 1]];
    }
    printf("最小成本为:%.1f\n", cost[0]);
    printf("\n");
    printf("具有最小成本的路径为:");
    for (i = 0; i < n;i++)
    {
        if((i==0)||(route[i]!=0))
        {
            printf("%d", route[i]);
            if(route[i+1]!=0)
                printf("->");
        }
    }
    printf("\n");
    printf("\n");
    free(route);
    free(path);
    free(cost);
}

void CreateALGraph(ALGraph *G)
{
    int i, k;
    G->v_num = 12;
    G->e_num = 21;
    printf("顶点数:%d 边数:%d\n",G->v_num,G->e_num);
    G->adjlist[0].vervex = 0;
    G->adjlist[1].vervex = 1;
    G->adjlist[2].vervex = 2;
    G->adjlist[3].vervex = 3;
    G->adjlist[4].vervex = 4;
    G->adjlist[5].vervex = 5;
    G->adjlist[6].vervex = 6;
    G->adjlist[7].vervex = 7;
    G->adjlist[8].vervex = 8;
    G->adjlist[9].vervex = 9;
    G->adjlist[10].vervex = 10;
    G->adjlist[11].vervex = 11;
    printf("顶点信息如下:\n");
    for (i = 0; i < G->v_num;i++)
    {
        printf("%d ", G->adjlist[i].vervex);
        G->adjlist[i].firstedge = NULL;
    }
    printf("\n");
    NewNode new[21] = {{0, 1, 9},
                       {0, 2, 7},
                       {0, 3, 3},
                       {0, 4, 2},
                       {1, 5, 4},
                       {1, 6, 2},
                       {1, 7, 1},
                       {2, 5, 2},
                       {2, 6, 7},
                       {3, 7, 11},
                       {4, 6, 11},
                       {4, 7, 8},
                       {5, 8, 6},
                       {5, 9, 5},
                       {6, 8, 4},
                       {6, 9, 3},
                       {7, 9, 5},
                       {7, 10, 6},
                       {8, 11, 4},
                       {9, 11, 2},
                       {10, 11, 5}};
    printf("边的信息如下:\n");
    for (k = 0; k < G->e_num;k++)
    {
        printf("%2d %2d %2d\n", new[k].i, new[k].j, new[k].q);
        EdgeNode *s = (EdgeNode *)malloc(sizeof(EdgeNode));
        s->adjvex = new[k].j;
        s->len = new[k].q;
        s->nextadj = G->adjlist[new[k].i].firstedge;
        G->adjlist[new[k].i].firstedge = s;
    }
    printf("\n");
}

int main(void)
{
    printf("***动态规划算法求解多段图的最小成本问题***\n");
    printf("\n");
    ALGraph *G;
    if(!(G=(ALGraph *)malloc(sizeof(ALGraph))))
        exit(EXIT_FAILURE);
    CreateALGraph(G);
    fgraph(G->adjlist, G->v_num);
    free(G);
    system("PAUSE");
    return 0;
}