// array is used to store simkilar data types

#include<iostream>
using namespace std;

int main()
{
    int i; 
    // int B[5];                        // Declaring the array B[] with 5 elements
    int A[10] = {2,3,5,10,7};            // Declaring and Initialising the array A
    // arrays declared are 10 but 5 values are given, the rest 5 values are 0 by default or garbage value
    // and will still take 4 bytes of memory
    // size of int is 4 bytes

    for(i=0; i<5; i++)
    {
        cout<<A[i]<<endl;
    }

    for(int x : A)                      // Loops through all the elements of array A
    {
        cout<<x<<" ";

    }
    cout<<"\n";
    cout<< "Size of Array is: " <<sizeof(A)<<endl;
    cout<<"The 2nd element of Array A is: " <<A[1];

}
