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

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x=-1;
    int i;
    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else
    {
        for(i=0; i<index-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

int main()
{
    int A[] = {10,20,30,40,50};
    create(A,5);
    display(first); cout << endl;
    cout << "Deleted Element is: " << Delete(first, 4) << endl;
    display(first);
    return 0;
}