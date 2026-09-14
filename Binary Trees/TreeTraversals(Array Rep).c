#include<stdio.h>
#define MAX 8
void inOrder(int a[],int index , int n)
{
    if(a[index] != 0 && index <= n)
    {
        inOrder(a,index*2,n);
        printf("%5d",a[index]);
        inOrder(a,index*2+1,n);
    }
}
void preOrder(int a[],int index , int n)
{
    if(a[index] != 0 && index <= n)
    {
        printf("%5d",a[index]);
        preOrder(a,index*2,n);
        
        preOrder(a,index*2+1,n);
    }
}
void postOrder(int a[],int index , int n)
{
    if(a[index] == 0 || index > n)
        return;
    postOrder(a,2*index,n);
    postOrder(a,2*index+1,n);
    printf("%5d",a[index]);
    
}
int main()
{
    int n = 7; // number of nodes
    int a[8]={0,1,2,3,4,5,6,7};
    inOrder(a,1,n);
    printf("\n\n");
    preOrder(a,1,n);
    printf("\n\n");
    postOrder(a,1,n);
}
