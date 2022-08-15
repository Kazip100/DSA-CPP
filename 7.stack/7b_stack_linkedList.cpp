#include<iostream>
using namespace std;

struct Node 
{
    int data;
    Node *next;
} *top = NULL;               

// if there is one stack in my program then having a global top is a good choice

void push(int x)
{
    struct Node *t;
    t = new Node;

    if(t == NULL)
        cout << "Stack is Full\n";
    else
        t->data = x;
        t->next = top;
        top = t;

}

int pop()
{
    struct Node *t;
    int x = -1;

    if(top == NULL)
        cout << "Stack is empty\n";
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int main()
{
    push(10);
    push(20);
    push(350);

    Display();

    cout << pop();



}