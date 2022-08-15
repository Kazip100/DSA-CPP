// Modular Programming
// the program is divided into different components(functions, strucutres and classes)

#include<iostream>
using namespace std;

int area (int a , int b)
{
    // inside area function, the declared integer 'area' is a variable
    //int area = a*b;
    //return area;
    return a*b;
}

int perimeter (int a, int b)
{   
    // inside perimeter function, the declared integer 'perimeter' is a variable
    int perimeter = 2*(a+b);
    return perimeter;
}

int main()
{
    int length =2, breadth =5, ar , peri;
    ar = area(length, breadth);
    peri = perimeter(length, breadth);
    cout << ar << " " << peri;
    
}

