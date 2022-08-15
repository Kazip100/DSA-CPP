#include <iostream>
#include <cstring>

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

int pre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    return 0;
}

int isOperand(char x)       //checking operand
{
    if(x == '+' || x == '-' || x == '/' || x == '*')
        return 0;
    else
        return 1;           // if it is not an operator then it is an operand

}

char *InToPost(char *infix)
{
    int i=0, j=0;
    char *postfix;
    int len = strlen(infix);
    postfix = new char[len+2];

    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))                     // if it is an operand
            postfix[j++] = infix[i++];
        else                                        // if not an opearand then we will upload it on a stack
        {
            if(pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();

            }
        }
        
    }
    while(top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c-d/e";
    push('#');

    char *postfix = InToPost(infix);
    cout << postfix;
    return 0;

}