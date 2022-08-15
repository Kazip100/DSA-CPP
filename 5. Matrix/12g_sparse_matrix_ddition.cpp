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

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele = (struct Element *)malloc((s1->num + s2->num)*sizeof(struct Element));
    
    while(i<s1->num && j<s2->num)
    {
        if(s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if(s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else
        {
            if(s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if(s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            
            else
            {
                sum-> ele[k] = s1->ele[i];
                sum-> ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    for( ; i<s1->num; i++)
        sum->ele[k++] = s1->ele[i];
    for( ; i<s2->num; i++)
        sum->ele[k++] = s2->ele[j];
    
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;
    
    return sum;
}


int main()
{
    struct Sparse s1, s2, *s3;
    create(&s1);
    create(&s2);
    s3 = add(&s1, &s2);
    cout << "\n";
    
    cout << "First Matrix:\n";
    Display(s1);
    cout << "Second Matrix:\n";
    Display(s2);
    cout << "Sum Matrix is:\n";
    Display(*s3);
    
    return 0;
}

