#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
}NODE;
NODE* makeNode(int data)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    temp->height; // Every new node has a height of 1
    return temp;
}
int getHeight(NODE *root)
{
    if(!root) return 0; //To handle NULL case getHeight  is written
    else return root->height;
}
int max(int a , int b)
{
    return (a>b) ? a : b;
}
void updateHeight(NODE *root)
{
    if(!root)
    {
        root->height = 1+max(getHeight(root->left) , getHeight(root->right));
    }
    
}
int getbalance(NODE* root)
{
    return (root->left->height - root->right->height);
}
NODE* RotateRight(NODE* Z)
{
    NODE* Y = Z->left;
    NODE* temp = Y->right;
    Y->right = Z;
    Z->left = temp;
    // Update heights (Order matters: z first, then y, because z is now y's child)
    updateHeight(Z);
    updateHeight(Y);
    return Y;
}
NODE* RotateLeft(NODE* Z)
{
    NODE *Y = Z->right;
    NODE* temp = Y->left;
    Y->left = Z;
    Z->right = temp;
    
    updateHeight(Z);
    updateHeight(Y);
    return Y;
}
NODE* insert(NODE *t , int data)
{
    if(!t) return makeNode(data);
    if(data > t->data) t->right = insert(t->right , data);
    if(data < t->data) t->left = insert(t->left,data);
    else return t; // dupes not allowed
    
    updateHeight(t);
    int bal = getbalance(t);
    
    if(bal > 1 && data < t->left->data) return RotateRight(t);
    if(bal < -1 && data > t->right->data) return RotateLeft(t);
    if(bal < 1 && data > t->left->data) 
    {
        t->left = RotateLeft(t->left);
        return RotateRight(t);
    }
    if(bal< -1 && data < t->right->data ) 
    {
        t->right = RotateRight(t->right);
        return RotateLeft(t);
    }
    return t;
    
}

void inOrder(NODE *t)
{
    if(t)
    {
        inOrder(t->left);
        printf("%5d",t->data);
        inOrder(t->right);
    }
}
void printByLevel(NODE *t)
{
    int front = 0;
    int rear =  0;
    NODE* q[100];
    q[++rear]=t;
    int curlvl = 0; // start from level 0
    while(front < rear)
    {
        int num = rear - front; //Count the number of nodes
        printf("Level %d",curlvl);
        while(num > 0) //printing all the nodes in that level
        {
            NODE* temp = q[++front];
            printf("%5d",temp->data);
            if(temp->left) q[++rear] = temp->left; // storing each nodes left and right
            if(temp->right) q[++rear] = temp->right; // and incrementing val of rear
            num--;
        }
        curlvl++;
        printf("\n");
    }
}
int main()
{
    NODE *t = NULL;
    t = insert(t,10);
    t = insert(t,20);
    t = insert(t,30);
    printByLevel(t);
}

