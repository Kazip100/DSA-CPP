#include<iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    cout << "Enter the size of the stack: ";
    cin >> st->size;
    st->top = -1;
    st->S = new int;    
}

void Display(struct Stack st)
{
    int i;
    for(i=st.top; i>=0; i--)
    {
        cout << st.S[i] << " ";
    }
    cout << "\n";
}

void push(struct Stack *st, int x)
{
    if(st->top == st->size-1)               // condition for full stack
        cout << "Stack Overflow";
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;

    if(st->top == -1)                       // condition for empty stack
        cout << "Stack Underflow ";
    else
    {
        x = st->S[st->top--];
    }
    return x;
}


int peek(struct Stack st, int index)
{
    int x =-1;
    if(st.top-index+1 < 0)
        cout << "Invalid index";
    x = st.S[st.top-index+1];

    return x;
}

int isEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack st)
{
    if(st.top == st.size-1)
        return 1;
    return 0;
}

int stackTop(struct Stack st)
{
    if( !isEmpty(st) )
        return st.S[st.top];
    return -1;
}

int main()
{
    struct Stack st;
    create(&st);                    // will create desired size of array e.g. 5
    push(&st, 10);
    push(&st, 21);
    push(&st, 38);
    push(&st, 70);
    push(&st, 18);

    cout << "\nValue at index 2 is: "<< peek(st, 2);

    cout << "\n\n";
    push(&st, 56);                  // since we have inputed 5 initial values but coded about 6 datas therefore the program will give show stack overflow 
    cout << "\n\n";
    Display(st);                    // the object that is added last is displayed first

    cout << pop(&st) << endl;       // LIFO
    cout << pop(&st) << endl;
    cout << pop(&st) << endl;
    cout << pop(&st) << endl;
    cout << pop(&st) << endl;

    cout << pop(&st) << endl;
    cout << pop(&st) << endl;
    cout << pop(&st) << endl;
    Display(st);


    cout << isEmpty(st) << endl;
    cout << isFull(st) << endl;
    cout << stackTop(st) << endl;


    
}