// we can send a structure as a parameter in call by value
// while we cannot send an array as call by value
// a structure having an array can be a parameter in call by value


#include<iostream>
using namespace std;

struct Rectangle
{
    int length, breadth;
    
};

void fun(Rectangle *r)
// call by address
{
     
    
    cout << r -> length << endl << r-> breadth << endl;
    // here r is a pointer therfore arrow command is used
    
    r -> breadth  = 22;
    // the new value of breadth will replace actual value of breadth
    
}

int main()
{
    Rectangle r = {10,5};
    fun (&r);   
    cout<<"length is: " << r.length << endl << "breadth is: " << r.breadth << endl;
                     // passing rectangle member in a function
    
}



