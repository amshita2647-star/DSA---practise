#include <stdio.h>

#define MAX 100

// Function to add two sparse matrices stored in 2D array triplet format
void addSparse(int A[][3], int B[][3], int C[][3]) {
    // Check if matrix dimensions match
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        printf("Matrix addition not possible: Dimensions do not match.\n");
        return;
    }

    // Assign dimensions to result matrix
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    int i = 1, j = 1, k = 1;
    int nA = A[0][2]; // Number of non-zero terms in A
    int nB = B[0][2]; // Number of non-zero terms in B

    while (i <= nA && j <= nB) {
        // Compare row indices
        if (A[i][0] < B[j][0]) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        } 
        else if (A[i][0] > B[j][0]) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        } 
        else {
            // Row indices are equal, compare column indices
            if (A[i][1] < B[j][1]) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = A[i][2];
                i++; k++;
            } 
            else if (A[i][1] > B[j][1]) {
                C[k][0] = B[j][0];
                C[k][1] = B[j][1];
                C[k][2] = B[j][2];
                j++; k++;
            } 
            else {
                // Same row and column position -> Add values
                int sum = A[i][2] + B[j][2];
                if (sum != 0) { // Only store non-zero sums
                    C[k][0] = A[i][0];
                    C[k][1] = A[i][1];
                    C[k][2] = sum;
                    k++;
                }
                i++; j++;
            }
        }
    }

    // Copy remaining terms of Matrix A
    while (i <= nA) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    // Copy remaining terms of Matrix B
    while (j <= nB) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    // Total non-zero terms in resulting matrix C
    C[0][2] = k - 1;
}

void printSparse(int matrix[][3]) {
    int terms = matrix[0][2];
    printf("Row\tCol\tValue\n");
    printf("---------------------\n");
    for (int i = 0; i <= terms; i++) {
        printf("%d\t%d\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

int main() {
    // 4x4 Sparse Matrix A with 3 non-zero elements
    int A[MAX][3] = {
        {4, 4, 3},  // [rows, cols, non-zero count]
        {0, 1, 5},  // A[0][1] = 5
        {1, 2, 8},  // A[1][2] = 8
        {3, 0, 2}   // A[3][0] = 2
    };

    // 4x4 Sparse Matrix B with 3 non-zero elements
    int B[MAX][3] = {
        {4, 4, 3},  // [rows, cols, non-zero count]
        {0, 1, 3},  // B[0][1] = 3 (Matches A's position)
        {2, 1, 4},  // B[2][1] = 4
        {3, 0, 7}   // B[3][0] = 7 (Matches A's position)
    };

    int C[MAX][3]; // Result Matrix

    printf("Sparse Matrix A:\n");
    printSparse(A);

    printf("\nSparse Matrix B:\n");
    printSparse(B);

    addSparse(A, B, C);

    printf("\nResultant Sparse Matrix C (A + B):\n");
    printSparse(C);

    return 0;
}
