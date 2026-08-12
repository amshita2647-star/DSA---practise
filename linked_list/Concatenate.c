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
/*NODE *concatenate(NODE* l1, NODE* l2) //o(n^2)
{
    NODE* temp=NULL;
    while(l1)
    {
        if(!temp){ temp=makeNode(l1->data); l1=l1->next; }
        else{
            temp=insertTail(temp,l1->data);
            l1=l1->next;
        }
    }
    while(l2)
    {
        if(!temp){ temp=makeNode(l2->data); l2=l2->next; }
        else{
            temp=insertTail(temp,l2->data);
            l2=l2->next;
        }
    }
    return temp;
}*/
NODE* copy(NODE *l)
{
    if(!l) return NULL;
    NODE *t = makeNode(l->data);
    t->next=copy(l->next);
    return t;
}
NODE * concat(NODE *l1, NODE *l2)
{
    if(!l1) return copy(l2);
    NODE *l3=copy(l1);
    NODE* temp=l3;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=copy(l2);
    return l3;
}
int main()
{
    int n1,n2;
    NODE *l1=NULL;
    NODE *l2=NULL;
    NODE *l3=NULL;
    printf("Enter size of l1: ");
    scanf("%d",&n1);
    l1=makeList(l1,n1);
    printf("Enter size of l2: ");
    scanf("%d",&n2);
    l2=makeList(l2,n2);
    l3=concat(l1,l2);
    printf("\n\nConcatenated l3: \n");
    display(l3);
}

