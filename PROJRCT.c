#include<stdio.h>
#include<stdlib.h>
struct details
{
  char name[20];
  int uniqueid_no;
  char address[20];
  int phone_no;
};
int main()
{
  FILE *fp;
  struct details d[10];
  int i;
  fp=fopen("details_city.txt","w");
  if(fp==NULL)
  {
      printf("error");
      exit(0);
  }

  printf("\nCITIZENS DETAILS\n");

for(i=0;i<2;i++)
{
    printf("\n%d Name=",i+1);
    scanf("%s",d[i].name);
    fprintf(fp,"%s",d[i].name);

    printf("\n%d Unique ID=",i+1);
    scanf("%d",&d[i].uniqueid_no);


    printf("\n%d Address=",i+1);
    scanf("%s",d[i].address);


    printf("\n%d Phone number=",i+1);
    scanf("%d",&d[i].phone_no);


}
fwrite(d,sizeof(struct details),10,fp);
printf("\nDATA IS STORED\n");
fclose(fp);
}
