#include<iostream>
using namespace std;

struct Element
{
    int i, j, x;        
};

struct Sparse
{
    int m, n, num;
    struct Element *ele;
    
};

void create(struct Sparse *s)
{
    int i;
    cout << "Enter the dimensions: ";
    cin >> s->m >> s->n;
    cout << "Number of non-zeroes: ";
    cin >> s->num;
    
    s->ele = (struct Element *) malloc(s->num*sizeof(struct Element));
    cout << "Enter non-zeroes elements\n";
    for(i=0; i< s->num; i++)
        cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x;
    
}
void Display(struct Sparse s)
{
    int i,j, k=0;
    for(i=0; i<s.m; i++)
    {
        for(j=0; j<s.n; j++)
        {
            if(i == s.ele[k].i && j == s.ele[k].j )
                cout << s.ele[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}
int main()
{
    struct Sparse s;
    create(&s);
    cout << "\n";
    Display(s);
    return 0;
}
