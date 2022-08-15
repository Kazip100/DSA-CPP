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
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next =t;
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

struct Node *ImSearch (struct Node *p, int key)
{
    Node *q = NULL;
    while(p)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        else
        {
            q = p;          // pointer q moves along with p
            p = p->next;
        }        
    }
    return NULL;
}

int main()
{
    int A[] = {2, 5, 7, 10, 6};
    create(A,5);
    struct Node *temp;
    temp = ImSearch(first, 7);

    if(temp)
        cout << "Key is found: " << temp->data;
    else
        cout << "Key is not found";

    //display(first);
}

