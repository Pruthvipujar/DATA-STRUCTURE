#include<stdio.h>
#include<stdlib.h>
#define INF 99999

int distance[10][10] = { {0,5,INF,10},
                         {INF,0,3,INF},
                         {INF,INF,0,1},
                         {INF,INF,INF,0}
                       };

int n = 4;

void floyd()
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
               if(distance[i][j] > distance[i][k]+distance[k][j])
                 distance[i][j] = distance[i][k]+distance[k][j];
            }
        }
    }
}
int main()
{
    int i,j;
    printf("Your input distance matrix is:\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d ",distance[i][j]);
        }
    }
    floyd();

    printf("Your output distance matrix is:\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d ",distance[i][j]);
        }
    }
    return(0);
}
