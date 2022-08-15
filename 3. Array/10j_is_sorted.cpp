#include<iostream>
using namespace std;
struct Array
{
     int A[10];
     int size;
     int length;
};

 void Display(struct Array arr)
 {
    int i;
    cout << "Elements are:\n";
    for(i=0;i<arr.length;i++)
       cout << arr.A[i] << " ";
 }
int isSorted(struct Array arr)
{
 int i;
    for(i=0; i<arr.length-1; i++)
    {
    if(arr.A[i]>arr.A[i+1])
        return 0;
    }
    return 1;
}
int main()
{
    struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
    cout << isSorted(arr1) << endl;
    Display(arr1);
    return 0;
}

