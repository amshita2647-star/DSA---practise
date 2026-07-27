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
int check(char c)
{
    if(c>='A' && c<='Z') return 1;
    if(c>='a' && c<='z') return 0;
}
int compatible(char a, char b)
{
    return (a+32==b);
}
int main()
{
    Stack s1=createstack();
    char w[MAX]; int flag=1;
    printf("enter the function call and return statement ");
    scanf("%s" , w);
    int length=strlen(w);
    for(int i=0;i<length;i++)
    {
        if(check(w[i])) { push(&s1,w[i]);}
        if(check(w[i])==0)
        {
            if(is_empty(s1)) { flag=0; break; }
            char c=pop(&s1);
            if(!compatible(c,w[i])) { flag=0; break;}
        }
    }
    if(flag) printf("valid");
    else
        printf("Invalid");
}
