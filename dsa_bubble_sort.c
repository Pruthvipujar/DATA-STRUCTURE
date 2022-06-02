#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bubble_sort(int a[20],int n)
{
    int i=0,j=0,c=0;
    for(i=0;i<=n-2;i++)
    {
        for(j=0;j<=n-2-i;j++)
        {
            if(a[j]>a[j+1])
            {
                c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
    }
}
void selection_sort(int a[20],int n)
{
    int i,j,min=0,c=0;
    for(i=0;i<=n-2;i++)
    {
        min=i;
        for(j=i+1;j<=n-1;j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        c=a[min];
        a[min]=a[i];
        a[i]=c;
    }

}
void insertion_sort(int a[20],int n)
{
    int i,j,v,c,m=0;
    for(i=1;i<=n-1;i++)
    {
        v=a[i];
        j=i-1;
        while(j>=0 && a[j]>v)
        {
            c=a[j];
            a[j]=a[j+1];
            a[j+1]=c;
            j=j-1;
        }
        a[j+1]=v;
    }

}

int main()
{
    int a[20],choice,n,i;
    while(1)
    {
        printf("\nenter choice\n");
        printf("1-insert\n2-bubble sort\n3-print\n4-selection sort\n5-insertion sort\n6-exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter how many numbers you want to insert\n");
                   scanf("%d",&n);
                   printf("enter %d numbers\n",n);
                   for(i=0;i<n;i++)
                   {
                       scanf("%d",&a[i]);
                   }
                   break;
            case 2:bubble_sort(a,n);
                   break;
            case 3:printf("the sorted numbers are\n");
                    for(i=0;i<n;i++)
                    {
                        printf("%d  ",a[i]);
                    }
                   break;
            case 4:selection_sort(a,n);
                   break;
            case 5:
                    insertion_sort(a,n);

                   break;
            case 6:exit(1);

        }
    }
}
