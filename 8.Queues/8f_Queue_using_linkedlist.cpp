#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = new Node;
    if(t == NULL)
    {
        cout << "Queue is FUll\n";
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
        {
            front = rear = t;            
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int dequeue()
{
    int x = -1;
    struct Node *t;

    if(front == NULL)
        cout << "Queue is Empty ";
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}

void Display(struct Node *p)
{
    
    while(p)
    {
        cout << p->data << " ";
        p = p->next;        
    }
    cout << "\n";
}

int main()
{
    
    enqueue(10);
    enqueue(21);
    enqueue(30);
    enqueue(44);
    enqueue(29);
    enqueue(90);


    Display(front);
    cout << dequeue() << endl;
    Display(front);
}