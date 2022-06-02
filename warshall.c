#include<stdio.h>
#include<stdlib.h>
#define INF 99999

int distance[10][10] = { {0,1,0,0},
                         {1,0,1,1},
                         {0,1,0,0},
                         {0,1,0,0}
                       };

int n = 4;

int max(int a, int b)
{
    if(a<b)
        return b;
    else
        return a;
}
void warshall()
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
               distance[i][j] = max(distance[i][j],distance[i][k]&&distance[k][j]);
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
    warshall();

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

