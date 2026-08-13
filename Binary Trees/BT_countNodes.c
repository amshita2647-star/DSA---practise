#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct node
{

    char data[100];
    struct node *left;
    struct node* right;
}BTree;
BTree* makeNode(char data[])
{
    BTree *t=(BTree*)malloc(sizeof(BTree));
    strcpy(t->data,data);
    t->left = NULL;
    t->right = NULL;
    return t;
}
BTree* insert(BTree *t , char data[]) // Binary search tree insertion
{
    if(!t) return makeNode(data);
    if(strcmp(t->data,data)>0) t->left = insert(t->left , data);
    if(strcmp(t->data,data)<0) t->right = insert(t->right , data);
    return t;
}
int countleaf(BTree *t)
{
    if(!t) return 0;
    if(t->left == NULL && t->right == NULL ) return 1;
    else
        return countleaf(t->left) + countleaf(t->right);
}
int countSingleChild(BTree *t)
{
    if((t->left == NULL && t->right != NULL) )
        return 1+countSingleChild(t->right);
    if((t->right == NULL && t->left != NULL))
        return 1+countSingleChild(t->left);
    if(t->left == NULL && t->right == NULL ) return 0;
    else
        return countSingleChild(t->left) + countSingleChild(t->right);
}
int countDouble(BTree *t)
{
    if(!t) return 0;
    int cc=0;
    if(t->right != NULL && t->left !=NULL )
        cc=1;
    return cc+countDouble(t->left)+countDouble(t->right);

}
void inOrder (BTree *t)
{
    if(t)
    {
        inOrder(t->left);
        printf("%s   ",t->data);
        inOrder(t->right);
    }
}
int main()
{
    BTree *t = NULL;
    int n;
    printf("Enter the number of nodes ");
    scanf("%d",&n);
    getchar();
    char st[20];
    printf("Enter the string to insert");
    for(int i=0;i<n;i++)
    {
        fgets(st,sizeof(st),stdin);
        st[strcspn(st, "\n")] = '\0';
        t=insert(t,st);
    }
    inOrder(t);
    printf("\nNumber of Leaf nodes : %d \n",countleaf(t));
    printf("Number of nodes with single child %d \n",countSingleChild(t));
    printf("Number of nodes with two children %d \n",countDouble(t));


}
