#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int deleted;          // 0 = active, 1 = deleted
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->deleted = 0;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {

    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);

    else if (data > root->data)
        root->right = insert(root->right, data);

    else {
        // Node already exists
        if (root->deleted == 1)
            root->deleted = 0;       // Reactivate the node
    }

    return root;
}

// Lazy deletion
struct Node* deleteNode(struct Node* root, int data) {

    if (root == NULL)
        return NULL;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else {
        // Node found
        root->deleted = 1;           // Just mark as deleted
    }

    return root;
}

// Search
int search(struct Node* root, int data) {

    if (root == NULL)
        return 0;

    if (data < root->data)
        return search(root->left, data);

    else if (data > root->data)
        return search(root->right, data);

    else {
        if (root->deleted == 1)
            return 0;                // Logically deleted

        return 1;                    // Active node
    }
}

// Inorder traversal
void inorder(struct Node* root) {

    if (root == NULL)
        return;

    inorder(root->left);

    if (root->deleted == 0)
        printf("%d ", root->data);

    inorder(root->right);
}

int main() {

    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Before deletion: ");
    inorder(root);

    // Lazy delete 30
    deleteNode(root, 30);

    printf("\nAfter deleting 30: ");
    inorder(root);

    if (search(root, 30))
        printf("\n30 found");
    else
        printf("\n30 not found");

    return 0;
}
