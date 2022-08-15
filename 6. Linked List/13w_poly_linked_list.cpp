#include<iostream>
using namespace std;

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;

void create()
{
    struct Node *t, *last = NULL;
    int num, i;

    cout << "Enter the number of terms";
    cin>> num;

    cout << "Enter each term with coefficient and exponential\n";
    for(i=0; i<num; i++)
    {
            
            t = new Node;
            cin >> t->coeff >> t->exp;
            t->next = NULL;

            if(poly == NULL)
            {
                poly = last = t;
            }
            else
            {
                last->next = t;
                last = t;
            }
    }
}

void display(struct Node *p)
{
    while(p)
    {
        cout << p->coeff <<"x^" << p->exp << " ";
        p = p->next;
    }
    cout << "\n";

}

int main()
{
    create();
    display(poly);

}