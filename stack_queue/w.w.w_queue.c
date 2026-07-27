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
char pop(Q *q)
{
    if(isempty(*q)) return 0;
    q->front=(q->front+1) %MAX;
    return q->val[q->front];
}
int main()
{
    char w[MAX]; int flag=1; int stop=0; int dot=0;
    printf("Enter the w.w.w string to check : ");
    fgets(w,sizeof(w),stdin);
    int length=strlen(w);
    Q q1=createqueue();
    Q q2=createqueue();
    for(int i=0;i<length;i++)
    {
        char c=w[i];
        if(c=='.'){ dot++; continue;}
        if(dot==0)
        {
            insert(&q1,c);
        }
        if(dot==1)
        {
            if(c!=pop(&q1)) {flag =0; break;}
            else{insert(&q2,c);}
        }
        if(dot==2)
        {
            if(c!=pop(&q2)) {flag =0; break;}
        }

    }
    if(!isempty(q1) && !isempty(q2)) flag=0;
    if(flag) printf("It is in w.w.w form");
    else
        printf("It is not in w.w.w form");
}

