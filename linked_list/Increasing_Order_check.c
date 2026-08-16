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
int is_increase(NODE *l)
{
    while(l&&l->next)
    {
        int n=(l->next)->data;
        if((l->data > n)) { return 0;}
        l=l->next;
    }
    return 1;
}
int main()
{
    NODE* l1=NULL;
    int len;
    printf("Enter the number of nodes");
    scanf("%d",&len);
    printf("Enter the values ");

    for(int i=1;i<=len;i++)
    {
        int n;
        scanf("%d",&n);
        if(!l1) l1=makeNode(n);
        else {l1=insertTail(l1,n);}
    }
    printf("List l1 \n");
    display(l1);
    printf("\n\n");
    printf("Is increasing : %s",is_increase(l1) ? "TRUE": "FALSE");
}
