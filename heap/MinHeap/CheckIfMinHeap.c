#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} BT;

typedef struct {
    int front, rear;
    BT* t[100];
} que;

void initi(que *q) {
    q->front = 0;
    q->rear = 0;
}

int isfull(que *q) {
    return (q->rear == 100);
}

int isempty(que *q) {
    return (q->front == q->rear);
}

void enqueue(BT *t, que *q) {
    if (isfull(q)) return;
    q->rear = q->rear + 1;
    q->t[q->rear] = t;
    
}

BT* dequeue(que *q) {
    if (isempty(q)) return NULL;
    q->front = q->front + 1;
    BT* temp = q->t[q->front];
    return temp;
}

BT* makeNode(int data) {
    BT *t = (BT *)malloc(sizeof(BT));
    t->val = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

BT* insert(BT *t, int data) {
    BT* new = makeNode(data);
    if (!t) return new;

    que q; // Allocate queue on the stack dont use pinter to it
    initi(&q);
    enqueue(t, &q);

    while (!isempty(&q)) {
        BT *tem = dequeue(&q);

        // Check Left Child
        if (!tem->left) {
            tem->left = new;
            return t; // Returned root
        } else {
            enqueue(tem->left, &q);
        }

        // Check Right Child
        if (!tem->right) { // Fixed typo: tem instead of temp
            tem->right = new;
            return t;
        } else {
            enqueue(tem->right, &q);
        }
    }
    return t;
}

void display(BT *t) {
    if (t) {
        display(t->left);
        printf("%5d", t->val);
        display(t->right);
    }
}

int countNodes(BT *t) {
    if (!t) return 0;
    return 1 + countNodes(t->left) + countNodes(t->right);
}

// Check Min-Heap property and completeness (1-based index)
int isMinHeap(BT *root, int c, int nodes) {
    if (!root) return (c > nodes); // Must be beyond node count if NULL

    if (c > nodes) return 0;

    if (root->left && root->left->val < root->val) return 0;
    if (root->right && root->right->val < root->val) return 0;

    return isMinHeap(root->left, 2 * c, nodes) && 
           isMinHeap(root->right, 2 * c + 1, nodes);
}

int main() {
    BT* t = NULL;

    // Building a Min-Heap: parent <= children
    t = insert(t, 10);
    t = insert(t, 20);
    t = insert(t, 30);
    t = insert(t, 40);

    printf("Inorder Traversal:\n");
    display(t);
    printf("\n");

    int totalNodes = countNodes(t);
    if (isMinHeap(t, 1, totalNodes)) {
        printf("The binary tree IS a Min Heap.\n");
    } else {
        printf("The binary tree IS NOT a Min Heap.\n");
    }

    return 0;
}
