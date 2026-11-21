
#include <stdio.h>
#include <ctype.h>

int isp(char op)
{
    switch(op)
    {
        case '(' : return 0;
        case '?' :
        case 'T' : return 1;

        case '+' :
        case '-' : return 2;

        case '*' :
        case '/' : return 3;

        case '^' : return 4;

        case '~' :
        case 'u' : return 5;
    }
    return -1;
}

int icp(char op)
{
    if(op == '(') return 6;
    return isp(op);
}

int rightAssociative(char op)
{
    return (op == '^' || op == '?' || op == '~' || op == 'u');
}

/* Pop operator and add to postfix */

void popOperator(char STACK[], char post[], int *top, int *postIndex)
{
    char op = STACK[(*top)--];

    if(op == 'T')
    {
        post[(*postIndex)++] = '?';
        post[(*postIndex)++] = ':';
    }
    else
        post[(*postIndex)++] = op;
}

void toPostfix(char *in, char *post)
{
    char STACK[25];
    int top = 0, postIndex = 0;
    int expectOperand = 1;

    while(*in)
    {
        if(isspace(*in))
        {
            in++;
            continue;
        }

        if(isalpha(*in) || isdigit(*in))
        {
            post[postIndex++] = *in;
            expectOperand = 0;
        }

        else if(*in == '(')
        {
            STACK[++top] = *in;
            expectOperand = 1;
        }

        else if(*in == ')')
        {
            while(top > 0 && STACK[top] != '(')
                popOperator(STACK, post, &top, &postIndex);

            if(top > 0)
                top--;

            expectOperand = 0;
        }

        else if(*in == ':')
        {
            while(top > 0 && STACK[top] != '?')
                popOperator(STACK, post, &top, &postIndex);

            if(top > 0)
            {
                top--;              // Remove ?
                STACK[++top] = 'T'; // Mark completed ternary
            }

            expectOperand = 1;
        }

        else
        {
            char op = *in;

            /* Identify unary operators */
            if(expectOperand && op == '-')
                op = '~';

            else if(expectOperand && op == '+')
                op = 'u';

            /* Common ISP-ICP popping condition */
            while(top > 0 && STACK[top] != '(' &&
                  (isp(STACK[top]) > icp(op) ||
                  (isp(STACK[top]) == icp(op) &&
                   !rightAssociative(op))))
            {
                popOperator(STACK, post, &top, &postIndex);
            }

            STACK[++top] = op;
            expectOperand = 1;
        }

        in++;
    }

    while(top > 0)
        popOperator(STACK, post, &top, &postIndex);

    post[postIndex] = '\0';
}

int main()
{
    char in[100], post[100];

    printf("Enter infix expression: ");
    scanf("%s", in);

    toPostfix(in, post);

    printf("Postfix: %s", post);

    return 0;
}
