// variable of type, structure on heap and return its address
#include<iostream>
using namespace std;
struct Rectangle
{
    int length, breadth;
    
};

//return a pointer of type rectangle
Rectangle *fun()

{
    // a function *fun() returning an object of type rectangle using a pointer 
    // and it is creating an object in heap
    
    Rectangle *p;
    p = new Rectangle;          // assigning heap memory for Rectangle
    p -> length = 15;           // initialising length and breadth
    p -> breadth = 10;
    
    return p;                   // finally returning the value
}


int main()
{
    Rectangle *ptr = fun();
    // accessing Rectangle values in a function using pointers
    
    cout << "length :" << ptr -> length << endl << "breadth :"<<ptr -> breadth << endl;
    return 0;
}


