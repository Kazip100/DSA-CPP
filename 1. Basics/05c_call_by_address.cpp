/* Paramter Passing Methods
 call by address
 Call By Address is also known as Call By Pointers. In this method, the programmer 
 passes the addresses of the actual arguments to the formal parameters.
*/

#include<iostream>
using namespace std;

// void function is only modifying the results so we don't have to assgin anything
// to it, a function can normally return one value but a call by address can return 
// more than one value by passing addresses using pointers

void swap(int *a, int *b)
// void function means that it won't return any value 
// but rather forces the code to make changes in it's variale
{
    int temp;   
    temp = *a;              // temp stores value 12
    *a = *b;                // a stores value 9
    *b = temp;              // b will store value of temp(12)
}

int main()
{
    int num1 =12, num2 = 9;
    
    swap(&num1, &num2);         
    // sends the address of num1 and num2 to a and b respectively
    // after swapping num1 = *a = 9
    // num2 = *b = 12
    cout << "First swap Number: " << num1 << endl;
    cout << "Second swap Number: " << num2 << endl;
    
}


