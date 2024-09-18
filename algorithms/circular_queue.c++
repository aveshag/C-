#include <iostream>
#include <vector>

#define MAX_SIZE 4
using namespace std;

class MyQueue
{
    vector<int> q;
    int rear;
    int front;

public:
    MyQueue()
    {

        q.resize(MAX_SIZE);
        rear = front = 0;
    }

    void enqueue(int ele)
    {
        if ((rear + 1) % MAX_SIZE == front)
        {
            cout << "Q is full" << endl;
            return;
        }

        rear = (rear + 1) % MAX_SIZE;
        q[rear] = ele;
        cout << ele << " is enqueued" << endl;
    }

    void dequeue()
    {
        if (front == rear)
        {
            cout << "Q is empty" << endl;
            return;
        }
        front = (front + 1) % MAX_SIZE;
        cout << q[front] << " is dequeued" << endl;
    }
};

int main()
{
    MyQueue *cq = new MyQueue();
    cq->enqueue(1);
    cq->enqueue(2);
    cq->enqueue(3);
    cq->enqueue(4);
    cq->dequeue();
    cq->enqueue(5);
    cq->enqueue(6);
    cq->dequeue();
    cq->dequeue();
    cq->dequeue();
    cq->dequeue();
    cq->enqueue(7);
    return 0;
}