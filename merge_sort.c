#include<stdio.h>
#include<stdlib.h>


void merge(int a[],int l,int m,int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int right[n2],left[n1];
    for(int i=0;i<n1;i++)
    {
        left[i]=a[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        right[j]=a[j+m+1];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<right[j])
        {
            a[k]=left[i];
            i=i+1;
        }
        else
        {
            a[k]=right[j];
            j=j+1;
        }
        k=k+1;
    }

    while(i<n1)
    {
        a[k]=left[i];
        i=i+1;
        k=k+1;
    }
    while(j<n2)
    {
        a[k]=right[j];
        j=j+1;
        k=k+1;
    }

}

void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int m = (l+(r-1))/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}


int main()
{
    int n=0;
    int a[10];
    int i;
    printf("size of array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return(0);
}
