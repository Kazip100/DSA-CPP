#include<iostream>
using namespace std;

double e(int x, int n)
{
    static double num=1,den=1;
    double r;
    if(n==0)
        return 1;
    else
    {
        r = e(x, n-1);
        num = num*x;
        den = den*n;
        return r + num/den;
    }
}

int main()
{
    int a=3,b=10;
    cout << e(a,b);
    
}

