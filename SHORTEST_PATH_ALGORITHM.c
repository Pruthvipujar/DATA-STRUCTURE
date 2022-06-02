#include<stdio.h>
#include<stdlib.h>
int find(int arr[10][10],int a,int b,int n )
{
    if(arr[a][b]==arr[b][a])
        return 1;
    else
        return 0;
}
void union_arr(int arr[],int a,int b,int n)
{
    int i;
    arr[a]=arr[b];
    int temp=arr[a];
    for(i=0;i<n;i++)
    {
        if(arr[i]==temp)
            arr[i]=arr[b];
    }
}
int main()
{
    int z,i,j,n,a,b,arr[10][10];
    int min 100;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    printf("weighted matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
        scanf("%d",&arr[i]);
        }
    }

    printf("edges with minimum weights are:\n");
    while(z<n)
    {


    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(arr[][]<min)
            {
                min=arr[i][j];
                a=u=i;
                b=v=j;
            }
        }
    }
    }
    u=find(u);
    v=find(v);
    if(union_arr(u,v))
    return 0;
}
