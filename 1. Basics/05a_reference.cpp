#include<iostream>
using namespace std;

int main()
{
    int a =10;
    // refernce is another name given to a variable
    int &r = a;                     // & before a variable is 'reference'

    cout<< a << " " << r << endl;
    r++;                            // as the value of r is incremented, a value also gets incremented
    cout << a << " " << r << endl;
    int b=30;
    r = b;
    cout << a << " " << r;


}