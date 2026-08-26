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
NODE *insertCir(NODE *l , int data)
{
    if(!l)
    {
        NODE*t = makeNode(data,NULL);
        t->next=t; return t;
    }
    NODE *t=makeNode(data,l->next);
    l->next=t;
    return l;
}
void dcir(NODE *l)
{
    if(l)
    {
        NODE *t=l; { printf("%5d",t->data); }
        while(t->next != l)
        {
            t=t->next;
            printf("%5d",t->data);
        }
    }
}
NODE *insertTail(NODE *l, int data) {  //INSERTION IN O(1) USING SWAPPING TRICK

    if (!l) {
        NODE *t = makeNode(data, NULL);
        t->next = t;
        return t;
    }

    NODE *t = makeNode(data, l->next);
    l->next = t;
    int temp = l->data;
    l->data = t->data;
    t->data = temp;


    return t;
}
NODE *insertCurr(NODE *head,int data)
{
    if (!head) {
        NODE *t = makeNode(data, NULL);
        t->next = t;
        return t;
    }
    NODE *new=makeNode(data,head->next);
    head->next=new;
    return head;

}
void search(NODE *l,int data)
{
    if(l==NULL)
    {
        printf("List is empty");
    }
    NODE *prev=l;
    while(prev->next != l)
    {
        prev = prev->next;
    }
    NODE *t=l;
    do
    {
        if(t->data == data)
        {
            printf("Element found = %d\n",t->data);
            printf("predecessor = %d\n",prev->data);
            printf("successor  = %d\n",t->next->data);
            return;
        }
        prev = t;
        t=t->next;
    }while(t != l);
    printf("Element element not found \n");

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
NODE* reverseCircularList(NODE *head)
{
    if (head == NULL || head->next == head) {
        return head;
    }

    NODE *last = head;
    while (last->next != head) {
        last = last->next;
    }
    NODE *prev = last;
    NODE *curr = head;
    NODE *next_node = NULL;

    do {
        next_node = curr->next; // Save next node
        curr->next = prev;      // Reverse link
        prev = curr;            // Move prev forward
        curr = next_node;       // Move curr forward
    } while (curr != head);

    // 4. Update head to point to the new head (old tail)
    head = prev;

    return head;
}
int main()
{
    NODE * cl=NULL;
    cl=insertCir(cl,100);
    cl = insertTail(cl,200);
    cl = insertCurr(cl,101);
    dcir(cl); printf("\n\n");
    search(cl,100);
    printf("The number of nodes in cll : %d\n",count(cl));
    cl=reverseCircularList(cl);
    dcir(cl); printf("\n\n");


}
