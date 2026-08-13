#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{

    int data;
    int cc;
    struct node *left;
    struct node* right;
}BTree;
BTree* makeNode(int data)
{
    BTree *t=(BTree*)malloc(sizeof(BTree));
    t->data = data;
    t->cc = 1;
    t->left = NULL;
    t->right = NULL;
    return t;
}
BTree* insert(BTree *t , int data) // Binary search tree insertion
{
    if(!t) return makeNode(data);
    if(t->data > data) t->left = insert(t->left , data);
    if(t->data < data) t->right = insert(t->right , data);
    if(t->data == data ) t->cc++;
    return t;
}
void inOrder (BTree *t)
{
    if(t)
    {
        inOrder(t->left);
        printf("data :%5d , frequency : %d\n",t->data,t->cc);
        inOrder(t->right);
    }
}
int main()
{
    BTree *t=NULL;
    for(int i=0;i<500;i++)
    {
        t=insert(t,rand()%10);
    }
    printf("The BST :\n");
    inOrder(t);
}
