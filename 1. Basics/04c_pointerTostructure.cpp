#include<iostream>
using namespace std;

struct Rectangle
{
    int length, breadth;
};

int main()
{
    Rectangle r = {10, 5};
    cout << r.length << " " << r.breadth << endl;

    Rectangle *p = &r;                  // *p points to r
    // for a pointer to a structure, dot operator cannot be used any further
    // but rather the arrow operator is to be used    
    cout << p-> length;

}

