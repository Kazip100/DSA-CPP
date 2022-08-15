#include<iostream>
using namespace std;

struct Node
{
    int data;    
    // int *next;                   // will point to an integer but we want a pointer that points to a node(structure)
    struct Node *next;              // pointer to itself
} *first = NULL ;                    // first is a global pointer that can be accessed by all
                                    // can be directly accessed or can be passed as a parameter

// always make first a global variable as the need may arise any time to access it                                    

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;          // t is a temporary pointer to create a new node
                                    // last is a temporary pointer that points to the last node of the linked list
    
    first = new Node;               // creates a new node first that stores the first value of linkedlist
    first ->data = A[0];
    first ->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = new Node;               // creates a new node t that stores the next value of array
        t->data = A[i];
        t->next = NULL;
        last->next = t;             // old last link will point to the new link
        last = t;                   // the new node/link will be the last node/link
    }
}

void display(struct Node *p)        // pointer p goes through all the node
{
    while(p!=0)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void RDisplay(struct Node *p)
{
     if(p!=NULL)
     {
        cout << p->data << " ";
        RDisplay(p->next);
        /*
        if we use this code then it will return the linked list in reverse form as values are
        printed only when it is returning

        RDisplay(p->next); 
        cout << p->data << " ";
        */
    }
}

int main()
{
    int A[] = {3,5,7,10,15};            // creates an array
    create (A,5);                       // creates a linked list
    
    display(first);                     // first == A[0]
    cout << "\n";
    RDisplay(first);
}