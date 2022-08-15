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

struct Node *LSearch(struct Node *p, int key)       // p takes a pointer to a structure node
{
    while(p!=0)
    {
        if(key == p->data)
            return p;               // p is node, therefore to get this value a struct Node must be declared in int main
        p = p->next;
    }
    return NULL;
}
struct Node *RSearch(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next, key);
}

int main()
{
    struct Node *temp;              // temporary structure(node) to return values of LSearch/RSearch
    int A[] = {3, 5, 16, 7, 9, 1, 3, 8};
    create (A, 8);

    temp = LSearch(first, 5);
    if(temp)
        cout << "Key is found " << temp->data;
    else
        cout << "Key is not found";

    cout << "\n\n";

    temp = RSearch(first, 4);
    if(temp)
        cout << "Key is found " << temp->data;
    else
        cout << "Key is not found";
    return 0;

}

