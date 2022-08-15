#include<iostream>
#include "9a_Queue.cpp"
using namespace std;

// stores the program to create stack, push and pop elements in a stack
// can also be used to check whether the stack is empty or full

struct Stack
{
    int size;
    int top;
    struct Node **S;    
};

void Stackcreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = new Node*;

}

void push(struct Stack *st, struct Node *x)
{
    if(st->top == st->size-1)
    {
        cout << "Stack Overflow\n";
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;
    if(st->top == -1)
    {
        cout << "Stack Overflow\n";
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;

}

int isEmptyStack(struct Stack st)
{
    if(st.top == -1)
        return -1;
    return 0;
}

int isFullStack(struct Stack st)
{
    return st.top == st.size-1;
}
