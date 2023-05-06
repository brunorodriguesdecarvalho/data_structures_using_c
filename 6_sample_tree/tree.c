//sample program using C language to demonstrate tree structure and its operations

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

void insert(int num){
    struct node *temp,*parent;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        parent=root;
        while(parent!=NULL)
        {
            if(num>parent->data)
            {
                if(parent->right==NULL)
                {
                    parent->right=temp;
                    return;
                }
                else
                    parent=parent->right;
            }
            else
            {
                if(parent->left==NULL)
                {
                    parent->left=temp;
                    return;
                }
                else
                    parent=parent->left;
            }
        }
    }
};

void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
}

void preorder(struct node *temp)
{
    if(temp!=NULL)
    {
        printf("%d\t",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d\t",temp->data);
    }
}

void search(int num)
{
    struct node *temp;
    temp=root;
    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            printf("Element found\n");
            return;
        }
        else if(num>temp->data)
            temp=temp->right;
        else
            temp=temp->left;
    }
    printf("Element not found\n");
}

void delete(int num)
{
    struct node *temp,*parent,*succ,*psucc;
    temp=root;
    parent=NULL;
    while(temp!=NULL)
    {
        if(temp->data==num)
            break;
        parent=temp;
        temp=(num>temp->data)?temp->right:temp->left;
    }
    if(temp==NULL)
    {
        printf("Element not found\n");
        return;
    }
    if(temp->left==NULL)
        succ=temp->right;
    else if(temp->right==NULL)
        succ=temp->left;
    else
    {
        psucc=temp;
        succ=temp->right;
        while(succ->left!=NULL)
        {
            psucc=succ;
            succ=succ->left;
        }
        if(temp==psucc)
            succ->left=temp->left;
        else
        {
            succ->left=temp->left;
            psucc->left=succ->right;
            succ->right=temp->right;
        }
    }
    if(parent==NULL)
        root=succ;
    else if(parent->left==temp)
        parent->left=succ;
    else
        parent->right=succ;
    free(temp);
}

int main()
{
    int ch,num;
    while(1)
    {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Delete\n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number to be inserted: ");
                    scanf("%d",&num);
                    insert(num);
                    break;
            case 2: inorder(root);
                    break;
            case 3: preorder(root);
                    break;
            case 4: postorder(root);
                    break;
            case 5: printf("Enter the number to be searched: ");
                    scanf("%d",&num);
                    search(num);
                    break;
            case 6: printf("Enter the number to be deleted: ");
                    scanf("%d",&num);
                    delete(num);
                    break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

