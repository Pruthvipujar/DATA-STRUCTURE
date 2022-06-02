#include<stdio.h>
#include<stdlib.h>

typedef struct details
{
  char name[20];
  int uniqueid_no;
  char address[20];
  int phone_no;
}CITY;
void write(FILE *,int,CITY *);

int main()
{
    CITY d[10];
    int n;
    FILE *fp;
    printf("enter number of citizen\n");
    scanf("%d",&n);
    write(fp,n,d);
    return 0;
}
void write(FILE *fp,int n,CITY *a)
{
    int i;
    fp=fopen("citizen_details.txt","w");
    for(i=1;i<=n;i++)
    {
        printf("Enter the Name  Unique_ID  Address Phone_no\n");
        scanf("%s  %d  %s  %d",a[i].name,&a[i].uniqueid_no,a[i].address,&a[i].phone_no);
        fprintf(fp,"%s  %d  %s  %d\n",a[i].name,a[i].uniqueid_no,a[i].address,a[i].phone_no);

    }
    fclose(fp);
}
