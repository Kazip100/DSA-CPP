// Heap Sort 
#include<iostream>
#include <stdio.h>
using namespace std;

void Insert(int A[],int n) 
{ 
    int i=n,temp; 
    temp=A[i];
    // here one liner conditional statemets are not applied because array values starts from index 1
    while(i>1 && temp>A[i/2]) 
    { 
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

int Delete(int A[],int n)
{
    int i,j,x,temp,val;
    val=A[1];
    x=A[n];
    A[1]=A[n];
    A[n]=val;
    i=1;
    j=i*2;
    while(j<=n-1)
    {
        if(j<n-1 && A[j+1]>A[j])        //comparing adjacent values
            j=j+1;
        
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
        else
            break;
    } 
    return val;
}

int main()
{
    // int H[]={0,14,15,5,20,30,8,40}; 
    int H[] = {0,10,20,30,25,5,40,35};
    int i;
    for(i=2;i<=7;i++)
        Insert(H,i);

    for(i=1; i<=7; i++)                     // since value at index 0 is 0
        cout << H[i] << " ";                // displays in binary heap format
    cout << endl;


    //deletes all the binary heap and returns a normal array
    for(i=7;i>1;i--)
    {
        Delete(H,i);
    }
    
    // shows the list of all deleted binary heap nodes 
    // and also displays it in sorted format
    for(i=1;i<=7;i++)
    {
        printf("%d ",H[i]);
    }
    printf("\n");
    return 0; 
} 