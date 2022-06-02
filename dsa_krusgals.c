#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct edge
{
    int u;
    int v;
    int weight;
};
typedef struct edge KA;

KA edges[30];
KA temp;

void union1(int a[20],int vertex,int u,int v)
{
    int i;
    int temp=a[u];
    for(i=0;i<vertex;i++)
    {
        if(a[i]==temp)
        {
            a[i]=a[v];
        }
    }
}

int find(int a[20],int u,int v)
{
    if(a[u]==a[v])
        return 1;
    else
        return 0;
}

void selection_sort(int e)
{
    int i,j,min=0,c=0;
    for(i=0;i<=e-2;i++)
    {
        min=i;
        for(j=i+1;j<=e-1;j++)
        {
            if(edges[j].weight<edges[min].weight)
                min=j;
        }
        temp=edges[min];
        edges[min]=edges[i];
        edges[i]=temp;
    }
}



int main()
{
    int a[20];
    int vertex,e,i,x=0,m=0;
    printf("Enter the number of vertices and edges\n");
    scanf("%d%d",&vertex,&e);
    for(i=0;i<e;i++)
    {
        printf("Enter initial vertex u,final vertex v and the weight associated with edge\n");
        scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].weight);
    }
    for(i=0;i<vertex;i++)
    {
        a[i]=i;
    }
    selection_sort(e);
    printf("The sorted edges are\n");
     for(i=0;i<e;i++)
    {
        printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].weight);
    }

    printf("The edges included in the MST are\n");
    for(i=0;i<e;i++)
    {

        m=find(a,edges[i].u,edges[i].v);
        if(m==1)
        {
            continue;
        }
        else
        {
            x++;
            union1(a,vertex,edges[i].u,edges[i].v);
            printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].weight);
        }
        if(x==vertex-1)
            break;
    }
    return 0;
}
