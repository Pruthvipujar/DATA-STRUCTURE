#include <stdio.h>
#include <stdlib.h>


int reach[5],n;
int a[5][5];
void main()
{
    int i,j;
    printf("\nEnter number of vertices\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
        for(j=1;j<=n;j++)
        {
            printf("\nIf edge exists between %d and %d, enter 1 else 0\n",i,j);
            scanf("%d",&a[i][j]);
        }
    }
for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
           if(a[i][j]==1)
           {
            printf("\nThere is an edge between %d and %d\n",i,j);
           }

        }
    }
    for(i=1;i<=n;i++)

        reach[i]=0;
        dfs(1);


}
void dfs(int v)
{
    int i;
    reach[v]=1;
    for(i=1;i<=n;i++)
    {

    if(a[v][i] && !reach[i])
            {
                printf("\n %d->%d",v,i);
                dfs(i);
            }
    }
}
