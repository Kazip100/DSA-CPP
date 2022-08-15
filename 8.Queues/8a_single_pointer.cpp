#include<iostream>
using namespace std;

struct Queue
{
    int size;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->rear = -1;
    q->Q = new int;

}

void enqueue(struct Queue *q, int x)
{
    if(q->rear == q->size -1)
        cout << "Queue is Full";
    else
    {
        q->rear++;
        q->Q[q->rear] = x;

    }
}

int dequeue(struct Queue *q)
{
    int x = -1, i;
    if(q->rear == -1)
        cout << "Queue is Empty\n";
    else
    {
        for(i=0; i<q->Q[q->rear]; i++)
        {
            q->Q[i-1] = q->Q[i];
        }
        q->rear--;
        x = q->Q[-1];
    }
    return x;
}

void Display(struct Queue q)
{
    int i;
    for(i=0; i<=q.rear; i++)
        cout << q.Q[i] << " ";
    cout << "\n";
}

int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 15);
    enqueue(&q, 65);
    Display(q);
    cout << dequeue(&q) << endl;
    Display(q);
}