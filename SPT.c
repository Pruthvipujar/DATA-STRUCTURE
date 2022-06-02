#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct priority_queue
{
    int distance;
    int node;
}pq;

pq front(pq p[],int n)
{
    pq temp;
    temp.distance=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(p[i].distance < temp.distance && p[i].distance!=-1)
        {
            temp=p[i];
        }
    }
    return temp;
}
void dequeue(pq p[],int n)
{
    pq temp=front(p,n);
    for(int i=0;i<n;i++)
    {
        if(temp.distance==p[i].distance && temp.node==p[i].node)
        {
            p[i].distance=-1;
            p[i].node=-1;
        }
    }
}
int isEmpty(pq p[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(p[i].node!=-1)
        return 0;
    }
    return 1;
}
void dijkstra(int **arr,int n,int dist[],int source)
{
    pq p[100];
    for(int i=0;i<100;i++)
    {
        p[i].node=-1;
        p[i].distance=-1;
    }
    int l=0;
    dist[source]=0;
    p[l].distance=0;
    p[l].node=source;
    while(!isEmpty(p,l+1))
    {
        pq t=front(p,l+1);
        int node=t.node;
        int d=t.distance;
        dequeue(p,l+1);
        for(int i=0;i<n;i++)
        {
            int curr_dist=d;
            if(arr[node][i]!=0)
            {
                int next_distance=curr_dist+arr[node][i];
                if(next_distance<dist[i])
                {
                    dist[i]=next_distance;
                    l=l+1;
                    p[l].distance=next_distance;
                    p[l].node=i;
                }
            }
        }
    }
}

int main()
{
    int n;
    printf("\nEnter total number of vertices : ");
    scanf("%d",&n);
    int **arr=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++)
    {
        arr[i]=(int *)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    }
    int edges;
    printf("\nEnter total number of edges : ");
    scanf("%d",&edges);
    for(int i=1;i<=edges;i++)
    {
        int u,v,w;
        printf("\nEnter the starting edge : ");
        scanf("%d",&u);
        printf("\nEnter the ending edge : ");
        scanf("%d",&v);
        printf("\nEnter the edge weight : ");
        scanf("%d",&w);
        arr[u][v]=w;
        arr[v][u]=w;
    }
    int dist[n];
    for(int i=0;i<n;i++)
    dist[i]=999999;
    int source;
    printf("\nEnter the source node : ");
    scanf("%d",&source);
    dijkstra(arr,n,dist,source);
    for(int i=0;i<n;i++)
    {
        printf("\n%d to %d distance is %d .",source,i,dist[i]);
    }
}
