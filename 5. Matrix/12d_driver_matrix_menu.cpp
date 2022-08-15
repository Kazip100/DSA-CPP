#include<iostream>
using namespace std;

//Upper Triangular Matrix

void Create(int A[], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i<=j)
            {
                cin >> A[ j*(j-1)/2+i-1 ];
            }
        }
    }
}

int Get(int A[], int i, int j)
{
    if(i<=j)
        cout << A[j*(j-1)/2+i-1] << endl;
    else
        cout << "0\n";
}

void Set(int A[], int i, int j, int x)
{
    if(i<=j)
        A[j*(j-1)/2+i-1] = x;
}

void Display(int A[], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            {
                if(i<=j)
                    cout << A[j*(j-1)/2+i-1] << " ";
                else
                    cout << "0 ";
            }
            cout << "\n";
    }
}

int main()
{
    int *A, n, i, j, ch, x;
    A = new int[n*(n+1)/2];
    cout << "Enter the dimension of the matrix: ";
    cin >> n;
    do
    {
        //display menu
        cout << "******Choose the option******\n";
        cout << "1. Create Matrix\n";
        cout << "2. Get Matrix\n";
        cout << "3. Set Matrix\n";
        cout << "4. Display Matrix\n";
        cout << "5. Exit\n";
        cin >> ch; 
        
        switch(ch)
        {
            case 1: Create(A, n);
            break;
            
            case 2: cout << "Enter the row and coloumn: ";
                    cin >> i >> j;
                    cout << Get(A, i, j);
            break;
            
            case 3: cout << "Enter the row, column and element: ";
                    cin >> i >> j >> x;
                    Set(A, i, j, x);
            break;
            
            case 4: Display(A, n);
            break;
        }
        
    }while(ch != 5);
    
    
}

