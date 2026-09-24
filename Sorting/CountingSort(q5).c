#include <stdio.h>
#include <stdlib.h>
typedef struct pair
{
    int r;
    int recordno;
} p;
void CountSort(p A[], p B[], int n)
{
    int largest = A[0].r;
    for (int i = 1; i < n; i++)
    {
        if (A[i].r > largest)
        {
            largest = A[i].r;
        }
    }

    int C[100] = {0};
    for (int i = 0; i < n; i++)
    {
        C[A[i].r]++;
    }
    for (int i = 1; i <= largest; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        B[C[A[i].r] - 1].r = A[i].r;
        B[C[A[i].r] - 1].recordno = A[i].recordno;
        C[A[i].r]--;
    }
}
void getdetails(p A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i].r = rand() % 100;
        A[i].recordno = i + 1;
    }
}
void printdet(p A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d : %d\n", A[i].r, A[i].recordno);
    }
}
int main()
{
    p A[50];
    p B[50];
    getdetails(A, 50);
    CountSort(A, B, 50);
    printdet(B, 50);
}
