#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int col;
    int data;
    struct node *next;
} NODE;
typedef struct head
{
    int rowId;
    struct head *nextRow;
    struct node *col;
} HEAD;
NODE* makeNode(int data, int col)
{
    NODE *temp = malloc(sizeof(NODE));

    temp->data = data;
    temp->col = col;
    temp->next = NULL;

    return temp;
}
HEAD* createHead(int id)
{
    HEAD *h = malloc(sizeof(HEAD));

    h->rowId = id;
    h->nextRow = NULL;
    h->col = NULL;

    return h;
}
void display(HEAD *h)
{
    while(h)
    {
        NODE *rowHead = h->col;

        printf("Row %d: ", h->rowId);

        while(rowHead)
        {
            printf("(%d,%d) ", rowHead->col, rowHead->data);
            rowHead = rowHead->next;
        }

        printf("\n");

        h = h->nextRow;
    }
}
HEAD* sparse(int n, int m, int a[n][m])
{
    HEAD *dummy = createHead(-1);
    HEAD *head = dummy;

    for(int i = 0; i < n; i++)
    {
        head->nextRow = createHead(i);
        head = head->nextRow;

        NODE *newN = NULL;

        for(int j = 0; j < m; j++)
        {
            if(a[i][j] != 0)
            {
                if(head->col == NULL)
                {
                    newN = makeNode(a[i][j], j);
                    head->col = newN;
                }
                else
                {
                    newN->next = makeNode(a[i][j], j);
                    newN = newN->next;
                }
            }
        }
    }

    return dummy->nextRow;
}
int main()
{
    int n, m;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);
    int a[n][m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            a[i][j] = (rand() % 1000) * (rand() % 2);
        }
    }
    printf("\nOriginal Matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    HEAD *h = sparse(n, m, a);
    printf("\nSparse Linked List:\n");
    display(h);
    return 0;
}
