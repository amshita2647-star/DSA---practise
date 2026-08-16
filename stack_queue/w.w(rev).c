#include<stdio.h>
#include<string.h>
#define MAX 20
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
int isfull(Stack s) { return (s.top == MAX-1 );}
int push (Stack *s , char val)
{
    if(isfull(*s)) return 0;
    else
    { s->top+=1;
    s->val[s->top]=val; return 1;}
}
char pop (Stack *s )
{

    if(isempty(*s)) return '0';
    char c=s->val[s->top];
    s->top=s->top-1; return c;
}
int top(Stack s) {if(isempty(s)) return -999; else return s.val[s.top];}
void copystack(Stack *temp , Stack *s)
{

    Stack a=createstack();
    while(!isempty(*s))
    {
        char c=pop(s);
        if(push(&a,c) && push(temp,c)){}
    }
    while(!isempty(a))
    {
        char c=pop(&a);
        if(push(s,c)){}
    }
}

int main()
{
    Stack s1=createstack(); char ch[MAX]; int flag=1;
    printf("Enter the string");
    fgets(ch,sizeof(ch),stdin);
    int length=strlen(ch);
    for(int i=0;i<length;i++)
    {
        char c=ch[i];
        if(c!='.'){ if(push(&s1,c)) {}}
        else 
        {
            c=ch[i+1];
            if(c==pop(&s1)) { flag=1;}
            else {flag=0; break;}
        }
    }
    // Stack temp =createstack();
    // copystack(&temp,&s1);
    // char x,y;
    // int flag=1;
    // while((x=pop(&s1))!='.' && (y=pop(&temp))!='.')
    // {
    //     if(x!=y) {flag=0; break;}
    // }
    if(flag) printf("It is in w.w(reverse) form");
    else
        printf("Not in w.w(reverse)form");

}


