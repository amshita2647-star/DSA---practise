#include<stdio.h>
typedef struct student
{
    int reg;
    int date;
    int month;
    int year;
}stu;
void swap(stu *a , stu *b)
{
    stu temp = *a;
    *a=*b;
    *b=temp;
}
int comparedate(stu s1,stu s2)
{
    if(s1.year < s2.year)
    {
        return 1;
    }
    else if(s1.year == s2.year)
    {
        if(s1.month < s2.month)
        {
            return 1;
        }
        else if(s1.month > s2.month)
        {
            return 0;
        }
        else
        {
            if(s1.date <= s2.date)
            {
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}
int partition(stu A[],int p,int r)
{
    stu pivotal=A[p];
    int i = p;
    for(int j=p+1;j<=r;j++)
    {
        if(comparedate(A[j] , pivotal)==1)
        {
            i=i+1;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[p],&A[i]);
    return i;
}
void QuickSort(stu A[],int p,int r)
{

    if(p<r)
    {
        int k= partition(A,p,r);
        QuickSort(A,p,k-1);
        QuickSort(A,k+1,r);
    }

}
void getdet(stu s[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter reg,DOB of stu %d ",i+1);
        scanf("%d",&s[i].reg);
        scanf("%d",&s[i].date);
        scanf("%d",&s[i].month);
        scanf("%d",&s[i].year);
    }
}
void printdet(stu s[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Reg no : %d\nDOB: %d/%d/%d\n\n",s[i].reg,s[i].date,s[i].month,s[i].year);
    }
}
int main()
{
    stu s[3];
    getdet(s,3);
    QuickSort(s,0,3);
    printdet(s,3);
}
