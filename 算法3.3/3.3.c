#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#define MAXVEX 100

typedef struct enode{
    int adjvex;
    int info;
    struct enode *nextadj;
}EdgeNode;

typedef struct vnode{
    int vervex;
    EdgeNode *firstedge;
}VerNode;

//typedef VerNode AdjList[MAXVEX];

typedef struct{
    //AdjList adjlist;
    VerNode adjlist[MAXVEX];
    int v_num;
    int e_num;
}ALGraph;

typedef struct nnode{
    int i;
    int j;
    int q;
}NewNode;

void dijkstra(VerNode node[],int n,int u)
{
    float temp;
    int i, j, t, k;
    float *d;
    int *p;
    bool *s;
    if(!(d=(float *)malloc((size_t)n * sizeof(float))))
        exit(EXIT_FAILURE);
    if(!(p=(int *)malloc((size_t)n * sizeof(int))))
        exit(EXIT_FAILURE);
    if(!(s=(bool *)malloc((size_t)n * sizeof(bool))))
        exit(EXIT_FAILURE);
    EdgeNode *pnode;
    for (i = 0; i < n;i++)
    {
        d[i] = FLT_MAX;
        s[i] = false;
        p[i] = -1;
    }
    if(!(pnode=node[u].firstedge))
        return;
    while(pnode)
    {
        d[pnode->adjvex] = pnode->info;
        p[pnode->adjvex] = u;
        pnode = pnode->nextadj;
    }
    d[u] = 0;                          
    s[u] = true;                       
    for (i = 1; i < n;i++)             
    {
        for (k = 0; k < n;k++)
            printf("%.1f ", d[k]);
        printf("\n");
        temp = FLT_MAX;
        t = u;
        for (j = 0; j < n;j++)
        {
            if(!s[j]&&d[j]<temp)
            {
                t = j;
                temp = d[t];
            }    
        }
        if(t==u)
            break;
        s[t] = true;
        pnode = node[t].firstedge;
        while(pnode)
        {
            if(!s[pnode->adjvex]&&d[pnode->adjvex]>d[t]+pnode->info)
            {
                d[pnode->adjvex] = d[t] + pnode->info;
                p[pnode->adjvex] = t;
            }
            pnode = pnode->nextadj;
        }
    }
    free(s);
    free(p);
    free(d);
}

void CreateALGraph(ALGraph *G)
{
    int i, k;
    //int j, q;

    //printf("请输入顶点数和边数:\n");
    //scanf("%d%d", &(G->v_num), &(G->e_num));

    G->v_num = 21;
    G->e_num = 40;
    printf("顶点数:%d,边数:%d\n",G->v_num,G->e_num);

    //printf("请输入顶点信息:\n");
    //for (i = 0; i < G->v_num;i++)
    //{
        //scanf("%d", &(G->adjlist[i].vervex));
        //G->adjlist[i].firstedge = NULL;
    //}

    //G->adjlist[7] = {[0].vervex = 0,
                     //[1].vervex = 1,
                     //[2].vervex = 2,
                     //[3].vervex = 3,
                     //[4].vervex = 4,
                     //[5].vervex = 5,
                     //[6].vervex = 6};
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
    G->adjlist[12].vervex = 12;
    G->adjlist[13].vervex = 13;
    G->adjlist[14].vervex = 14;
    G->adjlist[15].vervex = 15;
    G->adjlist[16].vervex = 16;
    G->adjlist[17].vervex = 17;
    G->adjlist[18].vervex = 18;
    G->adjlist[19].vervex = 19;
    G->adjlist[20].vervex = 20;
    printf("顶点信息如下:\n");
    for (i = 0; i < G->v_num;i++)
    {
        printf("%d ", G->adjlist[i].vervex);
        G->adjlist[i].firstedge = NULL;
    }
    printf("\n");

    //printf("请输入边的信息:\n");
    //for (k = 0; k < G->e_num;k++)
    //{
        //scanf("%d%d%d", &i, &j,&q);
        //EdgeNode *s = (EdgeNode *)malloc(sizeof(EdgeNode));
        //s->adjvex = j;
        //s->info = q;
        //s->nextadj = G->adjlist[i].firstedge;
        //G->adjlist[i].firstedge = s;
    //}

    //NewNode new[12] = {{0, 1, 20},
                       //{0, 2, 50}, 
                       //{0, 3, 30}, 
                       //{1, 2, 25}, 
                      //{1, 5, 70}, 
                       //{2, 3, 40}, 
                       //{2, 4, 25}, 
                       //{2, 5, 50}, 
                       //{3, 4, 55}, 
                       //{4, 5, 10}, 
                       //{4, 6, 70}, 
                       //{5, 6, 50}};
    NewNode new[40] = {{0, 1, 20},
                       {0, 2, 50}, 
                       {0, 3, 25}, 
                       {0, 4, 30}, 
                       {0, 5, 35}, 
                       {0, 6, 40}, 
                       {0, 7, 45}, 
                       {0, 8, 50}, 
                       {0, 9, 55}, 
                       {0, 10, 60}, 
                       {0, 11, 65}, 
                       {0, 12, 70},
                       {0, 13, 75},
                       {0, 14, 80},
                       {1, 2, 25},
                       {1, 15, 30},
                       {2, 15, 25},
                       {2, 17, 40},
                       {3, 15, 35},
                       {4, 15, 45},
                       {5, 16, 65},
                       {5, 17, 35},
                       {6, 16, 70},
                       {7, 16, 55},
                       {8, 16, 40},
                       {9, 16, 60},
                       {10, 17, 35},
                       {11, 17, 35},
                       {12, 17, 55},
                       {13, 17, 65},
                       {14, 17, 80},
                       {15, 18, 45},
                       {16, 18, 40},
                       {16, 19, 70},
                       {17, 16, 25},
                       {17, 18, 60},
                       {17, 19, 75},
                       {18, 19, 10},
                       {18, 20, 50},
                       {19, 20, 35}};
    printf("边的信息如下:\n");
    for (k = 0; k < G->e_num;k++)
    {
        printf("%d %d %d\n", new[k].i, new[k].j, new[k].q);
        EdgeNode *s = (EdgeNode *)malloc(sizeof(EdgeNode));
        s->adjvex = new[k].j;
        s->info = new[k].q;
        s->nextadj = G->adjlist[new[k].i].firstedge;
        G->adjlist[new[k].i].firstedge = s;
    }
}

int main(void)
{
    printf("***贪心算法求解单源点最短路径问题***\n");
    printf("\n");
    int u;
    ALGraph *G = (ALGraph *)malloc(sizeof(ALGraph));
    CreateALGraph(G);
    printf("请输入源结点:");
    scanf("%d", &u);
    printf("结果如下:\n");
    dijkstra(G->adjlist, G->v_num, u);
    free(G);
    system("PAUSE");
    return 0;
}