#include<iostream>
using namespace std;

// For Diagonal Matrix

int main()
{
    int *A, n, ch, x, i, j;
    cout << "Enter the dimension: ";
    cin >> n;
    A = new int[n*(n+1)/2];
    
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
            // Create Matrix
            case 1: for(i=1; i<=n; i++)
                    {
                        for(j=1; j<=n; j++)
                        {
                            if(i<=j)
                            {
                                cin >> A[ j*(j-1)/2+i-1];
                            }
                        }
                    }
                    
            break;
            
            // Get Matrix Elements
            case 2: cout << "Enter row and column: ";
                    cin >> i >> j;
                    if(i<=j)
                        cout << A[j*(j-1)/2+i-1] << endl;
                    else
                        cout << "0\n";
                    break;
                    
            // Set Matrix Elements
            case 3: cout << "Enter row, column and element: ";
                    cin >> i >> j >> x;
                    if(i<=j)
                        A[j*(j-1)/2+i-1] = x;
                    break;
                    
            // Display Matrix Elements
            case 4: for(i=1; i<=n; i++)
                    {
                        for(j=1; j<=n; j++)
                            {
                                if(i<=j)
                                    cout << A[j*(j-1)/2+i-1] << " ";
                                else
                                    cout << "0 ";
                            }
                            cout << "\n";
                    }
                    break;
            
        }
    }while(ch != 5 );
}



