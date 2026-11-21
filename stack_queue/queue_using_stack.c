
#include <stdio.h>
#define MAX 100

typedef struct
{
    int val[MAX];
    int top;
} STACK;

STACK S1, S2;

void push(STACK *s, int x)
{
    if (s->top == MAX - 1)
        return;

    s->val[++s->top] = x;
}

int pop(STACK *s)
{
    if (s->top == -1)
        return -1;

    return s->val[s->top--];
}

int isempty(STACK s)
{
    return s.top == -1;
}

// ENQUEUE
void enqueue(int x)
{
    push(&S1, x);
}

// DEQUEUE
int dequeue()
{
    if (isempty(S2))
    {
        while (!isempty(S1))
        {
            int x = pop(&S1);
            push(&S2, x);
        }
    }

    if (isempty(S2))
        return -1;

    return pop(&S2);
}

int main()
{
    S1.top = S2.top = -1;

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Deleted: %d\n", dequeue());
    printf("Deleted: %d\n", dequeue());

    enqueue(40);

    printf("Deleted: %d\n", dequeue());
    printf("Deleted: %d\n", dequeue());

    return 0;
}
