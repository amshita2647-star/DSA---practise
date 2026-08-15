#include <stdio.h>

// Helper function to swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the Max Heap property at subtree rooted with index i
void MaxHeapify(int A[], int n, int i) {
    int largest = i;
    int l = 2 * i;       // Left child index
    int r = (2 * i) + 1; // Right child index

    // Compare left child with current largest
    if (l <= n && A[l] > A[largest]) {
        largest = l;
    }

    // Compare right child with current largest
    if (r <= n && A[r] > A[largest]) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        swap(&A[largest], &A[i]);
        
        // Recursively heapify the affected sub-tree
        MaxHeapify(A, n, largest);
    }
}

// Function to perform Heap Sort
void heapsort(int A[], int n) {
    // Step 1: Build Max Heap (Rearrange array)
    for (int i = n / 2; i >= 1; i--) {
        MaxHeapify(A, n, i);
    }

    // Step 2: Extract elements one by one from heap
    for (int i = n; i >= 1; i--) {
        // Move current root (maximum element) to the end
        swap(&A[1], &A[i]);

        // Call MaxHeapify on the reduced heap of size (i - 1)
        MaxHeapify(A, i - 1, 1);
    }
}

void printArray(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    // 1-based array matching the whiteboard example array (index 0 is unused)
    int A[] = {0, 15, 17, 20, 1, 5, 10, 30};
    int n = 7; // Number of elements

    printf("Original Array:\n");
    printArray(A, n);

    heapsort(A, n);

    printf("Sorted Array (Ascending):\n");
    printArray(A, n);

    return 0;
}
