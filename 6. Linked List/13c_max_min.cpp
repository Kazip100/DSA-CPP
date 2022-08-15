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

int Max(struct Node *p)
{
    int max = p->data;          // points to the first initial value
    p = p->next;                // shifts to the next value
    while(p)
    {
        if(p->data > max)       // compares between tn+1 and tn
            max = p->data;
        p = p->next;
    }
    return max;
}

int Min(Node *p)
{
    int min = p->data;
    //int min = INT32_MIN;

    p = p->next;
    while(p)
    {
        if(min > p->data)
            min = p->data;
        else    
            p = p->next;
    }
    return min;
}

int RMax(struct Node *p)
{
    int x=0;
    if(p==0)
        return INT32_MIN;
    else
    {
        x = RMax(p->next);
        if(x > p->data)
            return x;
        else
            return p->data;
    }
}

int RMax2(struct Node *p)
{
    int x=0;
    if(p==0)
        return INT32_MIN;
    x = RMax2(p->next);             
    return x> p->data ? x: p->data;        // ternary operator: if x > p->data then print x else print p->data

}

int main()
{
    int A[] = {3,5,7,10,15};
    //create (A,0);
    //display(first);

    cout << "\n";
    cout << "Max is: " << Max(first);
    cout << "\nMax is: " << RMax(first);
    cout << "\nMax is: " << RMax2(first);
    //cout << "\nMin is: " << Min(first);

}
