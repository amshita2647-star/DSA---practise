//PS :Create a AVL tree by doing 1 insertion at a time and display the tree along with level numbers
// added delete operation along side
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;
NODE* makeNode(int data)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}
NODE* RotateRight(NODE* Z)
{
    NODE* Y = Z->left;
    NODE* temp = Y->right;
    Y->right = Z;
    Z->left = temp;
    return Y;
}
NODE* RotateLeft(NODE* Z)
{
    NODE *Y = Z->right;
    NODE* temp = Y->left;
    Y->left = Z;
    Z->right = temp;
    return Y;
}
int height(NODE *root)
{
    if(!root) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1+((left>right) ? left : right);
}
int getbalance (NODE* root)
{
    if(!root) return 0;
    return height(root->left) - height(root->right) ;
}
NODE* insert(NODE *t , int data)
{
    if(!t) return makeNode(data);
    if(data > t->data) t->right = insert(t->right , data);
    else if(data < t->data) t->left = insert(t->left,data);
    else return t; // dupes not allowed
    
    int bal = getbalance(t);
    
    if(bal > 1 && data < t->left->data) return RotateRight(t);
    if(bal < -1 && data > t->right->data) return RotateLeft(t);
    if(bal > 1 && data > t->left->data) 
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
int FindMin(NODE* t) //find MIN in Inorder successor
{
    if(!t->left) return t->data;
    else return FindMin(t->left);
}
int FindMax(NODE *t) //find MAX in Inorder predeccessor
{
    if(!t->right) return t->data;
    else return FindMax(t->right);
}
NODE* delete(NODE *t , int data)
{
    if(!t) return NULL;
    if(t->data == data )
    {
        if(!t->left && !t->right) return NULL;
        if(!t->left) return t->right;
        if(!t->right) return t->left;
        if(t->left && t->right)
        {
            t->data = FindMin(t->right);
            t->right = delete(t->right , t->data);
        }
    }
    else if(t->data > data) { t->left = delete(t->left , data); }
    else { t->right = delete(t->right,data); }
    int bal = getbalance(t);
    //left heavy
    
    if(bal > 1 && getbalance(t->left) >= 0) return RotateRight(t);
    if(bal > 1 && getbalance(t->left) < 0) 
    {
        t->left = RotateLeft(t->left);
        return RotateRight(t);
    }
    
    
    //Right Heavy
    if(bal < -1 && getbalance(t->right) < 0) return RotateLeft(t);
    if(bal< -1 && getbalance(t->right) >= 0) 
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
    t = insert(t,15);
    t = insert(t,11);
    t = delete(t,15);
    printByLevel(t);
}
