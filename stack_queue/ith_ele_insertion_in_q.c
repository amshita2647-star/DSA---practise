int insertIth(QUEUE *q, int i, int data)
{
    if (isFull(*q))
        return 0;

    int size = (q->rear - q->front + MAX) % MAX;

    if (i < 1 || i > size + 1)
        return 0;

    int temp[MAX];
    int k = 0, x;

    while (deleteQ(q, &x))
        temp[k++] = x;

    for (int j = 0; j < k; j++)
    {
        if (j == i - 1)
            insertQ(q, data);

        insertQ(q, temp[j]);
    }

    if (i == k + 1)
        insertQ(q, data);

    return 1;
}
