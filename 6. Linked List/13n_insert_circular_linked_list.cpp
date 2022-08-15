#include<iostream>
using namespace std;

// Code error in counting the length of the linked list




struct Node
{
    int data;
    struct Node *next;    
} *Head = NULL;

// create circular linked list
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = new Node;
    Head ->data = A[0];
    Head ->next = Head;
    last = Head;

    for(i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *h)
{
    do
    {
        cout << h->data << " ";
        h = h->next;
    }while(h != Head);
    cout <<"\n";
}

void Rdisplay(struct Node *h)
{
    static int flag = 0;
    if(h!=Head || flag == 0)
    {
        flag = 1;
        cout << h->data << " ";
        Rdisplay(h->next);
    }
}

int Length(struct Node *p)
{
    int len = 0;
    Node *temp = p;

    do
        {
            len++;
            temp=temp->next;        
        }while(temp != p);

    return len;
}


void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index<0 || index >Length(Head) )     //checking if index is valid
        return;

    if(index == 0)
    {
        t = new Node;
        t->data = x;
        if(Head == NULL)
        {
            Head = t;
            Head->next = Head;

        }
        else
        {
            while(p->next != Head)
            {
                p = p->next;
            }
            
            p->next = t;
            t->next = Head;
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
        p->next = t;
    }
}


int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A,5);
    // Insert(Head, 2, 10);
    // display(Head);
    
    cout << Length(Head) << endl;
    Rdisplay(Head); 
    
    return 0;
}
