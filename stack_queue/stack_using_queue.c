
#include <stdio.h>
#define MAX 100

typedef struct
{
    int val[MAX];
    int front, rear;
} Q;

Q createQueue()
{
    Q q;
    q.front = q.rear = 0;
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

int enqueue(Q *q, int x)
{
    if (isfull(*q))
        return 0;

    q->rear = (q->rear + 1) % MAX;
    q->val[q->rear] = x;
    return 1;
}

int dequeue(Q *q)
{
    if (isempty(*q))
        return -1;

    q->front = (q->front + 1) % MAX;
    return q->val[q->front];
}

// Stack using two queues
Q q1, q2;

void push(int x)
{
    enqueue(&q2, x);

    while (!isempty(q1))
        enqueue(&q2, dequeue(&q1));

    Q temp = q1;
    q1 = q2;
    q2 = temp;
}

int pop()
{
    if (isempty(q1))
        return -1;

    return dequeue(&q1);
}

int main()
{
    q1 = createQueue();
    q2 = createQueue();

    push(10);
    push(20);
    push(30);

    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());

    return 0;
}
