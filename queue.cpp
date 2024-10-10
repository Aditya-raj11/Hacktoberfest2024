#include <iostream>
using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int *q;
};
void create(struct queue *p, int size)
{
    p->size = size;
    p->front = p->rear = 0;
    p->q = new int[p->size];
}
void enqueue(struct queue *p, int x)
{
    if ((p->rear + 1) % p->size == p->front)
    {
        cout << "queue is full" << endl;
    }
    else
    {
        p->rear = (p->rear + 1) % p->size;
        p->q[p->rear] = x;
    }
}
int dequeue(struct queue *p)
{
    int x = -1;
    if (p->front == p->rear)
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        p->front = (p->front + 1) % p->size;
        x = p->q[p->front];
    }
    return x;
}
void display(struct queue p)
{
    int i = p.front + 1;
    do
    {
        printf("%d ", p.q[i]);
        i = (i + 1) % p.size;
    } while (i != (p.rear + 1) % p.size);

    cout << "\n";
}
int main()
{
    struct queue p;
    create(&p, 5);
    enqueue(&p, 10);
    enqueue(&p, 11);
    enqueue(&p, 12);
    enqueue(&p, 14);
    enqueue(&p, 19);
    
    display(p);
    dequeue(&p);
    enqueue(&p, 20);
    display(p);
    return 0;
}
