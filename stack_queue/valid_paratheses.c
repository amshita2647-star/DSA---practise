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
int isempty(Stack s){ return (s.top==0 );}
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

int check(char c)
{
    if(c=='{'|| c=='(' || c=='[') return 1;
    if(c=='}'|| c==')' || c==']') return 0;
    return -1;
}
int openclose(char close, char open)
{
    return
        (close==')' && open=='(') ||
        (close==']' && open=='[') ||
        (close=='}' && open=='{');
}
int main()
{
    Stack s1=createstack(); char ch[MAX]; 
    printf("Enter the string");
    fgets(ch,sizeof(ch),stdin);
    int length=strlen(ch);
    for(int i=0;i<length;i++)
    {
        char c=ch[i];
        if(check(c)==1) { if(push(&s1,c)){} }
        else if(check(c)==0)
        {
            if(openclose(c,pop(&s1)))
                continue;
            else
                 break;
        }
        else continue;
    }

    if(isempty(s1)) printf("It is in balanced form");
    else
        printf("Not in balanced form");

}



