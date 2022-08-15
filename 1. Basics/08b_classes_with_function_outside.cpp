// C++ supports generic functions(template function) and generic classes(template classes)

// class with all the functions outside 

#include<iostream>
using namespace std;

class Arithmetic
{
    private:
        int a;
        int b;
        
    public:
        Arithmetic(int a, int b);
        int add();
        int sub();
    
};

        Arithmetic::Arithmetic(int a, int b)
        // :: is the scope resolution
        {
            // a=a here the a refers to a of public 
            this-> a =a;        // pointer to the actual value of a
            this-> b = b;       // as it points to the address of a
        }
        
        int Arithmetic::add()
        {
            return a+b;
        }
        
        int Arithmetic::sub()
        {
            return a-b;
        }
        


int main()
{
    
    Arithmetic ar(10,5), ar2(10,7);
    // object ar passes the value 10 and 5 to class Arithmetic
    cout << "Add: " << ar.add() << endl;
    cout << "Sub: " << ar.sub() << endl;
    
    cout << "Add: " << ar2.add() << endl;
    cout << "Sub: " << ar2.sub() << endl;
    //return 0;
}



