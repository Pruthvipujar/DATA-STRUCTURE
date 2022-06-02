#include<stdio.h>
#include<stdlib.h>
typedef struct details
{
  char name[20];
  int uniqueid_no;
  char address[20];
  int phone_no;
}CITY;
int main()
{
  FILE *fp;
CITY d[10];
  int i;
  fp=fopen("citizen_details.txt","r");
while(!feof(fp))
    {
       fscanf(fp,"%s %d %s %d",d[i].name,&d[i].uniqueid_no,d[i].address,&d[i].phone_no);
      printf("\n%s %d %s %d\n",d[i].name,d[i].uniqueid_no,d[i].address,d[i].phone_no);
    }
    fclose(fp);


}


