#include<stdio.h>
int a[100][100];
int reach[100];
int n;
int sum=0;
int sum1=0;
int main()
{
    int e,n,i,j,u,v,ch,z,c1,c2,w;
    printf("enter the no of houses\n");
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
    printf("enter the total no of connections\n");

    scanf("%d",&e);



    for(i=0;i<e;i++)

    {

        printf("Enter the starting house of an edge\n");

        scanf("%d",&u);



        printf("enter the ending vertex of an edge\n");

        scanf("%d",&v);

        printf("Enter the distance of the house from source\n");

        scanf("%d",&w);
        a[u][v]=w;

        a[v][u]=w;

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

        printf("Enter 1 to BFS\n 2-DFS\n");

        scanf("%d",&ch);



        switch(ch)

        {

            case 1:bfs(0,n);

                    printf("TOTAL distance using bfs is %d\n",sum1);

                   c2=sum1*100;

                   printf("Total cost by bfs is %d\n",c2);

                   break;









            case 2: for(int i=0;i<=n;i++)

                    {

                        reach[i]=0;

                    }



                    dfs(0,n);

                    printf("total distance usnig dfs %d\n",sum1);

                    c1=sum1*100;

                    printf("total cost by dfs is %d\n",c1);

                    break;



                    default : return 0;

                    break;

        }

    }

}

void dfs(int z, int n)

{

    int i;

    if(reach[z]==0)

    {

        printf("%d->",z);

        reach[z]=1;

        for(i=0;i<n;i++)

        {

            if(a[z][i]&&!reach[i])

            {

                dfs(i,n);

            }
        }

    }

}

void bfs(int z,int n)

{

    sum1=0;

    int i;

    for(i=0;i<n;i++)

    {reach[i]=0;}

    int front=-1;

    int rear=-1;

    int q[n];



    rear++;

    q[rear]=z;

    while(front<=rear)

    {

        front++;

       int node= q[front];

       if(reach[node]==0)

       {

           printf("%d->",node);

           reach[node]=1;

           for(i=0;i<n;i++)

           {

               if(a[node][i]&&!reach[i])

               {

                   rear++;

                   q[rear]=i;

               }

                sum1=sum1+a[node][i];

           }

       }

    }

}
