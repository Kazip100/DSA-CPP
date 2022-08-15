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

int count2(struct Node *p)
{
    int x=0;
    if(p)
    {
        x = count2(p->next);
        return x+1;
    }
    else    
        return 0;
}

int Rcount(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return Rcount(p->next) + 1;
}

int sum(struct Node *p)
{
    int sum = 0;
    while(p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int sum2(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return sum2(p->next) + p->data;
}
int main()
{
    int A[] = {3,5,7,10,15,8,12,20};
    create(A,8);
    cout << "Sum is: " << sum (first);
    cout << "\nSum is: " << sum2 (first);
    cout << "\nLength of Linked List is: " << count(first);
    cout << "\nLength of Linked List is: " << count2(first);
    cout << "\nLength of Linked List is: " << Rcount(first);
    return 0;
}