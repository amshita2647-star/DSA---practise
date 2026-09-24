#include<stdio.h>
#include<math.h>
typedef struct line
{
    int x1,x2,y1,y2;
    float distance;
}line;
void calculateDistance(line l[],int n)
{
    for(int i=1;i<n;i++)
    {
        int a1 = l[i].x1;
        int a2 = l[i].x2;
        int b1= l[i].y1;
        int b2 = l[i].y2;
        l[i].distance=sqrt((b2-b1)*(b2-b1) + (a2-a1)*(a2-a1));
    }
}
void getDetails(line l[],int n)
{
    for(int i=1;i<n;i++)
    {
        printf("Enter the points of line %d",i);
        scanf("%d",&l[i].x1);
        scanf("%d",&l[i].y1);
        scanf("%d",&l[i].x2);
        scanf("%d",&l[i].y2);
    }
}
void swap(line *a , line *b)
{
    line temp = *a;
    *a=*b;
    *b=temp;
}
void Heapify(line A[],int i,int n)
{
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;
    if(left <= n && A[left].distance > A[largest].distance)
    {

        largest = left;
    }
    if(right <= n && A[right].distance > A[largest].distance)
    {

        largest=right;
    }
    if(largest != i)
    {
        swap(&A[i],&A[largest]);
        Heapify(A,largest,n);
    }
    return ;

}
void HeapSort(line A[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        Heapify(A,i,n);
    }
    for(int i=n;i>=2;i--)
    {
        swap(&A[1],&A[i]);
        Heapify(A,1,i-1);
    }
}
void printdet(line l[],int n)
{
    for(int i=1;i<n;i++)
    {
        printf("(x1: %d y1: %d ) ---- (x2: %d y2: %d ) ---- dis : %0.2f \n",l[i].x1,l[i].y1,l[i].x2,l[i].y2,l[i].distance);
    }
}
int main()
{
    line l[6];
    getDetails(l,6);
    calculateDistance(l,6);
    HeapSort(l,5);
    printdet(l,6);
}
