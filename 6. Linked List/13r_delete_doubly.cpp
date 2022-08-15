#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} *first = NULL;            // declares a structure with name first

// create doubly linked list
void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = new Node;       // stores the memory of structure in heap
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }

}

void display(struct Node *p)
{
    while(p)
    {
        cout << p->data << " ";
        p = p->next;

    }
    cout << "\n";
}

int Length(struct Node *p)
{
    int len = 0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1, i;
    if(index < 1 || index > Length(p) )
        return -1;
    if(index == 1)
    {
        first = first->next;
        if(first)
            first->prev = NULL;
        x = p->data;
        delete p;

    }
    else
    {
        for(i=0; i<index-1; i++)
        {
            p = p->next;            
        }
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);    
    display(first);
    Delete(first, 1);
    display(first);
    return 0;
}