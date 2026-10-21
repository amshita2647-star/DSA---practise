
#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct
{
    int val[MAX];
    int top;
} Stack;

Stack createstack()
{
    Stack s;
    s.top = 0;
    return s;
}

int is_empty(Stack s)
{
    return s.top == 0;
}

int is_full(Stack s)
{
    return s.top == MAX;
}

int push(Stack *s, int val)
{
    if (is_full(*s))
        return 0;

    s->val[s->top] = val;
    s->top++;
    return 1;
}

int pop(Stack *s)
{
    if (is_empty(*s))
        return -999;

    s->top--;
    return s->val[s->top];
}

int operation(int a, int b, char op)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int main()
{
    Stack s1 = createstack();
    char post[MAX];

    printf("Enter postfix expression: ");
    scanf("%999s", post);

    int n = strlen(post);

    for (int i = 0; i < n; i++)
    {
        char c = post[i];

        if (c >= 'a' && c <= 'z')
        {
            push(&s1, c - 'a' + 1);
        }
        else
        {
            int right = pop(&s1);
            int left = pop(&s1);

            push(&s1, operation(left, right, c));
        }
    }

    printf("Result = %d\n", pop(&s1));

    return 0;
}
