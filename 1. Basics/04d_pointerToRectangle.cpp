#include<iostream>
using namespace std;

struct Rectangle
{
    int length, breadth;
};

int main()
{
    Rectangle *p;
    p = new Rectangle;              // storing pointer p memory in heap

    p -> length = 15;               // declaring value of pointer 
    p -> breadth = 10;

    cout << p -> length << endl;    
    cout << p -> breadth << endl;
    delete [] p;                    // clears p value in heap memory


}