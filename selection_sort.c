#include<stdio.h>
#include<stdlib.h>

void selectionsort(int a[],int n)
{
    int i,j,max,temp;
    for(i=0;i<n;i++)
    {
        max=i;
        for(j=i+1;j<n;j++)
        {

            if(a[j]>a[max])
            {
                max=j;
                temp=a[i];
                a[i]=a[max];
                a[max]=temp;
            }
        }
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
    selectionsort(data,n);
    printf("sorted array  ");
    printArray(data,n);
    return 0;

}

