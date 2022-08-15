#include<iostream>
using namespace std;

struct Array
{
    int A[20], size, length;
};

void Display(struct Array arr)
// taking the structure member as a parameter will let us access all the objects 
// of a structure
{
    int i;
    cout << "Elements are: \n";
    for(i=0; i<arr.length; i++)
        cout << arr.A[i] << " ";
}
int BinarySearch(struct Array arr, int key)
{
    int l,mid,h;
    l = 0;
    h = arr.length-1;
    
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            h = mid - 1;
        else                // if(key > arr.A[mid])
            l = mid + 1;
            
    }
    return -1;              // if key is not found
}

int RBinSearch(int A[], int l, int h, int key)
{
    
    
    if(l<=h)
    {
        int mid = (l+h)/2;
        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            return RBinSearch(A, l, mid-1, key);
        else
            return RBinSearch(A, mid+1, h, key);
    }
    return -1;
}
int main()
{
    struct Array arr = {{2,3,4,5,6}, 10,5};
    Display(arr);
    cout << endl << BinarySearch(arr,5);
    cout << endl << BinarySearch(arr,21);
    
    cout << endl << RBinSearch(arr.A, 0, arr.length-1, 2);
    cout << endl << RBinSearch(arr.A, 0, arr.length-1, 20);
}
