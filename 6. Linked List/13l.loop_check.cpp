#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;    
} *first = NULL, *second= NULL, *third = NULL;

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

int isloop(Node *f)
{
    Node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q!= NULL ? q->next : NULL;
    } while(p && q && p != q);

    if(p==q)
        return true;
    else
        return false;

}

int main()
{
    struct Node *t1, *t2;

    int A[] = {10, 20, 30, 40, 50};
    create(A,5);                                // creates a linked list

    t1 = first->next->next;                     // for creating
    t2 = first->next->next->next->next;         // a loop
    t2->next = t1;                              // in a linked list

    if (isloop(first))
        cout << "It is circular linked list";
    else
        cout << "It is not circular linked list";


    return 0;
}