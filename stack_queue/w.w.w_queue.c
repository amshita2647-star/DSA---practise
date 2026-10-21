
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char val[MAX];
    int front, rear;
} Q;

Q createqueue()
{
    Q q;
    q.rear = q.front = 0;
    return q;
}

int isempty(Q q)
{
    return q.front == q.rear;
}

int isfull(Q q)
{
    return (q.rear + 1) % MAX == q.front;
}

int insert(Q *q, char data)
{
    if (isfull(*q))
        return 0;

    q->rear = (q->rear + 1) % MAX;
    q->val[q->rear] = data;
    return 1;
}

char pop(Q *q)
{
    if (isempty(*q))
        return '\0';

    q->front = (q->front + 1) % MAX;
    return q->val[q->front];
}

int main()
{
    char w[300];
    int flag = 1, dot = 0;
    int count[3] = {0, 0, 0};

    printf("Enter the w.w.w string to check: ");
    if (fgets(w, sizeof(w), stdin) == NULL)
        return 0;

    w[strcspn(w, "\n")] = '\0';

    Q q1 = createqueue();
    Q q2 = createqueue();

    for (int i = 0; w[i] != '\0'; i++)
    {
        char c = w[i];

        if (c == '.')
        {
            dot++;
            if (dot > 2)
            {
                flag = 0;
                break;
            }
            continue;
        }

        if (dot == 0)
        {
            if (!insert(&q1, c))
            {
                flag = 0;
                break;
            }
            count[0]++;
        }
        else if (dot == 1)
        {
            if (isempty(q1) || c != pop(&q1))
            {
                flag = 0;
                break;
            }

            if (!insert(&q2, c))
            {
                flag = 0;
                break;
            }
            count[1]++;
        }
        else
        {
            if (isempty(q2) || c != pop(&q2))
            {
                flag = 0;
                break;
            }
            count[2]++;
        }
    }

    if (dot != 2 || count[0] == 0 ||
        count[0] != count[1] ||
        count[1] != count[2] ||
        !isempty(q1) || !isempty(q2))
    {
        flag = 0;
    }

    if (flag)
        printf("It is in w.w.w form");
    else
        printf("It is not in w.w.w form");

    return 0;
}
