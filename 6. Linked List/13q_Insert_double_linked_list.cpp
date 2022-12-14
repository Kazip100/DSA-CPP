#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} *first = NULL;            // declares a structure with name first

// create double linked list
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

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index<0 || index>Length(p) )
        return;

    if(index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = NULL;
        first->prev = t;
        first = t;
    }
    else
    {
        for(i=0; i<index-1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next)
        {
            p->next->prev = t;            
        }
        p->next = t;
    }

}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    Insert(first, 2, 25);
    display(first);
    return 0;
}