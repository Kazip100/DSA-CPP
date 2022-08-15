#include<iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;

};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;             // for circular queue, initial must be at 0
    q->Q = new int;
}

void enqueue(struct Queue *q, int x)
{
    if( (q->rear+1)%q->size == q->front )
        cout << "Queue is Full" << endl;
    else
    {
        q->rear = (q->rear+1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if(q->front == q->rear)
        cout << "Queue is Empty\n";
        
    else
    {
        q->front = (q->front+1) % q->size;
        x = q->Q[q->front];

    }
    return x;
}

void Display(struct Queue q)
{
    int i = q.front+1;
    do
    {
        cout << q.Q[i] << " ";
        i = (i+1) % q.size;

    }while(i != (q.rear+1) % q.size );
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
    
    enqueue(&q, 16);
    enqueue(&q, 60);
    Display(q);
    cout << dequeue(&q) << endl;
    Display(q);
    enqueue(&q, 61);
    Display(q);
    cout << dequeue(&q) << endl;
    Display(q);
    enqueue(&q, 6);
    Display(q);

}