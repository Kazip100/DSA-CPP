#include <iostream>
#include <vector>
using namespace std;
 
// Lecture based
// T(n) : log(n)                depends on the height of the tree i.e. log(n) base 2
// S(n) : 
void InsertA(int A[], int n)
{
    int i = n;
    int temp = A[n];
    // conditional statemets are applied because array values starts from index 0
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2])
    {
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    A[i] = temp;
}
void InsertB(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}
 

// STL vector based
void Insert(vector<int>& vec, int key)
{
    // Insert key at the end
    auto i = vec.size();
    vec.emplace_back(key);
 
    // Rearrange elements: Indices are not DRY :-(
    while (i > 0 && key > vec[i % 2 == 0 ? (i/2)-1 : i/2])
    // conditional statemets are applied because array values starts from index 0
    {
        vec[i] = vec[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    vec[i] = key;
}
 
template <class T>

void Print(T& vec, int n)
{
    cout << "Max Heap: [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
 
int main() 
{
 
    int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
    InsertA(a, 9);
    Print(a, sizeof(a)/sizeof(a[0]));                   // gives array and array size as parameters
    cout << endl;
 
    // STL based
    vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};
    Print(v, v.size());
    v.reserve(15);  // Reserve space for 15 elements
 
    Insert(v, 50);
    Print(v, v.size());
 
    return 0;
}