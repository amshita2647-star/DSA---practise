#include<stdio.h>
typedef struct student
{
    int reg;
    float gpa;
    char grade;
}stu;
void merge(stu s[],int l,int m,int h)
{
    int i =l; int j=m+1; int k=0;
    stu B[100];
    while(i<=m && j<=h)
    {
        if(s[i].gpa < s[j].gpa)
        {
            B[k]=s[i];
            i++; k++;
        }
        else
        {
            B[k]=s[j];
            j++; k++;
        }
    }
    while(i<=m)
    {
        B[k]=s[i];
        k++; i++;
    }
    while(j<= h)
    {
        B[k]=s[j];
        k++; j++;
    }
    for(int i=0;i<h-l+1;i++)
    {
        s[l+i] = B[i];
    }

}
void MergeSort(stu s[],int l,int h)
{

    if(l<h)
    {
        int m =(l+h)/2;
        MergeSort(s,l,m);
        MergeSort(s,m+1,h);
        merge(s,l,m,h);
    }

}
int main()
{
    stu s[5];

    for(int i=0;i<5;i++)
    {
        printf("Enter reg,gpa,credits for student %d\n",i+1);
        scanf("%d",&s[i].reg);
        scanf("%f",&s[i].gpa);
        scanf("%c",&s[i].grade);
    }
    MergeSort(s,0,5);
    for(int j=0;j<5;j++)
    {
        printf("Reg: %d Gpa: %f Credit: %\c \n",s[j].reg,s[j].gpa,s[j].grade);
    }
}
