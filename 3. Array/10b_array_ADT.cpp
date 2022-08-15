#include<iostream>
using namespace std;

struct Array 
{
    int *A, size, length;
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
    struct Array arr;
    int i,n;
    cout << "Enter the size of the array: ";
    cin >> arr.size;
    arr.A = new int[arr.size];                      // accessing heap memory
    
    
    cout << "Enter the number of inputs: ";
    cin >> n;
    
    cout <<"Enter all Elements:\n";
    for(i=0; i<n; i++)
        cin >> arr.A[i];
    
    arr.length = n;
    display(arr);
    
}

