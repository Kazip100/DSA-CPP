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

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = new Node;
    second ->data = A[0];
    second ->next = NULL;
    last = second;

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

void Concat(struct Node *p, struct Node *q)
{
    third = p;                  // i.e. third = first
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;                // connects first linked list with the second linked list
    q = NULL;                   // a good practice to nullify when not in used
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)               // for determinig which linked list will be first
    {
        third = last = p;
        p = p->next;
        third->next = NULL;

    }
    else                                
    {
        third = last = q;               // or third = p;
        q =  q->next;
        third ->next = NULL;
    }

    while(p && q)                       // if p and q is not NULL
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last ->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p)
        last ->next = p;
    if(q)
        last ->next = q;

}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {1, 2, 31, 44, 52};

    create(A, 5);
    create2(B, 5);

    cout << "First:\n";
    display(first);

    cout << "\n\n";

    cout << "Second:\n";
    display(second);

    cout << "\n\n";

    Concat(first, second);
    cout << "Concated Linked List:\n";
    display(third);

    // cout << "\n\nAfter Merging:\n";
    // Merge(first, second);
    // display(third);
}