#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void find_missing(int A[], int n)
{
    int diff = 6;
    for(int i=0; i<n; i++)
    {
        while(A[i]-i != diff)
        {
            cout << i+diff << " ";
            diff++;
        }
    }
}

void find_missing2(int A[], int n)
{
    int h = 19;
    int H[h] = {0};
    for(int i=0; i<n; i++)
        H[A[i]]++;
    
    for(int i=6; i<h; i++)
        if(H[i] == 0)
            cout << i << " ";
}

void find_duplicate(int A[], int n)
{
    int i, h=10;
    int H[h] = {0};
    for(i=0; i<n; i++)
        H[A[i]]++;
    
    for(i=0; i<h; i++)
    {
        if(H[i] > 1)
        {
            cout << i << " is repeated no. of times... " << H[i] << endl;
        }        
    }


}

int main()
{
    int A[] = {6,7,8,9,11,12,15,16,17,19};
    int B[] = {8,3,6,4,6,5,6,8,2,7};
    int n = sizeof(A)/sizeof(A[0]);
    find_missing(A, n);
    cout << endl << endl;
    find_duplicate(B, n);


    return 0;
}