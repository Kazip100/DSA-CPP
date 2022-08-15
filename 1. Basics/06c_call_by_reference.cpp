
#include<iostream>
using namespace std;

struct Rectangle
{
    int length, breadth;
    
};

void fun(Rectangle &r)
// call by reference
{
     
    cout << r.length << endl << r.breadth << endl;
    // here r is a member of Rectangle
    
    r.breadth  = 22;
    // the new value of breadth will replace actual value of breadth
    
}

int main()
{
    Rectangle r = {10,5};
    fun (r);   
    cout<<"length is: " << r.length << endl << "breadth is: " << r.breadth << endl;
    
}




