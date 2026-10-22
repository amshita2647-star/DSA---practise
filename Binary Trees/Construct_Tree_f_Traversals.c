// construct tree from preorder and inorder traversal
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int preIndex = 0;

struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int search(int inorder[], int start, int end, int key) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == key)
            return i;
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[],
                       int start, int end) {
    if (start > end)
        return NULL;

    int rootValue = preorder[preIndex++];
    struct Node* root = createNode(rootValue);

    if (start == end)
        return root;

    int pos = search(inorder, start, end, rootValue);

    root->left = buildTree(preorder, inorder,
                           start, pos - 1);

    root->right = buildTree(preorder, inorder,
                            pos + 1, end);

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int preorder[] = {40, 20, 10, 30, 60, 50, 70};
    int inorder[]  = {10, 20, 30, 40, 50, 60, 70};

    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct Node* root =
        buildTree(preorder, inorder, 0, n - 1);

    printf("Inorder: ");
    inorderTraversal(root);

    printf("\nPreorder: ");
    preorderTraversal(root);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int postIndex;

struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int search(int inorder[], int start, int end, int key) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == key)
            return i;
    }
    return -1;
}

struct Node* buildTree(int postorder[], int inorder[],
                       int start, int end) {
    if (start > end)
        return NULL;

    int value = postorder[postIndex--];
    struct Node* root = createNode(value);

    if (start == end)
        return root;

    int pos = search(inorder, start, end, value);

    // Build right subtree first
    root->right = buildTree(postorder, inorder,
                            pos + 1, end);

    // Then build left subtree
    root->left = buildTree(postorder, inorder,
                           start, pos - 1);

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    int postorder[] = {10, 30, 20, 50, 70, 60, 40};
    int inorder[] = {10, 20, 30, 40, 50, 60, 70};

    int n = sizeof(inorder) / sizeof(inorder[0]);
    postIndex = n - 1;

    struct Node* root =
        buildTree(postorder, inorder, 0, n - 1);

    printf("Inorder: ");
    inorderTraversal(root);

    printf("\nPostorder: ");
    postorderTraversal(root);

    return 0;
}
