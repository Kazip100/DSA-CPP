#include<iostream>
using namespace std;

int main()
{
    char A[] = "deciiimal";
    char B[] = "medical";
    
    int i, H[26] = {0};
    
    for(i=0; A[i]!='\0'; i++)
    {
        H[A[i] -97] += 1;
    
    }
    for(i=0; B[i]!='\0'; i++)
    {
        H[A[i]-97] -=1;
        if(H[A[i]] < 0 || H[A[i]-97] >0)        
        {
            cout << "Not an Anagram" << endl;
            break;
        }
        
    }
    
    if(B[i] == '\0')
        cout << "It is an Anagram" << endl;
}
