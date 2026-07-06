#include<iostream>
using namespace std;
void pattern17(int n)
{
    
    for(int i=0;i<n;i++)
    {
        char a='A';
        int stop_pnt=(2*i+1)/2;
        for(int j=1;j<=n-i-1;j++)
        {
            cout<<" ";
        }
        for(int k=0;k<2*i+1;k++)
        {
            cout<<a;
            if(k<stop_pnt){a++;}
            else
            {  a--; }
            
            
        }
        cout<<endl;
    }
}
void pattern18(int n) //alpha triangle pattern//
{
    char a= 'A'+n-1;
    for(int i=0;i<n;i++)
    {
        for(char b=a-i;b<=a;b++)
        {
            cout<<b;
        }
        cout<<endl;
    }
}
void pattern19(int n) //Symmetric-Void Pattern//
{
    int initial_space=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<initial_space;j++)
        {
            cout<<" ";
        }
        initial_space+=2;
        for(int j=1;j<=n-i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    initial_space=2*(n-1);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<initial_space;j++)
        {
            cout<<" ";
        }
        initial_space-=2;
        for(int j=1;j<=n-i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern20(int n) //symmetric-Butterfly pattern//
{
    int initial_space=2*(n-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<initial_space;j++)
        {
            cout<<" ";
        }
        initial_space-=2;
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    initial_space=2;
    for(int i=n-2;i>=0;i--)
    {
        
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        } 
        for(int j=0;j<initial_space;j++)
        {
            cout<<" ";
        }
        initial_space+=2;
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
int main()
{
    pattern17(5);
}
