#include <stdio.h>
#include <stdlib.h>

// Structure for a Threaded Binary Tree Node
typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
    int lBit; // 1: left child,  0: thread to inorder predecessor
    int rBit; // 1: right child, 0: thread to inorder successor
} Node, *TREE;

/**
 * Finds the Inorder Successor of node 'n'
 */
TREE inSucc(TREE n) {
    TREE s = n->right;
    
    // If n has a real right child, successor is the leftmost node of that right subtree
    if (n->rBit == 1) {
        while (s->lBit == 1) {
            s = s->left;
        }
    }
    return s;
}

/**
 * Performs Inorder Traversal using the Head node
 */
void inOrder(TREE head) {
    TREE t = head;
    
    printf("Inorder Traversal: ");
    while ((t = inSucc(t)) != head) {
        printf("[%c] ", t->data);
    }
    printf("\n");
}

/**
 * Inserts node 'n' as the right child of node 't'
 */
void insertRight(TREE t, TREE n) {
    // Step 1: n inherits t's right link and rBit
    n->right = t->right;
    n->rBit = t->rBit;

    // Step 2: n's left link points to t as a thread
    n->left = t;
    n->lBit = 0;

    // Step 3: t's right link now points to n as a child
    t->right = n;
    t->rBit = 1;

    // Step 4: If n inherited a real right child, update the left thread 
    // of n's inorder successor to point back to n
    if (n->rBit == 1) {
        TREE s = inSucc(n);
        s->left = n;
    }
}

/**
 * Helper function to create a new node
 */
TREE createNode(char data) {
    TREE temp = (TREE)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->lBit = 0;
    temp->rBit = 0;
    return temp;
}

/**
 * Helper function to create an empty head node
 */
TREE createHead() {
    TREE head = createNode('-');
    head->lBit = 0;
    head->rBit = 1;
    head->left = head;
    head->right = head;
    return head;
}

int main() {
    // 1. Create Head Node
    TREE head = createHead();

    // 2. Create Root Node 'A' and insert as left child of Head
    TREE nodeA = createNode('A');
    head->left = nodeA;
    head->lBit = 1;
    nodeA->left = head;
    nodeA->right = head;

    // 3. Create Node 'B' and insert to the right of Node 'A'
    TREE nodeB = createNode('B');
    insertRight(nodeA, nodeB);

    // 4. Create Node 'C' and insert to the right of Node 'B'
    TREE nodeC = createNode('C');
    insertRight(nodeB, nodeC);

    // Perform Inorder Traversal
    inOrder(head);

    return 0;
}
