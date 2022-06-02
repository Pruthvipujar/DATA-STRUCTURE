#include<stdio.h>
int a[10][10];
int reach[10];
int s1=0;
int n;
void dfs(int h,int n);
void bfs(int h,int n);

int main()

{
    int i,j,n,z,p,q,r,choice,h,c,s1;
  printf("Enter the number of houses\n");
  scanf("%d",&n);
  a[n+1][n+1];
  reach[n+1];
  for(i=0;i<=n;i++)
  {
      for(j=0;j<=n;j++)
      {
          a[i][j]=0;
      }
  }
  printf("Enter the all connections\n");
  scanf("%d",&z);


  for(i=0;i<z;i++)
       {
  printf("Enter the start vertex number\n");
  scanf("%d",&p);

  printf("Enter the end vertex number\n");
  scanf("%d",&q);

  printf("enter distance from start to end vertex\n");
  scanf("%d",&r);

    a[p][q]=r;
    a[q][p]=r;
       }

for(i=0;i<=n;i++)
{
       printf("%d->",i);
        for(j=0;j<=n;j++)

        {
            if(a[i][j]>0)
            printf("%d->",j);
        }
        printf("\n");
}
for(;;)
{
    printf("ENTER THE CHOICE 1.DFS 2.BFS\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:for(i=0;i<=n;i++)
                 {
                      reach[i]=0;
                 }
                 dfs(0,n);
                printf("TOTAL distance using DFS is %d\n",s1);
                      c=s1*100;
                 printf("Total cost using DFS is %d\n",c);

        break;


        case 2:bfs(0,n);
            printf("TOTAL distance using BFS is %d\n",s1);
            c=s1*100;
            printf("Total cost using BFS is %d\n",c);

        break;
        default :return 0;
        break;
    }
}
}
void dfs(int h,int n)
{
int i;
    if(reach[h]==0)
    {
        printf("%d->",h);
        reach[h]=1;
        for(i=0;i<n;i++)
        {
            if(a[h][i]&&!reach[i])
            {
                dfs(i,n);
            }
        }
    }
}

void bfs(int h,int n)
{
    s1=0;
    int i;
    for(i=0;i<n;i++)
    {
        reach[i]=0;
    }
    int rear=-1;
    int front=-1;
    int q[n];
    rear++;
    q[rear]=h;
    while(front<=rear)
    {
        front++;
        int vertex=q[front];
        if(reach[vertex]==0)
        {

             printf("%d->",vertex);

           reach[vertex]=1;

           for(i=0;i<n;i++)

           {

               if(a[vertex][i]&&!reach[i])

               {
                   rear++;
                   q[rear]==i;
               }
               s1=s1+a[vertex][i];
           }
        }
     }
}



