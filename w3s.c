//1)	Read an array of numbers with size n and count frequency of positive/negative numbers
/*#include <stdio.h>

void checkneg_pos(int a[20],int n)
{
    int i=0,p=0,ne=0;
    printf("\nEnter the elements=");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }


    printf("\nThe entered elements are");
    for(i=0;i<n;i++)
    printf("\ta[%d]=%d",i,a[i]);


    for(i=0;i<n;i++)
    {
    if(a[i]>0)
        p++;
    else
        ne++;

 }
  printf("\nThe no.of positive numbers are %d",p);
    printf("\nThe no.of negative numbers are %d",ne);
}

int main()
{
    int n,a[20];
    printf("\nEnter the number of elements to be stored=");
    scanf("%d",&n);
    checkneg_pos(a,n);
    return 0;
}
*/


//2)	Read an array of n numbers. Input the number from keyboard (consider it as a key number) and check whether the key number is present in the array or not, also display the index at which the key number is present.

/*#include<stdio.h>

 void check(int a[100],int n)
 {
    int i=0,ele1,ele2,flag=0;
    printf("\nEnter the elements=");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }


    printf("\nThe entered elements are");
    for(i=0;i<n;i++)
    printf("\ta[%d]=%d",i,a[i]);


    printf("\nEnter the element to check=");
    scanf("%d %d",&ele1,&ele2);
     for(i=0;i<n;i++)
     {
        if(a[i]==ele1 || a[i]==ele2)
        {
            flag=1;
            printf("\nElement matched a[%d]=%d and the index number is %d",i,a[i],i);
        }
     }
     if(flag==0)
        printf("\nNo match found");

 }

 int main()
 {
     int a[100],n;
     printf("\nEnter the no.of elements to be stored=");
     scanf("%d",&n);
     check(a,n);
     return 0;
 }
*/
//6.
/*#include<stdio.h>

void read_(int a[100],int n)
{
    int i;
    printf("\nEnter the ranking of the students");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

}
void display(int a[100], int n)
{
    int i;
    printf("\nList if the students along with the ranking:");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\t",i,a[i]);
    }
}

void sort(int a[100],int n)
{
    int i,temp;
    for(i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {

        if(a[j]>a[j+1])
        {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        }

       }
       }
}

int main()
{
    int n,a[100];
    printf("\nEnter the number of students=");
    scanf("%d",&n);
    read_(a,n);
    display(a,n);
    sort(a,n);
    display(a,n);
    printf("\nThe highest rank is a[%d] is %d",n-1,a[n-1]);
    printf("\nThe lowest rank is a[%d] is %d",0,a[0]);

    return 0;

}
*/

/*#include<stdio.h>

void read_(int a[100],int n)
{
    int i;
    printf("\nEnter the marks of the students");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

}
void display(int a[100], int n)
{
    int i;
    printf("\nList if the students along with the marks:");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\t",i,a[i]);
    }
}

void avg_cal(int a[],int n)
{
    int i,sum=0;
    float avg=0;;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    avg=sum/n;
    printf("\nThe class avg. is %f\n",avg);

    printf("\nThe students with marks more than class avg are\n");
    for(i=0;i<n;i++)
    {
        if(a[i]>avg)
        {
            printf("a[%d] is %d",i,a[i]);
        }
}

    printf("\nThe students with marks less than class avg are\n");
        for(i=0;i<n;i++)
    {
        if(a[i]<avg)
        {
            printf("a[%d] is %d",i,a[i]);
        }
}

}

int main()
{
    int n,a[100];
    printf("\nEnter the number of students=");
    scanf("%d",&n);
    read_(a,n);
    display(a,n);
    avg_cal(a,n);
    return 0;

}
*/

