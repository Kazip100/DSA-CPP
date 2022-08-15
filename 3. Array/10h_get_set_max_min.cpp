#include<iostream>
using namespace std;

struct Array
{
    int A[20], size, length;
};
void Display(struct Array arr)
{
    cout << "Elements are: \n";
    for(int i=0; i< arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << "\n\n";
}

int Get(struct Array arr, int index)
{
    if(index >=0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}
int Set(struct Array *arr, int index, int x)       
// since values are to be changed therefore we use pointers
{
    if(index>=0 && index < arr->length)
        arr->A[index] = x;
}
int Max(struct Array arr)
{
    int Max = arr.A[0];
    int i;
    for(i=0; i<arr.length; i++)
    {
        if(arr.A[i] > Max)
        Max = arr.A[i];
    }
    return Max;
}
int Min(struct Array arr)
{
    int Min = arr.A[0];
    int i;
    for(i=0; i<arr.length; i++)
    {
        if(arr.A[i] < Min)
        Min = arr.A[i];
    }
    return Min;
}
int Sum(struct Array arr)
{
    int total =0, i;
    for(i=0; i< arr.length; i++)
    {
        total = total + arr.A[i];
    }
    return total;
}
float Avg(struct Array arr)
{
    float total =0;
    for(int i=0; i< arr.length; i++)
    {
        total = total + arr.A[i];
    }
    float Average = total / arr.length;
    return Average;
}

int main()
{
    struct Array arr = {{2,3,4,5,6}, 10, 5};
    Display(arr);
    
    cout << Get(arr, 2) << "\n\n";
    
    Set(&arr, 2, 21);
    Display(arr);
    
    cout << "Max is: " << Max(arr) << "\n";
    cout << "Min is: "<< Min(arr) << "\n";
    
    cout << "Sum is: " << Sum(arr) << endl << "Average is: " << Avg(arr);
}


