#include<iostream>
using namespace std;

struct Array 
{
    int A[20], size, length;
};

void display(struct Array arr)
// taking the structure member as a parameter will let us access all the objects 
// of a structure
{
    int i;
    cout << "\nElements are: \n";
    for(i=0; i<arr.length; i++)
        cout << arr.A[i] << " ";
    
}

int LinearSearch(struct Array arr, int key)
// here we are using call by value as we don't have to change the value inside the Array
// we only have to search for it
{
    int i;
    for(i=0; i<arr.length; i++)
    {
        if(key == arr.A[i])
            return i;
    }
    return -1;
}

int main()
{
    struct Array arr= { {2,3,4,5,6}, 10,5};
    cout << "Index where 6 lies is: "<< LinearSearch(arr,6);
    display(arr);
    
}
