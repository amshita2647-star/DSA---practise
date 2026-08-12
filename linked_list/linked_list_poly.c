#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int coeff; int expo;
    struct node*next;
}NODE;
NODE* makeNode(int coeff,int expo,NODE *next)
{
    NODE* t =(NODE *)malloc (sizeof(NODE));
    t->coeff=coeff;
    t->expo=expo;
    t->next=next; return t;
}
NODE *inSortD(NODE *l , int coeff , int expo) // insert node in descending order
{
     
    if(l->expo == expo) { l->coeff+=coeff; return l;}
    if(l->expo < expo)
    {
        NODE *t=makeNode(coeff,expo,l); return t;
    }
    l->next=inSortD(l->next,coeff,expo);
    return l;
}
void printlist(NODE *l)
{
    while(l)
    {
        printf(" %5d x^%d ",l->coeff,l->expo);
        l=l->next;
    }
}
void multiplyScalar(NODE *l, int n)
{
    while(l)
    {
        l->coeff=l->coeff*n;
        l=l->next;
    }
}
int count(NODE *l)
{
    if(!l) return 0;
    int cc=1;
    NODE * t=l;
    while(t->next != l)
    {
        cc++; t=t->next;
    }
    return cc;
}
NODE *addPoly(NODE *l1 , NODE *l2)
{
    NODE *l3 = NULL;
    while(l1 && l2)
    {
        if(l1->expo == l2->expo)
        {
            int sum=l1->coeff+l2->coeff;
            if(sum != 0) { l3=inSortD(l3,sum,l1->expo); }
        }
        else
        {
            l3=inSortD(l3,l1->coeff,l1->expo);
            l3=inSortD(l3,l2->coeff,l2->expo);
        }
        l1=l1->next; l2=l2->next;
    }
    while(l1)
    {
        l3=inSortD(l3,l1->coeff,l1->expo);
        l1=l1->next;
    }
    while(l2)
    {
        l3=inSortD(l3,l2->coeff,l2->expo);
        l2=l2->next;
    }
    return l3;

}
int main()
{
    NODE *l1 = NULL;
    for(int i=0;i<5;i++)
    {
        l1=inSortD(l1,(rand()%100),rand()%10);
    }
    printlist(l1); printf("\n\n");
    l1=inSortD(l1,24,9);
    printlist(l1); printf("\n\n");
    int n;
    printf("Enter a scalar to multiply\n");
    scanf("%d",&n);
    printf("Poly 1: \n");
    multiplyScalar(l1,n);
    printlist(l1); printf("\n\n");
    printf("Poly 2: \n");
    NODE *l2 = NULL;
    for(int i=0;i<5;i++)
    {
        l2=inSortD(l2,(rand()%100),rand()%10);
    }
    printlist(l2); printf("\n\n");
    printf("Poly 3: \n");
    NODE *l3 = NULL;
    l3 = addPoly(l1,l2);
    printlist(l3); printf("\n\n");
}
