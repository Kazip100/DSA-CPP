#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};


class Stack
{

private:
    Node *top;
public:
    Stack()
    {
        top = NULL;
    }
    void push(int x);
    int pop();
    void Display();

};

void Stack :: push(int x)
{
    struct Node *t;
    t = new Node;           // or Node *t = new Node;

    if(t == NULL)
        cout << "Stack is Full";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack :: pop()
{
    int x = -1;
    if(top == NULL)
        cout << "Stack is Empty\n";
    else
    {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void Stack :: Display()
{
    Node *p = top;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


int main()
{
    Stack st;
    st.push(21);
    st.push(44);
    st.push(9);

    st.Display();
    cout << st.pop() << endl;
    st.Display();

    
}