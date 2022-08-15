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

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if(first == NULL)
        first = t;
    else
    {
        while(p && p->data < x)
        {
            q = p;                      // q points at node p
            p = p->next;
        }
        if(p==first)                    // if new element qual to first node data
        {
            t->next = first;
            first = t;
        }
        else                            
        {
            t->next = q->next;
            q->next = t;            
        }
    }
    
}

int main()
{
    // int A[] = {5,10,20,30,40};
    // create(A,5);
    // SortedInsert(first, 35);
    // display(first);

    // inserting in a NULL linked list
    SortedInsert(first, 35);
    SortedInsert(first, 45);    
    SortedInsert(first, 30);
    display(first); cout << endl;
    SortedInsert(first, 20);
    SortedInsert(first, 21);
    SortedInsert(first, 35);

    display(first);
}

