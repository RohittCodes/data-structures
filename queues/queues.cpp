#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Queue
{
public:
    Node *front = NULL;
    Node *rear = NULL;

    void enqueue(int data)
    {
        Node *nn = new Node(data);
        if (front == NULL)
        {
            front = nn;
            rear = nn;
        }
        rear->next = nn;
        rear = nn;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "queue is empty:)" << endl;
            return;
        }
        Node *temp = front;
        front = temp->next;
        delete temp;
    }
    void get_front()
    {
        if (front == NULL)
        {
            cout << "quque is empty:)" << endl;
            return;
        }
        cout << "front element is " << front->data << endl;
    }
    void get_rear()
    {
        if (rear == NULL)
        {
            cout << "queue is empty:)" << endl;
        }
        cout << "rear element is " << rear->data << endl;
    }
};

int main()
{
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(10);
    q1.enqueue(15);
    q1.get_front();
    q1.get_rear();
}