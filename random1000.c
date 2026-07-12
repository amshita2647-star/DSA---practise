//PS : Call attachTem 1000 times to attach random terms if exponents repeat add the coeff , and if the sum is 0 remove that term from the polynomial
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct { int coef, expo; } TERM;
typedef struct { TERM t[1000]; int nT; } POLY;
POLY createPoly() {POLY p; p.nT=0; return p;}
void printPoly(POLY p)
{   for (int i=0; i<p.nT; i++)
        printf("+%dx^%d", p.t[i].coef, p.t[i].expo);
    return;
}
POLY attachTerm(POLY p, TERM t)
{   int i = p.nT-1;
    while (i>=0) { 
        if (p.t[i].expo == t.expo) 
        { 
            int sum=p.t[i].coef+ t.coef; 
            if(sum!=0) { p.t[i].coef=sum;} 
            else
            {
                for(int j=i;j<p.nT-1;j++)
                {
                    p.t[j]=p.t[j+1];
                }
                p.nT--;
            }
            return p; 
        }
        else i = i - 1; 
    } //duplicate term testing
    i = p.nT-1;
    //attaching a new term in the decreasing order of exponent
    while ((i>=0) && (p.t[i].expo < t.expo)) {p.t[i+1] = p.t[i]; i = i - 1;}
    p.t[i+1] = t; p.nT = p.nT + 1;
    return p;
}   
TERM randomterm()
{
    TERM t;
    t.coef = rand()%1000;
    t.expo = rand()%1000;
    return t;
}
POLY randompoly(int n)
{
    POLY p = createPoly();
    for(int i=0; i<n; i++)
    {
        TERM t=randomterm();
        p=attachTerm(p,t);
    }
    return p;
}
int main()
{
    srand(time(NULL));
   POLY P1=randompoly(1000);
   printPoly(P1);
   printf("\nthe number of terms in p1 = %d",P1.nT);
   return 0;    
}
