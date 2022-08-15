// Structure and functions using a function for initialising variables

#include<iostream>
using namespace std;

// writing the data member and all the functions together at a single place is call OOP
// in C++, all members in structure are by default public
// whereas all members in class are by deafult private

class Rectangle
{
    
public:
    int length, breadth;


// since initialise function is now inside structure we don't have to take Rectangle 
// as a parameter
//void initialise(Rectangle *r, int l, int b)

void initialise( int l, int b)
{
    //r -> length = l ;
    //r -> breadth = b;
    // since initialise function is now inside structure then we don't have to used
    // arrow operator to point towards length and breadth
    length =l;
    breadth = b;
    
}

// int area (int a , int b)
// instead of taking length and breadth as seperate parameters, a function can directly
// take structure as a parameter (which will also contain length and breadth as parameter)

int area ()
{
    // since the function can directly access the structure Rectangle r, 
    // therefore dot opeartor is not used
    return length*breadth;
}

int perimeter ()
{   
    // since the function can directly access the structure Rectangle r, 
    // therefore dot opeartor is not used
    return 2*(length + breadth);
}

};


int main()
{
    //Rectangle r = {0,0};         // not valid in class
    Rectangle r;
    
    
    int l=2, b=4;
    
    //initialise(&r, l, b);
    // initialise is now officially a member of structure, therefore we can use 
    // dot operator on the function itself to access the value
    r.initialise(l,b);
    
    
    // instead of taking length and breadth as seperate parameters, a function can directly
    // take structure as a parameter (which will also contain length and breadth as parameter)
    
    // ar = area(length, breadth);
    // peri = perimeter(length, breadth);
    
    //int ar = area (r);
    int ar = r.area();
    
    //int peri = perimeter(r);
    int peri = r.perimeter();
    
    
    
    cout << ar << " " << peri;
    
}


