#include<iostream>
using namespace std;

int main()
{
    int a=10;
    int *p;                                 // initialising a pointer
    p = &a;                                 // adressing a pointer to a variable

    cout<< a << endl << *p ;                // prints the value of a
    // when getting the value of pointer, * command is used for dereferring a pointer

    cout<< endl << &a << endl << p ;        // prints the address of a 
    
    int A[5] = {2,4,5,56,6}, i;
    p = A;                                  // addressing a pointer to an array
    for(i=0;i<5;i++)
    {
        cout<< p[i] << endl;                // prints the 
    }

}