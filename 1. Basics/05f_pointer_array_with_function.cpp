// function returning an array

#include<iostream>
using namespace std;

int *fun(int size)
{
    int *p;                     //initialising pointer p to access the heap memory
    p = new int[size];
    
    for(int i=0; i<size; i++)
    p[i] = i+1;
    return p;
}

int main()
{
    int *ptr, sz = 10;
    //initialising pointer ptr to access the function in heap memory
    ptr = fun(sz);
    
    for(int i=0; i<sz; i++)
    cout<<ptr[i]<<" ";
    
}

