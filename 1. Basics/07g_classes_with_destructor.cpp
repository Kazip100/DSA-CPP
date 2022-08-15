#include<iostream>
using namespace std;

class Rectangle
{
    private:
        int length, breadth; 
    
    public:
        
        Rectangle()
        // constructor, for initialising length and breadth
        // length and breadth are class members
        {
            length = 0;
            breadth = 0;
        }
        
        Rectangle (int l, int b)
        // l and b are class parameters
        {
            length = l;
            breadth = b;
        }
        
        int area()
        {
            return length * breadth;
        }
    
        int perimeter()
        {
            return 2*(length + breadth);
        }
        
        void setLength(int l)                   
        //setLength and setBreadth are mutator function for setting the properties
        {
            length = l;
        }
        void setBreadth(int b)
        {
            breadth = b;
        }
        
        int getLength()                        
        // getLength and getBreadth are accessor function for writting the properties
        {
            return length;
        }
        int getBreadth()
        {
            return breadth;
        }
        
        // norally we have to destroy/deallocatte the dynamically deallocatted memory but here we
        // don't have anything like that
        ~Rectangle()
        {
            cout<<"Destructor";
        }
};

int main()
{
    Rectangle r(10,5);
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;
    
}
