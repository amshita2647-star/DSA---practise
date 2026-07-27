#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 10
typedef  struct
{
    char val[MAX];
    int front,rear;
}Q;
Q createqueue()
{
    Q q;
    q.rear=q.front=0; return q;
}
int isempty( Q q)
{
    return(q.front==q.rear);
}
int isfull(Q q)
{
    return((q.rear+1)%MAX==q.front);
}
int insert(Q *q , char data)
{
    if(isfull(*q)) return 0;
    q->rear=(q->rear+1)%MAX;
    q->val[q->rear]=data; return 1;
}
char Delete(Q *q)
{
    if(isempty(*q)) return 0;
    q->front=(q->front+1) %MAX;
    return q->val[q->front];
}
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
    { s->top+=1;
    s->val[s->top]=val; return 1;}
}
char pop (Stack *s )
{

    if(is_empty(*s)) return '0';
    char c=s->val[s->top];
    s->top=s->top-1; return c;
}
int top(Stack s) {if(is_empty(s)) return -999; else return s.val[s.top];}
int main()
{
    char w[MAX]; int flag=1;  int dot=0;
    printf("Enter the w.w.w(rev) string to check : ");
    fgets(w,sizeof(w),stdin);
    int length=strlen(w);
    Q q=createqueue();
    Stack s=createstack();
    for(int i=0;i<length;i++)
    {
        char c=w[i];
        if(c=='.'){ dot++; continue;}
        if(dot==0)
        {
            insert(&q,c);
        }
        if(dot==1)
        {
            if(c!=Delete(&q)) {flag =0; break;}
            else{push(&s,c);}
        }
        if(dot==2)
        {
            if(c!=pop(&s)) {flag =0; break;}
        }

    }
    if(!isempty(q) && !is_empty(s)) {flag=0; }
    if(flag) printf("It is in w.w.w(rev) form");
    else
        printf("It is not in w.w.w(rev) form");
}
