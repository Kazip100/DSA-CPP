#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    char A[] = "Python";
    char B[7];
    int i=0,j;
    
    // Reversing a string by using another array
    while(A[i] != '\0') {i++;}
    i = i-1;    
    for(int j=0; i>=0; i--, j++)
    {
        B[j] = A[i];
    }
    
    cout << B << endl;
    
    
            
    // Reversing a string by swapping
    char t;
    for(j=0; A[j]!=0; j++)
    {}
    j = j-1;
    for(i=0; i<j; i++,j--)
    {
        t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
    cout << A << endl;
    
    
} 

