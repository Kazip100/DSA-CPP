#include<iostream>
using namespace std;

int main()
{
    int A[5] = {2, 5, 8, 1, 9};         // static array
    int *p;                             // pointer to access heap memory
    int i, n =5;
    p = new int[5];                     // dynamic array that can be resized
    p[0] = 2;
    p[1] = 3;
    p[2] = 7;
    p[3] = 11;
    p[4] = 112;

    for(i=0; i<n; i++)
        cout << A[i] << " ";
    
    cout << endl;

    for(i=0; i<n; i++)
        cout << p[i] << " ";
}