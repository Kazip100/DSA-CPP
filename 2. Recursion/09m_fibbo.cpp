#include<iostream>
using namespace std;

void fiboseq(int n)
{
    int t0 = 0, t1 = 1, tn;
    cout << t0 << " " << t1 << " " ;
    for(int i=2; i<=n; i++)
    {
        tn = t0 + t1;
        cout << tn << " ";
        t0 = t1;
        t1 = tn;
    }

}
int fiboterm(int n)
{
    if(n<=1)
        return n;
    else
        return fiboterm(n-2) + fiboterm(n-1);
}
int main()
{
    fiboseq(6);
    cout << endl;
    cout << fiboterm(6);
}