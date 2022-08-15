#include<iostream>
using namespace std;

struct Array 
{
    int A[20], size, length;
};

void display(struct Array arr)
{
    int i;
    cout << "\nElements are: \n";
    for(i=0; i<arr.length; i++)
        cout << arr.A[i] << " ";    
}

int main()
{
    struct Array arr = {{3,65,78,32,1},20,5};
    // here, values are entered in the format of values, size and length
    
    display(arr);
    
}

