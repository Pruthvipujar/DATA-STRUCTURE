#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct bst
{
char name[10];
int id;
float cost;
struct bst *right, *left;
}node;
node *root=NULL, *key;
node *create(node *key)
{
    node*temp;
    temp=key;
    temp->right=NULL;
    temp->left=NULL;
    return (temp);
}
node *insert(node *root, node *key)
{
    if(root==NULL)
    {
        root=create(key);
        return (root);
    }
    else if((key->id)>(root->id))
    {
        root->right=insert(root->right,key);
    }
    else if((key->id)<(root->id))
    {
        root->left=insert(root->left,key);
    }
return (root);
}
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("NAME:%s\tID:%d\tCOST:%f\t",root->name,root->id,root->cost);
        inorder(root->right);
    }
}
void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("NAME:%s\tID:%d\tCOST:%f\t",root->name,root->id,root->cost);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if(root!=NULL)
    {
        printf("NAME:%s\tID:%d\tCOST:%f\t",root->name,root->id,root->cost);
        postorder(root->left);
        postorder(root->right);
    }
}
node *search(node *root,int x)
{
    if(root->id==x)
    {
       printf("NAME:%s\tID:%d\tCOST:%f\n",root->name,root->id,root->cost);
    }
   else if(x>(root->id))
    {
        root->right=search(root->right,x);
    }
    else if(x<(root->id))
    {
        root->left=search(root->left,x);
    }
return (root);
}
node *min ( node *root)
{
     node *current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}
node *delete(node *root,int y)
{
    if(root==NULL)
     return root;
     else if(y>root->id)
     root->right=delete(root->right,y);
     else if(y<root->id)
     root->left=delete(root->left,y);
     else
     {
         if(root->right==NULL)
     {
         node *p;
         p=root->right;
         free(root);
         return p;
     }
      else if(root->left==NULL)
     {
         node *p;
         p=root->left;
         free(root);
         return p;
     }
        node *p;
        p = min (root->right);
        root->id = p->id;
        root->right = delete (root->right, p->id);
}
return root;
}
int level(node *root)
{
    int i=0,flag,q;
    node*cur=root;
    printf("ENTER THE ID OF WHICH YOU WANT TO FIND IT'S LEVEL:");
    scanf("%d",&q);
    while(cur!=NULL)
    {
        i++;
        if(cur->id==q)
        {
            flag=1;
            break;
        }
        else if(cur->id>q)
           cur=cur->left;
        else if(cur->id<q)
           cur=cur->right;
        else if(cur->id==q)
        {
            flag=1;
            break;
        }
    }
     return i;
}

int main()
{
    int y,n,x,m;
    while(1)
    {
        printf("\n1.INSERT\n2.TRAVERSE\n3.SEARCH\n4.DELETE\n5.LEVEL");
        printf("\nENTER THE CHOICE");
        scanf("%d",&n);
        switch(n)
        {
            case 1:key=(node*)malloc(sizeof(node));
                   printf("ENTER THE PRODUCT NAME:");
                   scanf("%s",key->name);
                   printf("ENTER THE ID:");
                   scanf("%d",&key->id);
                   printf("ENTER THE COST:");
                   scanf("%f",&key->cost);
                   root=insert(root,key);
                   break;
            case 2: printf("\n1.INORDER\n2.PREORDER\n3.POSTORDER");
                    printf("\nENTER YOUR CHOICE:");
                    scanf("%d",&m);
                    switch(m)
                    {
                        case 1:inorder(root);
                               break;
                        case 2:preorder(root);
                               break;
                        case 3:postorder(root);
                               break;
                        default: printf("WRONG CHOICE.");
                    }
                    break;
            case 3:printf("\nENTER THE ID TO BE SEARCHED:");
                   scanf("%d",&x);
                   root=search(root,x);
                   break;
            case 4:printf("\nENTER THE ID TO BE DELETED:");
                   scanf("%d",&y);
                   root=delete(root,y);
                   break;
            case 5:printf("LEVEL OF THE NODE:%d",(level(root)-1));
                   break;
            default: printf("WRONG CHOICE.");
        }
    }
}
