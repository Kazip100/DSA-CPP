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

void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
        arr-> A[arr->length++] = x;
    
    // updating the length or else the last digit won't be available
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if(index >=0 && index<= arr->length )
    // checking whether index is within given array range
    {
        for(i=arr-> length; i>index; i--)
            arr-> A[i] = arr-> A[i-1];
        arr -> A[index] = x;
        arr -> length++;            
        // updating the length or else the last digit won't be available
        
        
    }
    
}

int Delete(struct Array *arr, int index)
// we used data type int as return statements are used
{
    int x=0, i;
    if(index >= 0 && index < arr-> length)
    {
        x=arr-> A[index];
        for(i=index; i< arr-> length-1; i++)
        {
            arr-> A[i] = arr-> A[i+1];
        }
    arr-> length--;
    return x;
    }
    return 0;       // will run if the index is not found/ not valid
}

int main()
{
    struct Array arr = {{3,65,78,32,1},10,5};
    // here, values are entered in the format of values, size and length
    Append(&arr, 10);
    display(arr);
    cout << endl<< arr.length << endl;
    
    
    Insert(&arr, 2, 21);
    display(arr);
    cout << endl << arr.length << endl;
    
    cout << "\nDeleted element is: "<< Delete(&arr, 3);
    display(arr);
    cout << endl << arr.length << endl;
}






