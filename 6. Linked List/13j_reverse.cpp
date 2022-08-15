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

int count(struct Node *p)
{
    int l=0;
    while(p!=0)             // or while(p)
    {
        l++;
        p = p->next;
    }
    return l;
}

void Reverse1(struct Node *p)
{
    int i=0, *A;
    struct Node *q = p;
    A = (int *)malloc(sizeof(int)*count(p));
    // A = new int[count(p)];
    
    while(q!= NULL )
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    
    q=p;
    i--;
    while( q!= NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }

}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create (A, 5);
    Reverse1(first);

    display(first);
    cout << "\n\n";
    return 0;
}