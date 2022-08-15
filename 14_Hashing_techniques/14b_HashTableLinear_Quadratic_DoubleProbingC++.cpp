#include <iostream>
#define SIZE 10
#define PRIME 7
using namespace std;
 
template <class T>
void Print(T& vec, int n, string s)
{
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++)
    {
        cout << vec[i] << flush;
        if (i < n-1)
        {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int Hash(int key)
{
    return key % SIZE;
}
 
int LinearProbe(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;
    while (H[(idx+i) % SIZE] != 0)
    {
        i++;
    }
    return (idx + i) % SIZE;
}
 
void LInsert(int H[], int key)
{
    int idx = Hash(key);
 
    if (H[idx] != 0)
    {
        idx = LinearProbe(H, key);
    }
    H[idx] = key;
}
 
int LSearch(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;
    while (H[(idx+i) % SIZE] != key)
    {
        i++;
        if (H[(idx + i) % SIZE] == 0)
        {
            return -1;
        }
    }
    return (idx + i) % SIZE;
}


int QuadraticProbe(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;
    while (H[(idx+i*i) % SIZE] != 0)
    {
        i++;
    }
    return (idx + i*i) % SIZE;
}
 
void QInsert(int H[], int key)
{
    int idx = Hash(key);
 
    if (H[idx] != 0)
    {
        idx = QuadraticProbe(H, key);
    }
    H[idx] = key;
}
 
int QSearch(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;
    while (H[(idx+i*i) % SIZE] != key)
    {
        i++;
        if (H[(idx + i*i) % SIZE] == 0)
        {
            return -1;
        }
    }
    return (idx + i*i) % SIZE;
}

int PrimeHash(int key)
{
    return PRIME - (key % PRIME);
}
 
int DoubleHash(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != 0)
    {
        i++;
    }
    return (idx + i * PrimeHash(idx)) % SIZE;
}
 
void DInsert(int H[], int key)
{
    int idx = Hash(key);
 
    if (H[idx] != 0)
    {
        idx = DoubleHash(H, key);
    }
    H[idx] = key;
}
 
int DSearch(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != key)
    {
        i++;
        if (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] == 0)
        {
            return -1;
        }
    }
    return (Hash(idx) + i * PrimeHash(idx)) % SIZE;
}


int main()
{
 
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, " A");
 
    // Hash Table
    int HT[10] = {0};
    for (int i=0; i<n; i++)
    {
        DInsert(HT, A[i]);
    }
    Print(HT, SIZE, "HT");
 
    // int index = QSearch(HT, 25);
    // cout << "key found at: " << index << endl;
 
    // index = QSearch(HT, 35);
    // cout << "key found at: " << index << endl;
 
    return 0;
}