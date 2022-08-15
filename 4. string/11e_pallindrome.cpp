#include<iostream>
using namespace std;

int main()
{
    char A[] = "PyyP";
    char B[5];
    int i,j;
    
    // checking pallinrome using another string
    for(i=0; A[i]!='\0'; i++)
    {}
    i = i-1;
    cout << i << endl;
    
    for(j=0; i>=0; i--,j++)
        B[j] = A[i];
    cout << B << endl;
    
    for(i=0,j=0; A[i]!='\0' && B[j]!='\0'; i++, j++)
    {
        if(A[i] != B[j])
            break;
    }
    
    if(A[i] == B[j])
        cout << "It is a Pallindrome" << endl;
    else
        cout << "It is not a Pallindrome" << endl;
    
        
    // checking pallinrome by swapping
    for(j=0; A[j]!='\0'; j++)
    {}
    j = j-1;
    
    for(i=0; i<j; i++,j--)
    {
        if(A[i] != A[j])
            break;
    }
    if(A[i] == A[j])
        cout << "It is a Pallindrome";
    else
        cout << "It is not a Pallindrome";
    
    
}
