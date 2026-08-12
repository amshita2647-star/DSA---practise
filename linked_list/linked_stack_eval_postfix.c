#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data ; 
    struct node *next;
}NODE;
typedef struct stack
{
    NODE *top;
}STACK;
STACK createStack()
{
    STACK s;
    s.top=NULL;
    return s;
}
int isFull(STACK *s)
{
    return 0;
}
int isEmpty(STACK *s)
{
    if(s->top==NULL) return 1;
    else return 0;
}
int push(STACK *s,int data)
{
    NODE *newnode=(NODE *)malloc(sizeof(NODE));
    if(newnode == NULL) return 0;
    newnode->data=data;
    newnode->next=s->top;
    s->top=newnode;
    return 1;
}
int pop(STACK *s)
{
    if(isEmpty(s))
    {
       return -0;
    }
    NODE *temp=s->top;
    s->top=s->top->next;
    return temp->data;
    free(temp);
}
STACK printStack(STACK *s)
{
    STACK temp=createStack();
    while(s->top != NULL)
    {
        int n=pop(s);
        printf("%d",n);
        push(&temp,n);
    }
    return temp;
}
int eval(int f,int s,int c)
{
    if(c=='+')
        return f+s;
    else if(c=='-')
        return f-s;
    else if(c=='*')
        return f*s;
    else if(c=='/')
        return f/s;
    else return 0;
}
int main()
{
    char ch[50];
    STACK s1=createStack();
    printf("Enter postfix expression (e.g., 534*+2-): ");
    fgets(ch,sizeof(ch),stdin);
    int n = strlen(ch);

    for(int i=0;i<n;i++)
    {
        char c=ch[i];
        if(c== ' ' || c=='\n') continue;
        if( c >='0' && c <='9')
        {
            int x=c-'0';
            push(&s1,x);
        }
        else
        {
            int second=pop(&s1);
            int first=pop(&s1);
            int ans=eval(first,second,c);
            push(&s1,ans);
        }
    }
    if(!isEmpty(&s1))
        printf("Ans = %d ",s1.top->data);
}
