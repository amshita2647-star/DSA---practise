#include<stdio.h>
#include<malloc.h>
typedef struct node{
    int val;
    struct node *left;
    struct node *right;

}BT;
BT* makeNode(int data)
{
    BT *t = (BT *)malloc(sizeof(BT));
    t->val=data;
    t->left= NULL;
    t->right=NULL;
    return t;
}
BT* insert(BT *t,int data)
{
    if(!t) return makeNode(data);
    if(t->val > data) t->left = insert(t->left,data);
    if(t->val < data) t->right = insert(t->right,data);
    return t;
}
void display(BT *t)
{
    if(t)
    {
        display(t->left);
        printf("%5d",t->val);
        display(t->right);
    }
}

void inOrder(BT *t,int *cc ,int k) //cc is having the count
{
    if(t == NULL || *cc>k) return;
    inOrder(t->left,cc,k);  
    (*cc)+=1;
    if(*cc==k) // kth element with no left node is the kth samllest
    {
        printf("%d ",t->val);
        return;
    }
    inOrder(t->right,cc,k);
}
int main()
{
    BT *t=NULL;
    int c =0;
    for(int i=0;i<9;i++)  // creating a skewed BT of values fron 0 - 8
    {
        t=insert(t,i);
    }
    display(t);
    inOrder(t,&c,3);
}
