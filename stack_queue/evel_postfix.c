#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 3
typedef struct
{
    char val[MAX];
    int top;
}Stack;
Stack createstack()
{

    Stack s; s.top=0; return s;
}
int is_empty(Stack s){ return s.top==0 ;}
int is_full(Stack s) { return (s.top == MAX );}
int push (Stack *s , char val)
{
    if(is_full(*s)) return 0;
    else
    {
    s->val[s->top]=val;s->top+=1; return 1;}
}
char pop (Stack *s )
{

    if(is_empty(*s)) return '0';
    s->top=s->top-1;
    char c=s->val[s->top];
     return c;
}
int top(Stack s) {if(is_empty(s)) return -999; else return s.val[s.top-1];}
int operation(int a, int b, char op)
{
    switch(op)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        default: return 0;
    }
}
int main()
{
    Stack s1=createstack();
    char post[MAX];
    printf("Enter postfix expression");
    scanf("%s",post);
    for(int i=0;i<3;i++)
    {
        char c=post[i];
        if(c >= 'a' && c <= 'z')
        {

            push(&s1, c-'a'+1);
        }
        else
        {
            int right = pop(&s1);
            int left = pop(&s1);

            push(&s1, operation(left, right, c));
        }
    }
    printf("Result = %d ",pop(&s1));
}
