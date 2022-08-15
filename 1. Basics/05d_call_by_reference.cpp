// Paramter Passing Methods
// call by reference

#include<iostream>
using namespace std;

// call by referncef is same as call by address only difference being, we use
// ampersand instead of pointers in function variable declaration
// the variables in the function are like reference variables (stores not only address but also values)

void swap (int &a, int &b)		// call by reference
// void function means that it won't return any value 

{
  int temp;
  temp = a;			// inside the function of call by reference
  a = b;			// we don't have to use pointers
  b = temp;
}

int main ()
{
  int num1 = 12, num2 = 9;

  swap (num1, num2);		// we don't have to assign '&' in call by reference

  cout << "First swap Number: " << num1 << endl;
  cout << "Second swap Number: " << num2 << endl;

}




