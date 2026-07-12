//create 2 polynomial each of size 100 p1 with odd only exponential values and p2 with even only exponential values , co efficients with range -10 to 10 value p3 to add 
//p1 and p2 p3 should have 200 values
#include <stdio.h>
#include<stdlib.h>
typedef struct { int coef, expo; } TERM;
typedef struct { TERM t[100]; int nT; } POLY;
POLY createPoly() {POLY p; p.nT=0; return p;}
void printPoly(POLY p)
{   for (int i=0; i<p.nT; i++)
        printf("+%dx^%d", p.t[i].coef, p.t[i].expo);
    return;
}
POLY attachTerm(POLY p, TERM t)
{   int i = p.nT-1;
    while (i>=0) { 
        if (p.t[i].expo == t.expo) { return p; }
        else i = i - 1; 
    } //duplicate term testing
    i = p.nT-1;
    //attaching a new term in the decreasing order of exponent
    while ((i>=0) && (p.t[i].expo < t.expo)) {p.t[i+1] = p.t[i]; i = i - 1;}
    p.t[i+1] = t; p.nT = p.nT + 1;
    return p;
}
POLY createoddpoly() 
{
    POLY p;
    p.nT = 100;
    int index = 0; 
    for(int i=199; i>=1; i-=2) 
    {
        p.t[index].coef = (rand()%21) - 10;
        p.t[index].expo = i;
        index+=1;
    }
    return p;
}
POLY createevenpoly() 
{
    POLY p;
    p.nT = 100;
    int index = 0;
    for(int i=200; i>=2; i-=2) 
    {
        p.t[index].coef = (rand()%21) - 10;
        p.t[index].expo = i;
        index+=1;
    }
    return p;
}
POLY addpoly(POLY p1, POLY p2)
{
    POLY p3 = createPoly();
    int i=0,j=0;
    while(i<=p1.nT-1 && j<=p2.nT-1)
    {
        if(p1.t[i].expo ==p2.t[j].expo)
        {
            TERM t;
            t.coef=p1.t[i].coef+ p2.t[j].coef;
            t.expo=p1.t[i].expo;
            i++;j++;
            p3=attachTerm(p3,t);
        }
        else if(p1.t[i].expo > p2.t[j].expo)
        {
            p3=attachTerm(p3,p1.t[i]);
            i++;
        }
        else
        {
            p3=attachTerm(p3,p2.t[j]);
            j++;
        }
    }
    while(i<=p1.nT-1)
    {
        p3=attachTerm(p3,p1.t[i]);
        i++;
    }
    while(j<=p2.nT-1)
    {
        p3=attachTerm(p3,p2.t[j]);
        j++;
    }
    return p3;
}
int main()
{
   POLY P1=createoddpoly();
   POLY P2=createevenpoly();
   printf("\n P1 = "); printPoly(P1); 
   printf("\n P2 = "); printPoly(P2);
   POLY P3 = addpoly(P1, P2);
   printf("\n P3 = "); printPoly(P3);
   printf("The number of terms in p3 =%d",P3.nT);
   return 0;    
}
