#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct queue
{
int front,rear;
int q[100];
}que;

int empty(que *q)
{
if(q->front>q->rear)
return 1;
else
return 0;
}
void enqueue(que *q,int data)
{
q->rear=q->rear+1;
q->q[q->rear]=data;
}
int dequeue(que *q)
{
int data;
data=q->q[q->front];
q->front=q->front+1;
return data;
}

int bfssum=0;
int dfssum=0;
int dfsvisited[12]={0};
int ans=0;
int perlitre=10;
void quantityReq(int houses)
{
    int ans=0, i, cost=2,vol_out_per_sec, totalcost=0; //2rs per litre
    int lower = 1000, upper = 10000;
    srand(time(0));
    printf("\n Water storage capacity of houses: \n\n");
    for (i=0; i<houses; i++)
        {
        int num = (rand() % (upper - lower + 1)) + lower;
        printf("House no. %d: %d\nWater Bill: Rs %d\n",i+1, num, num*cost);
        totalcost = totalcost + (num*cost);
        ans = ans + num;
        }
    printf("\nTotal water required: %d", ans);
    printf("\nTotal cost: Rs %d", totalcost);
    vol_out_per_sec=(3.14)*(0.25*0.25)*10;
    float(time)=(ans/vol_out_per_sec);

printf("\nTotal time required to fill all houses:%0.2f seconds",time);


}
void dfs(int G[][11],int start,int n)
{
int t,j;
if(dfsvisited[start]==0)
{
printf("%d\t",start);
dfsvisited[start]=1;
for(j=0;j<=n;j++)
{
    if(G[start][j]!=0&& dfsvisited[j]==0)
{
         dfssum=dfssum+G[start][j];
         dfs(G,j,n);
}
}
}
}
void bfs(int G[][11],int start,int n)
{
bfssum=0;
struct queue q;
q.front=0;
q.rear=-1;
int i,j;
int visited[12]={0};
i=start;
printf("%d\t",i);
enqueue(&q,i);
visited[i]=1;
while(!empty(&q))
{
i=dequeue(&q);
for(j=0;j<=n;j++)
{
if(G[i][j]!=0&&visited[j]==0)
{
bfssum=bfssum+G[i][j];
printf("%d\t",j);
enqueue(&q,j);
visited[j]=1;
}
}
}
}

int main()
{
    float vol_out_per_sec,time;
    int s;
int houses=6;
int price=100;
int G[11][11]={{0,4,0,0,0,0},
               {4,0,2,3,3,4},
               {0,2,0,0,0,0},
               {0,3,0,0,0,0},
               {0,3,0,0,0,0},
               {0,4,0,0,0,0}
               };
bfs(G,1,10);
printf("\nBFS SUM:%d\n",bfssum*100);
printf("\n");
dfs(G,1,10);
printf("\n");
printf("\nDFS SUM:%d",dfssum*100);
quantityReq(houses);
printf("\n");
}
