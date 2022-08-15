#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;    
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first ->data = A[0];
    first ->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)

{
    while(p!=0)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int isSorted(struct Node *p)
{
    int x = INT32_MIN;
    while(p!= NULL)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

int main()
{
    int A[] = {10,2,30,40,50};
    create(A,5);

    if(isSorted(first))
    {
        cout << "Sorted\n";

    }
    else
    {
        cout << "Not Sorted\n";
    }

    return 0;
}