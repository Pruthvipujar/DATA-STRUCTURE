#include<stdio.h>
#include<conio.h>
typedef struct hospital
{
    char hospital_name[10];
    char location[10];
    char doctor_name[10];
}PLACE;

int main()
{
FILE *fp1;
PLACE f[10];
int i;
  fp1=fopen("hospital_details.txt","r");
while(!feof(fp1))
    {
       fscanf(fp1,"%s %s %s",f[i].hospital_name,f[i].location,f[i].doctor_name);
      printf("\n%s %s %s\n",f[i].hospital_name,f[i].location,f[i].doctor_name);
    }
    fclose(fp1);
}
