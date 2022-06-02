/*3) There is a company NI Infotech which has N number of employees working in it.
 NI Infotech gives bonus to its employees according to the following terms and conditions
  i) if  7<experience >5 bonus = 10% of basic ;
  ii) if  10<experience >8 bonus = 20% of basic ;
  iii) if experience >10  bonus = 30% of basic ;
Calculate the bonus for N employees and display the salary of N employees after getting bonus.
*/
/*#include <stdio.h>
#include <stdlib.h>


struct employee
{
    int basic;


    int experience;
    float salary;
}employee[50];


void read_employee(struct employee[] ,int);
void calculate_salary(struct employee[] , int);

int main()
{
    int n;

    printf("Enter the total number of employees : \n");
    scanf("%d",&n);
    read_employee(employee,n);

    return 0;
}
void read_employee(struct employee employee[50],int b)
{
    int i=1;
    int j = b;


    printf("\n Enter %d employee details : \n ",j);
    while(j!=0)
    {
        printf("\n Enter experience of employee %d   : ",i);
        scanf("%d",&employee->experience);


        j--;
        i++;

    }
    calculate_salary(employee,b);

}
void calculate_salary(struct employee employee[50], int b)
{

    if(employee -> experience >= 5 || employee -> experience <= 7)
    {
        employee->basic = 10600;
        employee->salary = employee->basic + (employee->basic * 0.10f);

        printf("\n\n Basic : %d\n Salary after adding Bonus: %.2f \n",employee->basic,employee->salary);
    }


    if(employee -> experience>=8 || employee->experience<=10)
    {
        employee->basic = 21300;
        employee->salary = employee->basic + (employee->basic * 0.20f);

        printf("\n\n Basic : %d\n Salary after adding Bonus: %.2f \n",employee->basic,employee->salary);
    }
    if(employee->experience>10)
    {
        employee->basic = 32100;
        employee->salary = employee->basic + (employee->basic * 0.30f);

        printf("\n\n Basic : %d\n Salary after adding Bonus: %.2f \n",employee->basic,employee->salary);
    }


}*/



    /*for(i=0;i<b;i++,j++)
    {
        printf("\nSalary details of employee %d",j);
        printf("\n\n Basic : %d\n Salary after adding Bonus: %.2f \n",employee->basic,employee->salary);
    }*/


/*4.In a class there are 10 students. Course teacher of “DS with Applications ”
wants to calculate the class average and also count total number of students
who scored above and below class average. Most of the students IQ is very high.
Help course teacher to solve the above problem.
*/
/*#include <stdio.h>
#include <stdlib.h>

struct student
{
    int sno;

    int marks;


}st[10];
void read_student(struct student[] ,int);

void find_average(struct student[] ,int );
void find_below_av(struct student[] ,int , float );
void find_above_av(struct student[] ,int, float );


int main()
{

    int n =10;
    read_student(st, n);
    find_average(st,n);
    return 0;


}

void read_student(struct student st[],int b){
    int i;
    int max_marks = 0;
    printf("\n Enter the maximium marks to be obtained  : ");
    scanf("%d",&max_marks);
    for(i=0;i<b;i++)
    {
        st[i].sno = i + 1;

        printf("Enter the marks of student %d : ",i+1);
        scanf("%d",&st[i].marks);
    }
}
void find_average(struct student st[], int b)
{
    int sum = 0;
    float average = 0 ;


    int i;
    for(i=0;i<b;i++)
    {
        sum = sum + st[i].marks;
    }
    average = (float)(sum / b);

    printf("\nThe class average is  %f",average);
    find_above_av(st,b,average);
    find_below_av(st,b,average);
}


void find_below_av(struct student st[] ,int b, float av)
{
    int i ;
    printf("Students scored below average : ");
    for(i = 0; i<b ; i++)
    {
        if(st[i].marks < av)
        {
            printf("\n Student number : %d \n Marks obtained : %d \n",st[i].sno,st[i].marks);
        }
    }
}
void find_above_av(struct student st[] ,int b, float av)
{
    int i ;
    printf("\n \n Students scored above average : ");
    for(i = 0;i<b;i++)
    {
        if(st[i].marks > av)
        {
            printf("\n Student number : %d \n Marks obtained : %d \n",st[i].sno,st[i].marks);
        }
    }
}
*/
