#include<stdio.h>
typedef struct str
{
    char arr[100];
}str;
void InsertionSort(str s[],int n)
{
    for(int i=1;i<n;i++)
    {
         char st[100];
         strcpy(st,s[i].arr);
        int j=i-1;
        while(j >= 0 && strcmp(s[j].arr,st) > 0)
        {
            strcpy(s[j+1].arr,s[j].arr);
            j=j-1;
        }
        strcpy(s[j+1].arr,st);
    }

}
int main()
{
    str s[5];
    strcpy(s[0].arr,"Orange");
    strcpy(s[1].arr,"Apple");
    strcpy(s[2].arr,"Ball");
    InsertionSort(s,3);
    for(int i=0;i<=2;i++)
    {
        printf("%s\n",s[i].arr);
    }

}
