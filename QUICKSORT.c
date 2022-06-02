#include<stdio.h>
void quick_sort(int arr[],int low,int high)
{
    int p;
    if(low<high)
    {
        p = partition(arr,low,high);
        quick_sort(arr,low,p-1);
        quick_sort(arr,p+1,high);
    }
}
int partition(int arr[],int low,int high)
{
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    int temp;
    do
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
        temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        }

    }while(i<j);

    temp = arr[low];
    arr[low] = arr[j];
     arr[j]= temp;
    return j;
}
int main()
{
    int arr[5]={23,1,7,90,4};
    quick_sort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
}
