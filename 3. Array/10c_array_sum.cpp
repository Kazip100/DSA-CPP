#include<iostream>
using namespace std;
struct Array
{
    int *A, size, length;
};

void display(struct Array arr)
{
    for(int i=0; i<arr.length; i++)
        cout << arr.A[i] << " ";
}

int sum(struct Array arr)
{
    int sum = 0;
    for(int i=0; i<arr.length; i++)
        sum += arr.A[i];
    return sum;
}
int main()
{
    struct Array arr;
    int i, n;
    cout << "Enter the size of the array: ";
    cin >> arr.size;

    cout << "Total Number of inputs: ";
    cin >> arr.length;

    cout << "Enter all the elements:\n";
    for(i=0; i<n; i++)
    {
        cin >> arr.A[i];
    }
    arr.length = n;
    display(arr);
    cout << sum(arr);




}