//LIBRARY
/*#include<stdio.h>

void read(int a[],int n)
{
    int i;
    printf("\nENTER THE DAYS AFTER THE DEADLINE THE STUDENT HAS RETURNED:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int a[],int n)
{
    int i;
    printf("\nLIST OF STUDENTS WITH THE DAYS AFTER DEADLINE:\n");
    for(i=0;i<n;i++)
    {
        printf("\ta[%d]=%d",i,a[i]);
    }
}

void penalty(int a[],int n)
{
    int i=0,sum=0,amt=0,max,min;
    float avg;
    for(;i<n;i++)
    {

        sum=sum+a[i];
 }
 amt=sum*2;
 printf("\nThe total penalty collected is %d",amt);

    avg=amt/sum;
    printf("\nThe avg. penalty collected is %f",avg);
    i=0;
    max=min=a[i];
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
        else if(a[i]<min)
            min=a[i];
    }
    printf("\nThe max penalty paid by the student is %d",max*2);
     printf("\nThe max penalty paid by the student is %d",min*2);

}
int main()
{
    int n,a[100];
    printf("\nEnter the number of students:");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    penalty(a,n);
    return 0;
}
*/
/*9) C programming for problem solving is a course offered to first semester
 students of KLE Technological University. The course conducts POST TESTs to students
for a maximum of 10 marks. Once all the POST TESTS are conducted, the marks scored by
each student will be announced. Help the course teacher to do the followings.
i)	How many students scored EVEN marks?
ii)	How many students scored ODD marks?
iii)Find, if any student scored 100% marks? Display appropriate message.
iv)	How many students scored 100% marks?
*/
/*#include <stdio.h>
#include <stdlib.h>
struct post_test
{
    int sno;
    int marks;

}pt[100];

void read_marks(struct post_test[],int );
void find_even(struct post_test[],int );
void find_odd(struct post_test[],int );
void find_cent(struct post_test[] , int);



int main()
{
    int n;
    printf("\n Enter the number of students : \t ");
    scanf("%d",&n);
    read_marks(pt,n);
    find_even(pt,n);
    find_odd(pt,n);
    find_cent(pt,n);
    return 0;
}
void read_marks(struct post_test pt[],int b)
{
    int i,j;

    for(i=0,j=1;i<b;i++,j++)
    {
        printf("\nEnter the marks of student %d : ",j);
        scanf("%d",&pt[i].marks);
        pt[i].sno = j;
    }
}
void find_even(struct post_test pt[] ,int b)
{
    int i;
    int even;
    printf("\nThe students scoring even marks are : \n ");
    for(i=0;i<b;i++)
    {
        if(pt[i].marks % 2 == 0)
        {
            even = pt[i].sno;
            printf("\n Student number : %d \t marks : %d ",even, pt[i].marks);
        }
    }
}
void find_odd(struct post_test pt[] ,int b)
{
    int i;
    int odd;
    printf("\nThe students scoring odd marks are : \n");
    for(i=0;i<b;i++)
    {
        if(pt[i].marks % 2 != 0)
        {
            odd = pt[i].sno;
            printf("\n Student number : %d \t marks : %d ",odd, pt[i].marks);
        }
    }
}
void find_cent(struct post_test pt[],int b)
{
    int i;
    int count = 0;
    printf("\nStudents scoring 100 percent are : \n");
    for(i=0;i<b;i++)
    {
        if(pt[i].marks == 10)
        {
            printf("\n Student number : %d ",pt[i].sno);
            count++;
        }
    }
    printf("\n Congrats ! <3 \n");
    printf("\n The total number of students who scored 100 percent  is : %d ",count);


}
*/

/*11) Godrej constructed a new Apartment with N flats, in Hubballi.
 At the end of each month the Secretary of the apartment, collects
 the total units of electricity consumed by each flat.  As per the
 table given below, help Secretary to calculate the total bill to
 be paid by each flat.

Units Consumed	Charges apply
0-100	1.5 Rs/Unit
101-250	2.3 Rs/Unit, for above 100 units
251-600	4.0 Rs/Unit, for above 250 units
Above 600	5.5 Rs/Unit, for above 600 units

*/
/*#include <stdio.h>
#include <stdlib.h>


struct apartment
{
    int flatno;
    int unit;
}ap[100];

void read_unit(struct apartment[],int );
void calc_bill(struct apartment[],int );

int main()
{
    int n ;
    printf("\nEnter the total number of flats in the apartment : \n");
    scanf("%d",&n);
    read_unit(ap,n);
    calc_bill(ap,n);
    return 0;
}
void read_unit(struct apartment ap[],int b)
{
    int i,j;
    for(i=0,j=1;i<b;i++,j++)
    {
        printf("\nEnter the units of flat %d ",j);
        scanf("%d",&ap[i].unit);
        ap[i].flatno = j;
    }
}
void calc_bill(struct apartment ap[],int b)
{
    int i;
    float total_flat;
    total_flat = 0;
    for(i=0;i<b;i++)
    {
        if(ap[i].unit >=0 && ap[i].unit <= 100)
        {
            total_flat = ap[i].unit * 1.5;
            printf("\n Flat number : %d\t Bill : %.2f",ap[i].flatno,total_flat);

        }
        if(ap[i].unit >=101 && ap[i].unit <= 250)
        {
            total_flat = ap[i].unit * 2.3;
            printf("\n Flat number : %d\t Bill : %.2f",ap[i].flatno,total_flat);
        }
        if(ap[i].unit >=251 && ap[i].unit <= 600)
        {
            total_flat = ap[i].unit * 4.0;
            printf("\n Flat number : %d\t Bill : %.2f",ap[i].flatno,total_flat);
        }
        if(ap[i].unit >600)
        {
            total_flat = ap[i].unit * 5.5;
            printf("\n Flat number : %d\t Bill : %.2f",ap[i].flatno,total_flat);
        }

    }

}*/

