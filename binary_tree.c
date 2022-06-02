#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int parentnode=0,childnode=0;
struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
};
struct treenode *create(int data)
{
    struct treenode *temp;
    temp=((struct treenode*) malloc(sizeof(struct treenode)));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;

};
struct treenode *insertion(struct treenode *temp,int data)
{
    if(temp==NULL)
    {
        temp=create(data);
        return temp;
    }
    else if(data<(temp->data))
    {
        temp->left=insertion(temp->left,data);
    }
    else if(data>(temp->data))
    {
        temp->right=insertion(temp->right,data);
    }
    return temp;
};
struct treenode *traverse(struct treenode *temp)
{
    if(temp!=NULL)

    {
        traverse(temp->left);
        printf("%3d",temp->data);
        traverse(temp->right);
         if(temp->left==NULL && temp->right==NULL)
        {
            childnode+=1;
        }
        if(temp->left==NULL || temp->right==NULL)
        {
            parentnode+=1;
        }

    }
    return temp;
}

struct treenode *search(struct treenode *temp,int key)
{
    if(temp->data==key)
    {
printf("Key %d found\n",key);
        return temp;
    }
    else if(key<(temp->data))
    {
        temp->left=insertion(temp->left,key);
    }
    else if(key>(temp->data))
    {
        temp->right=insertion(temp->right,key);
    }
    return temp;
}
struct treenode *minimum(struct treenode *temp)
{
  struct treenode *node=temp;
  while(node->left!=NULL)
  {
      node=node->left;
  }
  printf("Minimum is %d",node->data);
  return temp;
}
struct treenode *maximum(struct treenode *temp)
{
  struct treenode *node=temp;
  while(node->right!=NULL)
  {
      node=node->right;
  }
  printf("Maximum is %d",node->data);
  return temp;
}

int main()
{
struct treenode *head=NULL;
int data,key,choice,count=0;
for(;;)
{
printf("\n 1-INSERT and 2-DISPLAY 3-NUMBER OF NODES 4-SEARCH 5-NUMBER OF MINIMUM NODES 6-NUMBER OF MAXIMUM NODE 7-NUMBER OF PARENT NODE 8-NUMBER OF CHILD NODE\n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("Enter the data\n");
        scanf("%d",&data);
        count++;
        head=insertion(head,data);
        break;
case 2: head=traverse(head);
        break;
case 3: printf("no of nodes:%d",count);
        break;
case 4:printf("Enter the number to be searched\n");
        scanf("%d",&key);
        head=search(head,key);
        break;
case 5:head=minimum(head);
       break;
case 6:head=maximum(head);
       break;
case 7:printf("Number of Parent node=%d",parentnode);
break;
case 8:printf("Number of child node=%d",childnode);
break;
}
}
return 0;
}
