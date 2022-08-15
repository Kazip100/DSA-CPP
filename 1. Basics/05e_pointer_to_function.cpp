// pointer to an array
#include<iostream>
using namespace std;

void fun (int A[], int n )  // or void fun(int *A, int n)
//call by reference and call by value function is used

// Arrays are always passed by address and never by values in a function

{
    // cout << sizeof(A)/sizeof(int) << endl;
    // the size of array A[] is taken a pointer i.e. 8 bytes
    // i.e. 8/4 = 2 elements
    
    // for (int a : A)
    // cout <<a;
    // for each loop cannot be used in a function as A[] is not an array but rather
    // a pointer in a function
   
    for (int i =0; i<n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    A[0] = 22;
    //since A[] is a pointer it can also change the value in the original array too
}


int main()
{
    int A[] = {2,4,5,78,11};
    int n = 5;
    
    fun(A,n); 
    // Arrays are always passed by address and never by values in a function
    
    cout << sizeof(A)/sizeof(int) << endl;
    // here, (4*5)/4 = 5 elements
    
    for(int x : A)
    {
    cout << x << " ";
    }
    
    
}



