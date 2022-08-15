// structure is used for defining uder defined data types
#include<iostream>
using namespace std;

struct Rectangle
{
    int length, breadth;
    char x;

};

int main()
{
    //struct Rectangle r;                     //declaring a structure variable of Rectangle
    struct Rectangle r = {10,5};            //declaring and inintialising variable of Rectangle
    cout << "Area of Rectangle is: " << r.length * r.breadth << endl;
    // re-assign new values of the structure members
    r.length = 15;
    r.breadth = 10;
    cout << r.length << "\n";
    cout << "Area of New Rectangle is: " << r.length*r.breadth << endl;

    cout << sizeof(r);
    // integer takes 4 bytes, and character takes 1 byte, as we declared 2 integers and 1 character
    // Therefore a total of 4*2+1 = 9 bytes will be used
    // but the computer can easily read 4 bytes or nearest biggest size at a time therefore size of char 
    // will be taken as 4 bytes
    // but only one byte shall be used for char data type
    // Therefore 4*3 = 12 bytes will be used

}

