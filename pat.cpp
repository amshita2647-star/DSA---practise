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
int main()
{
    pattern17(5);
}
