#include <stdio.h>
#include <string.h>

#define MAX 20

typedef struct
{
    char val[MAX];
    int top;
} Stack;

Stack createstack()
{
    Stack s;
    s.top = -1;
    return s;
}

int isempty(Stack s)
{
    return s.top == -1;
}

int isfull(Stack s)
{
    return s.top == MAX - 1;
}

int push(Stack *s, char val)
{
    if (isfull(*s))
        return 0;

    s->top++;
    s->val[s->top] = val;

    return 1;
}

char pop(Stack *s)
{
    if (isempty(*s))
        return '\0';

    char c = s->val[s->top];
    s->top--;

    return c;
}

char top(Stack s)
{
    if (isempty(s))
        return '\0';

    return s.val[s.top];
}

int check(char c)
{
    if (c == '{' || c == '(' || c == '[')
        return 1;

    if (c == '}' || c == ')' || c == ']')
        return 0;

    return -1;
}

int openclose(char close, char open)
{
    return (close == ')' && open == '(') ||
           (close == ']' && open == '[') ||
           (close == '}' && open == '{');
}

int main()
{
    Stack s1 = createstack();
    char ch[MAX];

    printf("Enter the string: ");
    fgets(ch, sizeof(ch), stdin);

    int length = strlen(ch);
    int balanced = 1;

    for (int i = 0; i < length; i++)
    {
        char c = ch[i];

        // Opening bracket
        if (check(c) == 1)
        {
            if (!push(&s1, c))
            {
                balanced = 0;
                break;
            }
        }

        // Closing bracket
        else if (check(c) == 0)
        {
            // No opening bracket available
            if (isempty(s1))
            {
                balanced = 0;
                break;
            }

            char open = pop(&s1);

            // Wrong type of opening bracket
            if (!openclose(c, open))
            {
                balanced = 0;
                break;
            }
        }

        // Other characters are ignored
        else
        {
            continue;
        }
    }

    // If something is still in stack, brackets are unmatched
    if (!isempty(s1))
        balanced = 0;

    if (balanced)
        printf("It is in balanced form\n");
    else
        printf("Not in balanced form\n");

    return 0;
}
