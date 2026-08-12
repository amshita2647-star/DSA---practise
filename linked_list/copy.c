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
NODE* copy(NODE *l)
{
    if(!l) return NULL;
    NODE *t = makeNode(l->data);
    t->next=copy(l->next);
    return t;
}
int main()
{
    int n1;
    NODE *l1=NULL;
    printf("Enter values of n1");
    scanf("%d",&n1);
    l1=makeList(l1,n1);
    NODE *l2=NULL;
    l2=copy(l1);
    printf("\n\nCopied list: \n");
    display(l2);

}
