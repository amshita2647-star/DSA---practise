#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 10
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
int is_full(Stack s) { return (s.top == MAX-1 );}
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
int main()
{
    char w[MAX]; int flag=1; Stack s=createstack();
    printf("Enter the string to check palindrome : ");
    scanf("%s",w);
    int length=strlen(w);
    for(int i=0;w[i]!='\0';i++)
    {
        char c=w[i];
        push(&s,c);
    }
    int j=0;
    while(!is_empty(s) && w[j]!='\0')
    {
        if(w[j]!=pop(&s)) { flag=0; break; } j++;
    }
    if(flag) printf("It is in w=w(rev)");
    else
        printf("It is not in w=w(rev)");
}
