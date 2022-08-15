// we can send a structure as a parameter in call by value
// while we cannot send an array as call by value
// a structure having an array can be a parameter in call by value


#include<iostream>
using namespace std;

struct Rectangle
{
    int length, breadth;
    
};

void fun(Rectangle r)
// call by value
{
    r.breadth  = 22;                        
    // local variable inside fun cannot influence code in main()
    
    cout << r.length << endl << r.breadth << endl;
    //here we don't have to use pointer as r itself is a member and not pointer 
    // to struct Rectangle
    
}

int main()
{
    Rectangle r = {10,5};
    fun (r);   
    cout<<"length is: " << r.length << endl << "breadth is: " << r.breadth << endl;
                     // passing rectangle member in a function
    
}




