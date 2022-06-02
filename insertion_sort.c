#include<stdio.h>
#include<stdlib.h>


void insertionsort(int a[],int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];
        j=i-1;
        while(j>=0&&a[j]>t)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
}
void printArray(int a[],int size)
{
    for(int i =0;i<size;i++)
    {
        printf(" %d ",a[i]);
    }
}
int main()
{
    int i,n,data[20];
    printf("Enter the array size\n");
    scanf("%d",&n);
    printf("enter the array elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&data[i]);
    insertionsort(data,n);
    printf("sorted array  ");
    printArray(data,n);
    return 0;

}
