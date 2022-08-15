// Monolithic program: Program that are interwoven into a single component 
// rather than inside architecturally separate components.

#include<iostream>
using namespace std;

int main()
{
    int length=0, breadth =0;
    //initialise the values to avoid garbages values
    cout<<"Enter Length and Breadth ";
    cin >> length >> breadth;
    
    int area = length * breadth;
    int perimeter = 2*(length + breadth);
    
    cout << "Area is: " << area << endl;
    cout << "Perimeter is: " << perimeter << endl;
}


