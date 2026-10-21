int deleteIth(QUEUE *q, int i)
{
    if (isEmpty(*q))
        return 0;

    int size = (q->rear - q->front + MAX) % MAX;

    if (i < 1 || i > size)
        return 0;

    int pos = (q->front + i) % MAX;

    // Shift subsequent elements left
    while (i < size)
    {
        int next = (pos + 1) % MAX;
        q->val[pos] = q->val[next];
        pos = next;
        i++;
    }

    q->rear = (q->rear - 1 + MAX) % MAX;

    return 1;
}
