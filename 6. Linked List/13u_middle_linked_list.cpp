#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*first = NULL;

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

        last->next = t;
        last = t;
    }


}

void display(Node *p)
{
    while(p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    
}

int Length(struct Node *p)
{
    int len = 0;
    while(p!=0)
    {
        len++;
        p = p->next;
    }
    return len;
}

int Middle(Node *p)
{
    int len = Length(first) / 2;
    for(int i=0; i<len; i++)
    {
        p = p->next;
    }
    return p->data;    
}

int Middle2(Node *f)
{
    Node *p, *q;    
    p = q = f;              // pointers for checking the nodes
    
    while(q!=NULL)
    {
        q = q->next;
        q = q!= NULL ? q->next : NULL;
        if(q!=NULL)
        p = p->next;
    }

    return p->data;
}

int main()
{
    int A[] = {2, 3, 67, 22, 31, 4, 90};
    create(A, 7);

    display(first);
    cout << endl << Length(first) << endl;
    
    cout << Middle(first) << endl;
    cout << Middle2(first) << endl;
}