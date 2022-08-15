// C++ supports generic functions(template function) and generic classes(template classes)

// Templates allows the user to run the same function with many data types
// i.e. the program can work for int, float, double etc.

#include<iostream>
using namespace std;

template<class T>
class Arithmetic
{
    private:
        T a;            
        // in places where all the data types are given we have to replace it with T
        T b;
        
    public:
        Arithmetic(T a, T b);
        T add();
        T sub();
    
};

        template<class T>
        Arithmetic<T> :: Arithmetic(T a, T b)
        // :: is the scope resolution
        {
            // a=a here the a refers to a of public 
            this-> a =a;        // pointer to the actual value of a  
            this-> b = b;       // as it points to the address of a  
        }
        
        template<class T>
        T Arithmetic<T> :: add()
        {
            return a+b;
        }
        
        template<class T>
        T Arithmetic<T> :: sub()
        {
            return a-b;
        }
        


int main()
{
    
    Arithmetic<float> ar(10.1,5), ar2(10.67,7);
    // object ar passes the value 10 and 5 to class Arithmetic
    cout << "Add: " << ar.add() << endl;
    cout << "Sub: " << ar.sub() << endl;
    
    cout << "Add: " << ar2.add() << endl;
    cout << "Sub: " << ar2.sub() << endl;
    return 0;
}


