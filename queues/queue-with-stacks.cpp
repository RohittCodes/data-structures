#include <iostream>
using namespace std;

// Node Class
class Node
{
public:
    char data;
    Node *next;
};

// Stack Class
class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }

    // check if stack is empty
    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }

    // push item into stack
    void push(int value)
    {
        Node *newNode = new Node;
        if (newNode == NULL)
        {
            cout << "Stack is full\n";
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // pop top item from stack
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        int value = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // peek top item from stack
    char peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        return top->data;
    }
};

class Queue
{
    Stack s1, s2;

public:
    void enqueue(int data)
    {
        while (!s1.isEmpty())
        {
            s2.push(s1.pop());
        }

        if (data)
        {
            s1.push(data);
        }

        while (!s2.isEmpty())
        {
            s1.push(s2.pop());
        }
    }

    int dequeue()
    {
        return s1.pop();
    }
};

int main()
{
    Queue q;
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << q.dequeue() << ' ';
    cout << q.dequeue() << ' ';
    cout << q.dequeue() << ' ';

    return 0;
}