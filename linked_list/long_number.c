#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;
NODE *createNode(int data)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
NODE *insertTail(NODE *l, int data)
{
    if (l == NULL)
        return createNode(data);
    NODE *temp = l;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    NODE *new = createNode(data);
    temp->next = new;
    return l;
}
int count(NODE *l)
{
    int cc = 0;
    while (l->next != NULL)
    {
        l = l->next;
        cc++;
    }
    return cc;
}
void printlist(NODE *l)
{
    while (l != NULL)
    {
        printf("%5d", l->data);
        l = l->next;
    }
}
int main()
{
    NODE *l1=NULL;
    l1 = insertTail(l1, 1);
    l1 = insertTail(l1, 23);
    l1 = insertTail(l1, 78);
    printlist(l1);
    int number = 0;
    int expo ;
    while (l1 != NULL)
    {
        number=number*100+l1->data;
        
        l1 = l1->next;
    }
    printf("\n%d", number);
}
