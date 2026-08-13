#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
}NODE;
NODE* makeNode(int data,NODE *next)
{
    NODE* t =(NODE *)malloc (sizeof(NODE));
    t->data=data;
    t->next=next; return t;
}
NODE *inSortA(NODE *l , int data) // insert node in ascending order
{
    if(!l) return makeNode(data,NULL);
    if(l->data > data)
    {
        NODE *t=makeNode(data,l); return t;
    }
    l->next=inSortA(l->next,data);
    return l;
}
NODE *inSortD(NODE *l , int data) // insert node in ascending order
{
    if(!l) return makeNode(data,NULL);
    if(l->data <= data)
    {
        NODE *t=makeNode(data,l); return t;
    }
    l->next=inSortD(l->next,data);
    return l;
}
NODE *delSort(NODE*l,int data)
{
    if(!l) return l;
    if(l->data > data) return l;
    if(l->data == data) return l->next;
    l->next =delSort(l->next,data);
}
void printlist(NODE *l)
{
    while(l)
    {
        printf("%5d",l->data);
        l=l->next;
    }
}
void printRev(NODE *l)
{
    if(l){ printRev(l->next); printf("%5d",l->data);}
}
int main()
{
    NODE *l = NULL;
    l=inSortA(l,100);
    for(int i=0;i<5;i++)
    {
        l=inSortA(l,rand()%10);
    }
    printf("After insertion in ascending order: \n");
    printlist(l);
    printf("\n\n");
    printf("After deletion of 0 : \n");
    l=delSort(l,0);
    printlist(l);
    printf("\n\n");
    printf("Printing the ascending order list into descending order \n");
    printRev(l);
}
