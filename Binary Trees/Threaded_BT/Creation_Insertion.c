typedef struct node
{
    int data;
    struct node *left, *right;
    int lBit, rBit;
} NODE;

typedef NODE* TREE;

//inorder Succ
TREE inSucc(TREE n)
{
    TREE s = n->right;

    if(n->rBit == 1)
    {
        while(s->lBit == 1)
            s = s->left;
    }

    return s;
}

//inorder pred
TREE inPred(TREE n)
{
    TREE p = n->left;

    if(n->lBit == 1)
    {
        while(p->rBit == 1)
            p = p->right;
    }

    return p;
}

//insert right
void insertRight(TREE t, TREE n)
{
    // Step 1: Copy existing right link
    n->right = t->right;
    n->rBit = t->rBit;

    // Step 2: Make left thread to parent
    n->left = t;
    n->lBit = 0;

    // Step 3: Make n the right child of t
    t->right = n;
    t->rBit = 1;

    // Step 4: Update successor's thread
    if(n->rBit == 1)
    {
        TREE s = inSucc(n);
        s->left = n;
    }
}

//insert left
void insertLeft(TREE t, TREE n)
{
    // Step 1: Copy existing left link
    n->left = t->left;
    n->lBit = t->lBit;

    // Step 2: Make right thread to parent
    n->right = t;
    n->rBit = 0;

    // Step 3: Make n the left child of t
    t->left = n;
    t->lBit = 1;

    // Step 4: Update predecessor's thread
    if(n->lBit == 1)
    {
        TREE p = inPred(n);
        p->right = n;
    }
}

//complete insert
void insert(TREE head, int x)
{
    TREE t, n;

    n = malloc(sizeof(NODE));
    n->data = x;

    // Empty tree
    if(head->lBit == 0)
    {
        n->left = head;
        n->right = head;

        n->lBit = 0;
        n->rBit = 0;

        head->left = n;
        head->lBit = 1;

        return;
    }

    t = head->left;  // Root is on LEFT of head

    while(1)
    {
        if(x < t->data)
        {
            if(t->lBit == 1)
                t = t->left;

            else
            {
                insertLeft(t, n);
                return;
            }
        }

        else if(x > t->data)
        {
            if(t->rBit == 1)
                t = t->right;

            else
            {
                insertRight(t, n);
                return;
            }
        }

        else
        {
            printf("Duplicate element");
            free(n);
            return;
        }
    }
}
//Traversal
void inOrder(TREE head)
{
    TREE t = head->left;

    if(head->lBit == 0)
        return;

    // Find first node
    while(t->lBit == 1)
        t = t->left;

    // Visit remaining nodes
    while(t != head)
    {
        printf("%d ", t->data);
        t = inSucc(t);
    }
}
