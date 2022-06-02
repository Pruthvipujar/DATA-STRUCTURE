#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef struct Account
{
    char name[10];
    int account_no;
    char acc_type[5];
    float balance;
    struct Account *left;
    struct Account *right;
}node;

typedef struct Account_copy
{
    char name[10];
    int account_no;
    char acc_type[5];
    float balance;
}acc_copy;

node *insert(node *temp,char name[],int account_no,char acc_type[],float balance)
{
    if(temp==NULL)
    {
        node *cur=(node *)malloc(sizeof(node));
        cur->left=NULL;
        cur->right=NULL;
        strcpy(cur->name,name);
        strcpy(cur->acc_type,acc_type);
        cur->balance=balance;
        cur->account_no=account_no;
        return cur;
    }
    else
    {
        if(account_no<temp->account_no)
        temp->left=insert(temp->left,name,account_no,acc_type,balance);
        else if(account_no>temp->account_no)
        temp->right=insert(temp->right,name,account_no,acc_type,balance);
        else
        return temp;
    }
    return temp;
}
int height(node *temp)
{
    if(temp==NULL)
    return 0;
    else
    {
        int left=height(temp->left);
        int right=height(temp->right);
        return left>right?left+1:right+1;
    }
}
acc_copy in_pre(node *temp)
{
    node *cur=temp;
    while(cur->right!=NULL)
    cur=cur->right;
    acc_copy a;
    strcpy(a.acc_type,cur->acc_type);
    strcpy(a.name,cur->name);
    a.account_no=temp->account_no;
    a.balance=cur->balance;
    return a;
}
acc_copy in_succ(node *temp)
{
    node *cur=temp;
    while(cur->left!=NULL)
    cur=cur->left;
    acc_copy a;
    strcpy(a.acc_type,cur->acc_type);
    strcpy(a.name,cur->name);
    a.account_no=cur->account_no;
    a.balance=cur->balance;
    return a;
}
node *delete_bst(node *temp,int account_no)
{
    if(temp==NULL)
    return NULL;
    else if(temp->left==NULL && temp->right==NULL && temp->account_no==account_no)
    return NULL;
    else
    {
        if(account_no<temp->account_no)
        temp->left=delete_bst(temp->left,account_no);
        else if(account_no>temp->account_no)
        temp->right=delete_bst(temp->right,account_no);
        else
        {
            int lh=height(temp->left);
            int rh=height(temp->right);
            if(lh>rh)
            {
                acc_copy in_pred=in_pre(temp->left);
                strcpy(temp->acc_type,in_pred.acc_type);
                strcpy(temp->name,in_pred.name);
                temp->account_no=in_pred.account_no;
                temp->balance=in_pred.balance;
                temp->left=delete_bst(temp->left,temp->account_no);
            }
            else
            {
                acc_copy in_succe=in_succ(temp->left);
                strcpy(temp->acc_type,in_succe.acc_type);
                strcpy(temp->name,in_succe.name);
                temp->account_no=in_succe.account_no;
                temp->balance=in_succe.balance;
                temp->right=delete_bst(temp->right,temp->account_no);
            }
            return temp;
        }
        return temp;
    }
}
int search(node *temp,int account_no)
{
    if(temp==NULL)
    {
        printf("\nSearch Unsuccesfull\n");
    }
    else
    {
        int left=0;
        int right=0;
        if(account_no<temp->account_no)
        left=search(temp->left,account_no);
        else if(account_no>temp->account_no)
        right=search(temp->right,account_no);
        else
        {
            printf("\nName : %s\n",temp->name);
            printf("Account Number : %d\n",temp->account_no);
            printf("Account type : %s\n",temp->acc_type);
            printf("Balance : %f\n",temp->balance);
            return 1;
        }
        if(left==1 || right==1)
        return 1;
        else
        return 0;
    }
}
void inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("Name:%s\tAccount_no:%d\tAcc_type:%s\tBalance:%f\n",temp->name,temp->account_no,temp->acc_type,temp->balance);
        inorder(temp->right);
    }
}
void preorder(node*temp)
{
    if(temp!=NULL)
    {
    printf("Name:%s\tAccount_no:%d\tAcc_type:%s\tBalance:%f\n",temp->name,temp->account_no,temp->acc_type,temp->balance);
    preorder(temp->left);
    preorder(temp->right);
    }
}
void postorder(node*temp)
{
    if(temp!=NULL)
    {
    postorder(temp->left);
    postorder(temp->right);
    printf("Name:%s\tAccount_no:%d\tAcc_type:%s\tBalance:%f\n",temp->name,temp->account_no,temp->acc_type,temp->balance);
    }
}
int max_bal_acc(node *temp)
{
    if(temp==NULL)
    return INT_MIN;
    else
    {
        int left=max_bal_acc(temp->left);
        int right=max_bal_acc(temp->right);
        int root_bal=temp->balance;
        if(root_bal>left && root_bal>right)
        return root_bal;
        else if(left>root_bal && left>right)
        return left;
        else
        return right;
    }
}
void print_max_bal(node *temp,int max_bal)
{
    if(temp==NULL)
    return;
    else
    {
        print_max_bal(temp->left,max_bal);
        if(temp->balance==max_bal)
        {
            printf("\nName : %s\n",temp->name);
            printf("Account Number : %d\n",temp->account_no);
            printf("Account type : %s\n",temp->acc_type);
            printf("Balance : %f\n",temp->balance);
        }
        print_max_bal(temp->right,max_bal);
    }
}
int min_bal_acc(node *temp)
{
    if(temp==NULL)
    return INT_MAX;
    else
    {
        int left=min_bal_acc(temp->left);
        int right=min_bal_acc(temp->right);
        int root_bal=temp->balance;
        if(root_bal<left && root_bal<right)
        return root_bal;
        else if(left<root_bal && left<right)
        return left;
        else
        return right;
    }
}
void print_min_bal(node *temp,int min_bal)
{
    if(temp==NULL)
    return;
    else
    {
        print_min_bal(temp->left,min_bal);
        if(temp->balance==min_bal)
        {
            printf("\nName : %s\n",temp->name);
            printf("Account Number : %d\n",temp->account_no);
            printf("Account type : %s\n",temp->acc_type);
            printf("Balance : %f\n",temp->balance);
        }
        print_min_bal(temp->right,min_bal);
    }
}
void print_less_than_500(node *temp)
{
    if(temp==NULL)
    return;
    else
    {
        print_less_than_500(temp->left);
        if(temp->balance<500)
        {
            printf("\nName : %s\n",temp->name);
            printf("Account Number : %d\n",temp->account_no);
            printf("Account type : %s\n",temp->acc_type);
            printf("Balance : %f\n",temp->balance);
        }
        print_less_than_500(temp->right);
    }
}
void print_ancestor(node *temp,int account_no)
{
    if(temp==NULL)
    return;
    else
    {
        if(account_no<temp->account_no)
        {
            printf("\nName : %s\n",temp->name);
            printf("Account Number : %d\n",temp->account_no);
            printf("Account type : %s\n",temp->acc_type);
            printf("Balance : %f\n",temp->balance);
            print_ancestor(temp->left,account_no);
        }
        else if(account_no>temp->account_no)
        {
            printf("\nName : %s\n",temp->name);

            printf("Account Number : %d\n",temp->account_no);
            printf("Account type : %s\n",temp->acc_type);
            printf("Balance : %f\n",temp->balance);
            print_ancestor(temp->right,account_no);
        }
        else
        return;
    }
}
void level(node *temp,int account_no,int level_node)
{
    if(temp==NULL)
    {
        printf("\nkey not found.\n");
        return;
    }
    else
    {
        if(account_no<temp->account_no)
        level(temp->left,account_no,level_node+1);
        else if(account_no>temp->account_no)
        level(temp->right,account_no,level_node+1);
        else
        {
            printf("Level of node is : %d .\n",level_node);
        }
    }
}
void left_view(node *temp)
{
    if(temp!=NULL)
    {
        left_view(temp->left);
            printf("\nName : %s\n",temp->name);
            printf("Account Number : %d\n",temp->account_no);
            printf("Account type : %s\n",temp->acc_type);
            printf("Balance : %f\n",temp->balance);
    }
}
void right_view(node *temp)
{
    if(temp!=NULL)
    {
        right_view(temp->right);
            printf("\nName : %s\n",temp->name);
            printf("Account Number : %d\n",temp->account_no);
            printf("Account type : %s\n",temp->acc_type);
            printf("Balance : %f\n",temp->balance);
    }
}
void largest_bst(node *temp)
{
    inorder(temp);
}
void top_view(node *temp)
{
    if(temp==NULL)
    return;
    else if(temp->left==NULL && temp->right==NULL)
    {
            printf("\nName : %s\n",temp->name);
            printf("Account Number : %d\n",temp->account_no);
            printf("Account type : %s\n",temp->acc_type);
            printf("Balance : %f\n",temp->balance);
    }
    else
    {
        top_view(temp->left);
        top_view(temp->right);
    }
}
void bottom_view(node *temp)
{
    if(temp==NULL)
    return ;
    else
    {
            if(temp->left!=NULL && temp->right!=NULL)
            {
            printf("\nName : %s\n",temp->name);
            printf("Account Number : %d\n",temp->account_no);
            printf("Account type : %s\n",temp->acc_type);
            printf("Balance : %f\n",temp->balance);
            }
            bottom_view(temp->left);
            bottom_view(temp->right);
    }
}
void print_left_right_subtree(node *temp,int account_no)
{
    if(temp==NULL)
    return;
    else
    {
        if(account_no<temp->account_no)
        print_left_right_subtree(temp->left,account_no);
        else if(account_no>temp->account_no)
        print_left_right_subtree(temp->right,account_no);
        else
        {
            printf("\nLeft subtree is : \n");
            inorder(temp->left);
            printf("\nRight subtree is : \n");
            inorder(temp->right);
            return;
        }
    }
}
node *root_copy=NULL;
void same_balance_printf(node *temp,float bal)
{
    if(temp!=NULL)
    {
        if(temp->balance==bal)
        {
            printf("\nName : %s\n",temp->name);
            printf("Account Number : %d\n",temp->account_no);
            printf("Account type : %s\n",temp->acc_type);
            printf("Balance : %f\n",temp->balance);
            same_balance_printf(temp->left,bal);
            same_balance_printf(temp->right,bal);
    }
    }
}
void same_bal(node *temp)
{
    if(temp!=NULL)
    {
        same_balance_printf(root_copy,temp->balance);
        same_bal(temp->left);
        same_bal(temp->right);
    }
}
int main()
{
    node *temp=NULL;
    while(1)
    {
        int choice;
        printf(" 1.INSERT\n 2.SEARCH\n 3.DELETE\n 4.INORDER TRAVERSAL\n 5.PREORDER TRAVERSAL\n 6.POSTORDER TRAVERSAL\n 7.LEVEL OF NODE\n 8.ACCOUNT WITH HIGHEST BALANCE\n 9.ACCOUNT WITH MINIMUM BALANCE\n 10.ACCOUNT LESS THAN 500\n 11.ACCOUNT WITH SAME BALANCE\n 12.ANCESTORS OF NODE\n 13.TOP VIEW\n 14.BOTTOM VIEW\n 15.LEFT VIEW\n 16.RIGHT VIEW\n 17.SEARCH A TREE AND PRINT ITS RIGHT AND LEFT SUBTREE\n 18.LARGEST SUBTREE\n");
        printf("Press 0 to exit.\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            int account_no;
            char name[10];
            char account_type[5];
            float balance;
            printf("Enter account number : ");
            scanf("%d",&account_no);
            printf("Name :");
            fflush(stdin);
            scanf("%s",name);
            fflush(stdin);
            printf("Account type :");
            fflush(stdin);
            scanf("%s",account_type);
            fflush(stdin);
            printf("Enter balance :");
            scanf("%f",&balance);
            temp=insert(temp,name,account_no,account_type,balance);
        }
        else if(choice==2)
        {
            int acc_no;
            printf("\nEnter accoount number to search : ");
            scanf("%d",&acc_no);
            if(search(temp,acc_no))
            {

            }
            else
            {
                printf("\nThis account number doesn't exist.\n");
            }
        }
        else if(choice==3)
        {
            int acc_no;
            printf("Enter account number to delete : ");
            scanf("%d",&acc_no);
            temp=delete_bst(temp,acc_no);
        }
        else if(choice==4)
        inorder(temp);
        else if(choice==5)
        preorder(temp);
        else if(choice==6)
        postorder(temp);
        else if(choice==7)
        {
            int account_no;
            printf("Enter key/account number : ");
            scanf("%d",&account_no);
            printf("\n");
            level(temp,account_no,0);
        }
        else if(choice==8)
        {
            int max_balance=max_bal_acc(temp);
            print_max_bal(temp,max_balance);
        }
        else if(choice==9)
        {
            int min_balance=min_bal_acc(temp);
            print_min_bal(temp,min_balance);
        }
        else if(choice==10)
        {
            print_less_than_500(temp);
        }
        else if(choice==11)
        {
            root_copy=temp;
            same_bal(temp);
        }
        else if(choice==12)
        {
            int acc_no;
            printf("Enter account number : ");
            scanf("%d",&acc_no);
            print_ancestor(temp,acc_no);
        }
        else if(choice==13)
        {
            top_view(temp);
        }
        else if(choice==14)
        {
            bottom_view(temp);
        }
        else if(choice==15)
        {
            left_view(temp);
        }
        else if(choice == 16)
        {
            right_view(temp);
        }
        else if(choice==17)
        {
            int account_no;
            printf("Enter key : ");
            scanf("%d",&account_no);
            print_left_right_subtree(temp,account_no);
        }
        else if(choice==18)
        {
            largest_bst(temp);
        }
        else if(choice==0)
        {

            break;
        }
        else
        {
            printf("\nWrong choice.\n");
        }

    }
    return 0;
}
