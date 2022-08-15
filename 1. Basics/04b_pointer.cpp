#include<iostream>
using namespace std;

int main()
{
    int *p;                                         // declaring a pointer

    // int A[5] = {2,4,5,56,6}, i;                  // stores memory in stack
    // p = A;                                       // addressing a pointer to an array

    p = new int[5];                                 // initializing, stores memory in heap (rather in stack)
    p[0]=12; p[1]=23; p[2]=22; p[3]=80; p[4]=90;
    for(int i=0;i<5;i++)
    {
        cout << p[i] << endl;
    }
    delete [] p;                                    // clears the memory in heap, mandatory if the program 
                                                    // is big


    // Whatever be the type of pointer, a pointer always takes the same type of memory, i.e. 8 bytes
    int *p1;
    char *p2;
    double *p3;
    float *p4;
    struct Rectangle *p5;                   // pointer of a rectangle
    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;


}