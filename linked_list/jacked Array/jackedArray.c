#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

typedef struct head
{
    int rowId;
    struct head *nextRow;
    struct node *col;
} HEAD;


/* Create a column node */
NODE* makeNode(int data)
{
    NODE *temp = malloc(sizeof(NODE));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->data = data;
    temp->next = NULL;

    return temp;
}


/* Create a row header */
HEAD* createHead(int id)
{
    HEAD *h = malloc(sizeof(HEAD));

    if (h == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    h->rowId = id;
    h->nextRow = NULL;
    h->col = NULL;

    return h;
}


/* Display the complete structure */
void display(HEAD *h)
{
    while (h != NULL)
    {
        printf("Row %d: ", h->rowId);

        NODE *rowHead = h->col;

        while (rowHead != NULL)
        {
            printf("%5d", rowHead->data);
            rowHead = rowHead->next;
        }

        printf("\n");

        h = h->nextRow;
    }
}


int main()
{
    srand(time(NULL));

    int rows = 5;

    /* Dummy/head node */
    HEAD *head = createHead(-1);

    HEAD *temp = head;

    /* Create rows */
    for (int i = 0; i < rows; i++)
    {
        /* Create new row */
        temp->nextRow = createHead(i);

        temp = temp->nextRow;

        /* Random number of columns: 0 to 9 */
        int columns = rand() % 10;

        if (columns == 0)
            continue;

        /* Create first column node */
        NODE *n = makeNode(rand() % 1000);

        temp->col = n;

        /* Create remaining column nodes */
        for (int j = 1; j < columns; j++)
        {
            n->next = makeNode(rand() % 1000);
            n = n->next;
        }
    }

    /* Skip dummy node */
    head = head->nextRow;

    display(head);

    return 0;
}
