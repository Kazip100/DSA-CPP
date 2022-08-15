#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
} *top = NULL;

// if there is one stack in my program then having a global top is a good choice

void push(char x)
{
    struct Node *t;
    t = new Node;

    if (t == NULL)
        cout << "Stack is Full\n";
    else
        t->data = x;
    t->next = top;
    top = t;
}

char pop()
{
    struct Node *t;
    char x = -1;

    if (top == NULL)
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
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

// code to check the balanced used of parenthesis (), {}, []
int isBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '[' || exp[i] == '(' || exp[i] == '{')
            push(exp[i]);
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if ((exp[i] == ']' && top->data == '[') || (exp[i] == ')' && top->data == '(') || (exp[i] == '}' && top->data == '{') )
                pop();
            else
                return 0;
        }
    }
    
    if (top == NULL)
        return 1;
    return 0;
}

int main()
{
    char *exp = "((a+b)*((c-d)";
    cout << isBalanced(exp);
    // output 1 means that the stack equation is balanced and is empty
    // output 0 means that the stack equation is not balanced
}