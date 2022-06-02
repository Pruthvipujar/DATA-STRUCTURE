#include<stdio.h>
#include<stdlib.h>
int cost[50][50];
int source=0,u,V,E;
int v[10],visited[10];
int dist[10],path[10];

int minimum(int dist[])
{
    int h=100,min=1000;
    for(int j=0;j<V;j++)
    {
        if(visited[j]==0)
        {
            min=dist[j];
            h=j;
        }
    }
    for(int i=0;i<V;i++)
    {
        if(visited[i]!=1)
        {

            if(dist[i]<min)
            {
                min=dist[i];
                h=i;
            }
       }

    }
    return h;
}
int min(int a,int b)
{
    if(a>b)
    {
       return b;
    }
    else
    {
       return a;
    }



}
void print(int dist[],int path[],int q[],int Q)
{
    for(int i=0;i<Q;i++)
    {
        printf("%d\n",dist[q[i]]);
    }
}
int main()
{
    int m,q[50],Q;
    int p,t,r;
    scanf("%d",&V);
    scanf("%d",&E);

    for(int k=0;k<V && V>3;k++)
    {
        for(int l=0;l<V;l++)
        {
            if(k==l)
            {

                cost[k][l]=0;
            }
            else
            {
                cost[k][l]=1000;
            }
        }
    }
    for(int a=0;a<E;a++)
    {
        scanf("%d%d%d",&p,&t,&r);
        cost[p][t]=r;
    }
    scanf("%d",&Q);
    for(int r=0;r<Q;r++)
    {
        scanf("%d",&q[r]);
    }
    u=source;
    for(int j=0;j<V;j++)
    {
       path[j]=source;
       dist[j]=cost[source][j];
       visited[j]=0;
    }
    visited[u]=1;
    for(int i=0;i<V;i++)
    {

        u=minimum(dist);
        visited[u]=1;
        for(int j=0;j<V;j++)
        {

            if(visited[j]==0)
            {
                m=min(dist[j],(dist[u]+cost[u][j]));
                if(m!=dist[j])
                {
                   dist[j]=m;
                   path[j]=u;
                }

            }
            visited[u]=1;
        }


    }
    print(dist,path,q,Q);

}
