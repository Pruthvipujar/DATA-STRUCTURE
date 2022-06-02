#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void read(int a[],int n)
{
int i,num;
srand(time(0));
printf("\nTHE NUMBERS ARE:\n");
for(i=0;i<n;i++)
{
a[i]=rand()%100;
printf("NUM %d=%d\n",i+1,a[i]);
}
}
void display(int a[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d\t",a[i]);
}
void swap(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
}
void bubblesort(int a[],int n)
{
int i,j;

for(i=0;i<n-1;i++)
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
swap(&a[j],&a[j+1]);
}
}
void selectionsort(int a[],int n)
{
    int i,j,max;
    for(i=0;i<n;i++)
    {
        max=i;
        for(j=i+1;j<n;j++)
        {

            if(a[j]>a[max])
            {
                max=j;
                swap(&a[max],&a[i]);
            }
        }
    }
}

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

void mergesort(int a[],int l,int r)
{
    int m;
   if(l<r)
   {
    m=l+(r-1)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,l);
    merge(a,l,m,r);
   }
}
void merge(int a[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = a[l + i];
for (j = 0; j < n2; j++)
R[j] = a[m + 1+ j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
a[k] = L[i];
i++;
}
else
{
a[k] = R[j];
j++;
}
k++;
}
while (i < n1)
{
a[k] = L[i];
i++;
k++;
}
while (j < n2)
{
a[k] = R[j];
j++;
k++;
}
}

void quicksort(int a[],int first,int last)
{
int i, j, pivot, temp;

if(first<last)
{
pivot=first;
i=first;
j=last;
clock_t start_t, end_t, total_t;

while(i<j)
{
while(a[i]<=a[pivot]&&i<last)
i++;
while(a[j]>a[pivot])
j--;
if(i<j){
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
temp=a[pivot];
a[pivot]=a[j];
a[j]=temp;
quicksort(a,first,j-1);
quicksort(a,j+1,last);
}
}
int main()
{
    int a[100];
    int c,n;
    clock_t start_t, end_t, total_t;
    srand(time(0));
    n=rand()%10;
    printf( "\nNUMBER OF ELEMENTS:%d",n);
    read(a,n);
    printf("\nBEFORE SORTING:");
    display(a,n);
    printf("\n1.BUBBLE SORT\n2.INSERTION SORT\n3.SELECTION SORT\n4.MERGE SORT\n5.QUICK SORT");
    printf("\nENTER THE TYPE OF SORTING:");
    scanf("%d",&c);

    switch(c)
    {
        case 1: start_t = clock();
                printf("Starting of the program, start_t = %ld\n", start_t);
                printf("Going to scan a big loop, start_t = %ld\n", start_t);
                bubblesort(a,n);
                 end_t = clock();
                printf("End of the big loop, end_t = %ld\n", end_t);
                total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                printf("Total time taken by CPU: %f\n", total_t  );
                printf("\nAFTER SORTING:");
                display(a,n);
                break;
        case 2: start_t = clock();
                printf("Starting of the program, start_t = %ld\n", start_t);
                printf("Going to scan a big loop, start_t = %ld\n", start_t);
                selectionsort(a,n);
                 end_t = clock();
                printf("End of the big loop, end_t = %ld\n", end_t);
                total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                printf("Total time taken by CPU: %f\n", total_t  );
                printf("\nAFTER SORTING:");
                display(a,n);
                break;
        case 3: start_t = clock();
                printf("Starting of the program, start_t = %ld\n", start_t);
                printf("Going to scan a big loop, start_t = %ld\n", start_t);
                insertionsort(a,n);
                 end_t = clock();
                printf("End of the big loop, end_t = %ld\n", end_t);
                total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                printf("Total time taken by CPU: %f\n", total_t  );
                printf("\nAFTER SORTING:");
                display(a,n);
                break;
        case 4:  start_t = clock();
                printf("Starting of the program, start_t = %ld\n", start_t);
                printf("Going to scan a big loop, start_t = %ld\n", start_t);
                 mergesort(a,0,n-1);
                 end_t = clock();
                printf("End of the big loop, end_t = %ld\n", end_t);
                total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                printf("Total time taken by CPU: %f\n", total_t  );
                printf("\nAFTER SORTING:");
                display(a,n);
                break;
        case 5: start_t = clock();
                printf("Starting of the program, start_t = %ld\n", start_t);
                printf("Going to scan a big loop, start_t = %ld\n", start_t);
                quicksort(a,0,n-1);
                 end_t = clock();
                printf("End of the big loop, end_t = %ld\n", end_t);
                total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
                printf("Total time taken by CPU: %f\n", total_t  );
                printf("\nAFTER SORTING:");
                display(a,n);
                break;
        default: printf("WRONG CHOICE.");
    }

}
