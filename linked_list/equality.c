#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE* makeNode(int data)
{
    NODE* temp =(NODE *) malloc (sizeof(NODE));
    temp->data=data;
    temp->next = NULL;
    return temp;
}
void display(NODE *l)
{
    while(l)
    {
        printf("[ %p -%d - %p]",l,l->data,l->next);
        l=l->next;
    }
}
NODE* insertHead(NODE *l , int data)
{
    NODE *temp=makeNode(data);
    temp -> next=l;
    return temp;
}
NODE * insertTail(NODE *l,int data) //insert node at end
{
    if(!l) return makeNode(data);
    NODE *t =l;
    while(t->next) t=t->next; // after loop it points to the end
    t->next=makeNode(data); //connecting with last node
    return l;
}
int countNodes(NODE *l) //nodes count
{
    int cc=0;
    while(l)
    {
        cc=cc+1; l=l->next;
    }
    return cc;
}
int isEqual(NODE *l1 , NODE *l2)
{
    if(countNodes(l1) != countNodes(l2)) return 0;
    while(l1 && l2)
    {
        if(l1->data != l2->data) return 0;
        l1=l1->next; l2=l2->next;
    }
    return 1;
}
NODE * makeList(NODE *l , int size)
{
    printf("Enter values :");
    for(int i=1;i<=size;i++)
    {
        int n;
        scanf("%d",&n);
        if(!l) l=makeNode(n);
        else {l=insertTail(l,n);}
    }
    return l;
}
int main()
{
    int n1,n2;
    NODE *l1=NULL;
    NODE *l2=NULL;
    printf("Enter size of l1: ");
    scanf("%d",&n1);
    l1=makeList(l1,n1);
    printf("Enter size of l2: ");
    scanf("%d",&n2);
    l2=makeList(l2,n2);
    printf("IS L1 and L2 EQUAL ? %s",isEqual(l1,l2)?"yes":"No");
}
