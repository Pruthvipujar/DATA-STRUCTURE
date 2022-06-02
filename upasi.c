#include<stdio.h>
#include<stdlib.h>
    struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;

void create()
{
    struct Node *newnode,*temp;
    temp=head;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("enter data\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==0)
    {
        head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void display()
{
    struct Node *temp;
     if(head == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
    temp=head;
    printf("\n printing values\n");
    while(temp!=NULL)
    {
        printf("\t%d",temp->data);
        temp=temp->next;
    }
    }

}
int main()
{
    head=0;
    int choice;
    printf("enter choice\n");
    while(1)
    {
        printf("\n1.create\t 2.display\t 3.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:create();
            break;
            case 2:display();
            break;
            case 3:exit(0);
            break;
        }

    }
}