/*12)	Write a modular c program to perform the following:
 a) Read 1D array
 b) Display 1D array
 c) To find the maximum digit in every element of an array and
 find sum of all maximum digits.
Write a suitable main function to call the above user defined
functions
Example:
Input: arr[3] = {132,458,732}
Output: Maximum digit in a[0]=3
Maximum digit in a[1]=8
Maximum digit in a[2]=7
Sum=3+8+7=18
*/
/*#include <stdio.h>
#include <stdlib.h>
void read_array(int [],int );
void find_max_dig(int[],int);
void print_array(int [] ,int);

int main()
{
    int a[100];
    int n;
    printf("\n Enter the size of array : ");
    scanf("%d",&n);
    read_array(a,n);
    print_array(a,n);
    find_max_dig(a,n);

    return 0;
}
void read_array(int a[],int b)
{
    int i;
    printf("\nEnter %d array elements: \n ",b);

    for(i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
    }
}
void print_array(int a[],int b)
{
    int i;
    printf("{");
    for(i=0;i<b;i++)
    {
        printf(" %d \t ",a[i]);

    }
    printf("}");
}
void find_max_dig(int a[],int b)
{
    int i,s;
    int first,middle,last,sum,largest;
    sum = 0;

    for(i=0;i<b;i++)
    {
        first = a[i]/100;
        s  = a[i]%100;
        last = s % 10;
        middle = s/10;
        if(first > middle && first > last)
            largest = first;
        if(middle > first && middle > last)
            largest = middle;
        if(last > first && last > middle)
            largest = last;

        printf("\n Maximum digit in a[%d] is %d ",i,largest);
        sum = sum + largest;

    }
    printf("\nSum of largest is : %d ",sum);



}
*/

/*13)	Write a modular C program to read a list of n random numbers
 and check whether each element of an array is perfect number or not.
*/

/*#include <stdio.h>
#include <stdlib.h>
void find_perfect(int [],int );
void read_array(int [],int );

int main()
{
    int a[100];
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    read_array(a,n);
    find_perfect(a,n);

    return 0;
}
void read_array(int a[],int b)
{
    int i;
    printf("\nEnter %d elements : \n",b);
    for(i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
    }
}
void find_perfect(int a[],int b)
{
    int i,j,temp;
    for(i=0;i<b;i++)
    {
        int sum=0;
        temp=a[i];
        for(j=1;j<=(temp-1);j++)
       {
        if(temp%j==0)
        {
            sum=sum+j;
        }
       }
      if(sum==temp)
      {
          printf("\n %d is perfect\n",temp);
      }
      else{
        printf("\n %d is not perfect \n",temp);

      }
    }
}*/

/*14)	Find equilibrium index in an array. An index is equilibrium
, where sum of right side elements is equal to sum of left side elements.
Ex: A={-7,1,5,2,-4,3,0}
Here '3' is equilibrium index since A[0]+A[1]+A[2] = A[4]+A[5]+A[6].
*/
/*#include <stdio.h>
#include <stdlib.h>

int find_index(int [], int );
int main()
{
        int a[100];
        int n,eqi;
        printf("\nEnter array size : ");
        scanf("%d",&n);

        printf("\nInput the array elements : ");
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        eqi = find_index(a,n);
        printf("\nEquilibrium Index : %d\n", eqi);
        return 0;
}


int find_index(int a[], int b)
{
int i, j;
int l_sum, r_sum;

for (i = 0; i < b; ++i)
    {

        l_sum = 0;
        for (j = 0; j < i; j++)
        l_sum += a[j];

        r_sum = 0;
        for (j = i + 1; j < b; j++)
        r_sum += a[j];

        if (l_sum == r_sum)
        return i;
    }

    return -1;
}*/

