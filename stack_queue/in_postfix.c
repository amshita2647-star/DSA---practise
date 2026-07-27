#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
typedef struct
{
    char val[MAX];
    int top;
}Stack;
Stack createstack()
{

    Stack s; s.top=0; return s;
}
int isempty(Stack s){ return s.top==0 ;}
int isfull(Stack s) { return (s.top == MAX );}
int push (Stack *s , int val)
{
    if(isfull(*s)) return 0;
    else
    { s->top+=1;
    s->val[s->top]=val; return 1;}
}
char pop (Stack *s )
{

    if(isempty(*s)) return 0;
    char val = s->val[s->top];
    s->top=s->top-1; return val;
}
char top(Stack s) {if(isempty(s)) return -999; else return s.val[s.top];}
int precedence(char op)
{
    switch(op)
    {

        case '!':
        case '~':
            return 5;
        case '^':
            return 4;
        case '*':
        case '/':
        case '%':
            return 3;
        case '+':
        case '-':
            return 2;
        case '?':
        case ':':
            return 1;

        default:
            return 0;
    }
}

int main()
{
    Stack s;
    s=createstack();
    char infix[MAX];char postfix[MAX];int j=0;
    printf("Enter the infix expression ");
    fgets(infix,sizeof(infix),stdin);
    int length=strlen(infix);
    for(int i=0;infix[i]!='\0';i++)
    {
        char c=infix[i];
        if(isalnum(c))
        {
            postfix[j++]=c;
        }
        else if(c=='(')
        {
            int x=push(&s,c);
        }
        else if(c==')')
        {
            while(!isempty(s) && top(s)!='(')
            {
                postfix[j++]=pop(&s);
            }
            if(!isempty(s)) { char x=pop(&s);}
        }
        else if(c=='?')
        {
            push(&s,c);
        }
        else if(c==':')
        {
            while(!(isempty(s)) && top(s)!='?')
            {
                postfix[j++]=pop(&s);
            }
            if(!isempty(s)) {char x=pop(&s);push(&s, '?');push(&s,':');}
        }
        else
        {
            while(!isempty(s) && (precedence(top(s))> precedence(c)))
            {
                postfix[j++]=pop(&s);
            }
            int x=push(&s,c);
        }
    }
    while(!isempty(s))
    {
        postfix[j++]=pop(&s);
    }
    postfix[j] = '\0';

    printf("The postfix expression is : %s ",postfix);
}
