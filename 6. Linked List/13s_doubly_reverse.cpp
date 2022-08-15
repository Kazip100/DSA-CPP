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
void Reverse(struct Node *p)
{
    struct Node *temp;
    while(p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p!= NULL && p->next == NULL)
            first = p;
    }
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

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    Reverse(first);
    display(first);
    return 0;
}