/*15)	Calculate the minimum number of platforms required for a
railway station so that no train waits. Given arrival and departure
 of all trains (in 24Hr format) in separate arrays.
 	  Ex: arr[] = {9.00, 9.40, 9.50, 11.00, 15.00, 18.00}
		dep[] = {9:10, 12.00, 11.20, 11.30, 19.00, 20.00}
*/
/*#include <stdio.h>
#include <stdlib.h>
void read_arr(int arr[],int n)
{
    int i;
    printf("\nEnter arrival times of train : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void read_dep(int dep[],int n)
{
    int i;
    printf("\nEnter departure times of train : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&dep[i]);
    }
}
int findPlatform(int arr[], int dep[], int n)
{


    int plat_needed = 1, result = 1;
    int i = 1, j = 0;


    for (int i = 0; i < n; i++) {

        plat_needed = 1;

        for (int j = i + 1; j < n; j++) {

            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i]))
                plat_needed++;
        }

        if(plat_needed > result)
        {
            result = plat_needed;
        }
    }

    return result;
}

int main()
{
    int n;
    printf("\nEnter total number of arrivals and departures of train : ");
    scanf("%d",&n);
    int p_req;
    int arr[100], dep[100];
    read_arr(arr,n);
    read_dep(dep,n);
    p_req  = findPlatform(arr,dep,n);
    printf("\nThe total number of platforms required are : %d",p_req);
    return 0;
}*/

/*
16)	Write a modular C program to reverse an array.
*/
/*#include <stdio.h>
#include <stdlib.h>
void read_array(int [],int );
void reverse_array(int [],int);
void print_array(int [],int );

int main()
{
    int n;
    int a[100];
    printf("\nEnter array size : \t");
    scanf("%d",&n);
    read_array(a,n);
    print_array(a,n);
    reverse_array(a,n);
    print_array(a,n);
    return 0;
}
void read_array(int a[],int n)
{
    int i;
    printf("\nEnter %d elements  : ",n);
    for(i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void print_array(int a[],int n)
{
    int i;

    printf("\nThe array elements are : \n");
    for(i=0;i<n;i++)
    {
        printf("\t%d\t",a[i]);
    }
}
void reverse_array(int a[],int n )
{
    int i;
    int temp;
    for(i = 0 ; i < n/2 ; i++)
    {
        temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
}
*/
/*
17)	Read the 2 sets(2 arrays) of numbers with same size n.
 Then exchange the content of two sets.
*/
/*#include <stdio.h>
#include <stdlib.h>
void read_array(int [],int );
void print_array(int [],int );
void exchange_arrays(int [],int [],int );


int main()
{
    int n;
    int a[100],b[100];
    printf("Enter array elements : ");
    scanf("%d",&n);
    printf("\nEnter first array : \n");
    read_array(a,n);
    printf("\nEnter second array : \n");
    read_array(b,n);
    printf("\n Displaying arrays before swapping : \n");
    printf("\n First array : \n");
    print_array(a,n);
    printf("\n Second array : \n");
    print_array(b,n);
    exchange_arrays(a,b,n);
    printf("\n \n Results after swapping arrays : \n");
    printf("\n First array : \n");
    print_array(a,n);
    printf("\n Second array : \n");
    print_array(b,n);
    return 0;
}

void read_array(int a[],int n)
{
    int i;
    printf("\nEnter %d array elements : ",n);


    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void print_array(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\t%d\t",a[i]);
    }
}

void exchange_arrays(int a[],int b[],int n)
{
    int i;
    int temp[n];
    for(i=0;i<n;i++)
    {
        temp[i]= a[i];
        a[i] = b[i];
        b[i] = temp[i];
    }
}
*/
/*18)	Read an array of numbers with size n and another number m. then for every element
print the sum of m next numbers in sequence from array.
*/

/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void read_array(int a[],int n);
void add_m(int a[],int n,int m);
int main()
{
   int a[100],n,m;
    printf("Value of n:\n");
    scanf("%d",&n);
     printf("Value of m:\n");
    scanf("%d",&m);
    read_array(a,n);
    add_m(a,n,m);
    return 0;
}
void read_array(int a[],int n)
{   int i;
    printf("enter no.s\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void add_m(int a[],int n,int m)
{
    int i=0,j=0;
    for(i=0;i<n-m;i++)
    {
         int sum=0;
        for(j=i+1;j<m+i+1;j++)
    {
        sum=sum+a[j];
    }
     printf("for position %d, sum= %d\n",i+1,sum);
    }
}*/








