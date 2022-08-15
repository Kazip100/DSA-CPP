#include <iostream>
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
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
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
    while (p != 0)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int count(struct Node *p)
{
    int l = 0;
    while (p != 0) // or while(p)
    {
        l++;
        p = p->next;
    }
    return l;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > count(p)) //checks if the index is valid or not
        return;

    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

void InsertLast(struct Node *p, int x)
{
    struct Node *t, *last;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = last = t;
    }

    else
    {
        last = first;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = t;
    }
}

int main()
{
    // insert new node in a pre-defined linked list
    int A[] = {111, 112, 113};
    create(A, 3);
    //Insert(first, 2, 39);
    //display(first);

    // Insert a new user defined linked list
    Insert(first, 0, 94);
    Insert(first, 1, 95);
    Insert(first, 2, 96);
    display(first);

    cout << "\n\n";
    InsertLast(first, 999);
    display(first);

    cout << "\n\n";
    Insert(first, 3, 97);
    Insert(first, 4, 98);
    display(first);

    cout << "\n\n";
    Insert(first, 5, 99);
    display(first);

    cout << "\n\n";
    InsertLast(first, 199);
    display(first);
}