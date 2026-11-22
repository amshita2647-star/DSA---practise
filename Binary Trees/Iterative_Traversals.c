//inorder iterative approach
void inorder(BT *root)
{
    STACK s;
    init(&s);

    BT *temp = root;

    while(temp != NULL || !isEmpty(&s))
    {
        // Go to the leftmost node
        while(temp != NULL)
        {
            push(&s, temp);
            temp = temp->left;
        }

        // Pop and print
        temp = pop(&s);
        printf("%d ", temp->data);

        // Move to the right subtree
        temp = temp->right;
    }
}

//preorder 
void preorder(BT *root)
{
    if(root == NULL)
        return;

    STACK s;
    init(&s);

    push(&s, root);

    while(!isEmpty(&s))
    {
        BT *temp = pop(&s);

        printf("%d ", temp->data);

        if(temp->right != NULL)
            push(&s, temp->right);

        if(temp->left != NULL)
            push(&s, temp->left);
    }
}

//Two stack method - postOrder
void postorder(BT *root)
{
    if(root == NULL)
        return;

    STACK s1, s2;
    init(&s1);
    init(&s2);

    push(&s1, root);

    while(!isEmpty(&s1))
    {
        BT *temp = pop(&s1);

        push(&s2, temp);

        if(temp->left != NULL)
            push(&s1, temp->left);

        if(temp->right != NULL)
            push(&s1, temp->right);
    }

    while(!isEmpty(&s2))
    {
        BT *temp = pop(&s2);
        printf("%d ", temp->data);
    }
}
