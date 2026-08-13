#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct node
{

    char data;
    struct node *left;
    struct node* right;
}BTree;
BTree* makeNode(int data)
{
    BTree *t=(BTree*)malloc(sizeof(BTree));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}
BTree* insert(BTree *t , char data) // Binary search tree insertion
{
    if(!t) return makeNode(data);
    if(t->data > data) t->left = insert(t->left , data);
    if(t->data < data) t->right = insert(t->right , data);
    return t;
}
int min(BTree *t)
{
    if(!t->right) return t->data;
    return min(t->right);
}
BTree *delete(BTree *t , char data)
{
    if(!t) return NULL;
    if(t->data == data)
    {
        if(!t->left && !t->right) return NULL;
        if(!t->left ) return t->right;
        if(!t->right) return t->left;
        t->data = min(t->right);
        t->right = delete(t->right,t->data);
        return t;
    }
    if(t->data > data) t->left = delete(t->left , data);
    else t->right = delete(t->right,data);
}
int search(BTree *t, char data)
{
    if(!t) return 0;
    if(t->data==data) return 1;
    if(t->data > data) return search(t->left,data);
    if(t->data < data) return search(t->right,data);
}
int main()
{
    char s[20];
    BTree *t=NULL;
    int f=1;
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='K' && t==NULL)
        {
            printf("Invalid: Can't delete undeclared variable");
            f=0;
            break;
        }
        if(s[i]=='K')
        {
            if(!search(t,s[i+1]))
            {
                printf("Invalid: Can't delete undeclared variable");
                f=0;
                break;
            }
            else
            {
                t=delete(t,s[i+1]);
                i=i+1;
            }
        }
        if(s[i]=='D')
        {
            if(!search(t,s[i+1])) //handling Duplication of Declaration
            {
                printf("Invalid : Variable already declared or not declared at all");
                f=0;
                break;
            }
            else
            {
                t=insert(t,s[i+1]);
                i=i+1;
            }
        }
        if(s[i] == 'U')
        {
            if(!search(t,s[i+1]))
            {
                printf("Invalid : Can't use undeclared variable");
                f=0;
                break;
            }
            else
                i=i+1;
        }

    }
    if(f)
        printf("Valid");
}
