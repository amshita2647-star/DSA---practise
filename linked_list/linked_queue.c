#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;
typedef struct queue
{
    NODE *front;
    NODE *rear;
} QUEUE;
QUEUE createQueue()
{
    QUEUE q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}
int isFull(QUEUE *q)
{
    return 0;
}

int isEmpty(QUEUE *q)
{
    if(q->front == NULL)
        return 1;
    else
        return 0;
}
int enqueue(QUEUE *q, int data)
{
    NODE *newnode = (NODE *)malloc(sizeof(NODE));

    if(newnode == NULL)
        return 0;

    newnode->data = data;
    newnode->next = NULL;

    // If queue is empty
    if(q->front == NULL)
    {
        q->front = newnode;
        q->rear = newnode;
    }
    else
    {
        q->rear->next = newnode;
        q->rear = newnode;
    }

    return 1;
}
int dequeue(QUEUE *q)
{
    if(isEmpty(q))
    {
        return -1;
    }

    NODE *temp = q->front;
    int n = temp->data;

    q->front = q->front->next;

    // Queue became empty
    if(q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return n;
}
void printQueue(QUEUE *q)
{
    NODE *temp = q->front;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
