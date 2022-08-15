#include<iostream>
using namespace std;

int power1(int n, int p)
{
    if(p==0)
        return 1;
    else
        return power1(n,p-1)*n;
    
}
int main()
{
    int x = 2, power =9;
    cout << power1(x,power);
}
