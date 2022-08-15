#include <iostream>
#include <cstring>

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

    if (t == NULL)
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

int isOperand(char x)       //checking operand
{
    if(x == '+' || x == '-' || x == '/' || x == '*')
        return 0;
    else
        return 1;           // if it is not an operator then it is an operand

}

int Eval(char *postfix)
{
    int i=0;
    int x1, x2, r;
    for(i=0; postfix[i]!='\0'; i++)
    {
        if(isOperand ( postfix[i] ) )
        {
            push(postfix[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch(postfix[i])
            {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    char *postfix = "234*+82/-";
    cout << "Result is: " << Eval(postfix);
    return 0;

}