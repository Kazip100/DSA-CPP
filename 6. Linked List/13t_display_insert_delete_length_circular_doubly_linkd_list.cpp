#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} *Head = NULL;            // declares a structure with name Head

// create doubly linked list
void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    Head = new Node;       // stores the memory of structure in heap
    Head->data = A[0];
    Head->prev = Head->next = Head;
    last = Head;

    for(i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;      

        last->next = t;
        Head->prev = t;
        last = t;
    }

}

void display(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;

    }while( p != Head );
    cout << "\n";
}


int Length(struct Node *h)
{
    int len;
    do
    {
        len++;
        h = h->next;
    }while(h != Head);
    return len;

}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index<0 || index > Length(Head) )     //checking if index is valid
        return;

    if(index == 0)
    {
        t = new Node;
        t->data = x;
        if(Head == NULL)
        {
            Head = t;
            Head->next = Head;
            Head->prev = Head;
        }
        else
        {
            while(p->next != Head)
            {
                p = p->next;
            }            
            p->next = t;
            t->next = Head;
            t->prev = p;
            Head->prev = t;
            Head = t;                   // new Head Position
        }
    }
    else
    {
        for(i=0; i<index-1; i++)
        {
            p = p->next;
        }
        
        t = new Node;
        t->data = x;
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
        
    }
}


int Delete(Node *p, int index)
{
    struct Node *q;
    int i, x;

    if(index<0 || index > Length(Head))
        return -1;

    if(index == 1)
    {
        while(p->next != Head)
        {
            p = p->next;
        }
        x = Head->data;
        if(Head == p)
        {
            delete Head;
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            p->next->prev = p;

            delete Head;
            Head = p->next;
        }
    }    
    else
    {
        for(i=0; i<index-2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        q->next->prev = p;
        x = q->data;
        delete q;

    }
    return x;

}

int main()
{
    int A[] = {3,4,5,7,10};
    create(A, 5);
    display(Head);
    cout << "Length is: "<< Length(Head) << endl;
    Insert(Head, 3, 21);
    display(Head);
    cout << endl << Delete(Head, 2) << endl;
    display(Head);
}