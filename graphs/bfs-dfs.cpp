#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    int weight;
    Node *next;

    Node(int data, int weight)
    {
        this->data = data;
        this->weight = weight;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }

    void insertNode(int data, int weight)
    {
        Node *newNode = new Node(data, weight);
        newNode->next = head;
        head = newNode;
    }
};

class Graph
{
public:
    int size;
    vector<LinkedList> adjacencyList;

    Graph(int size)
    {
        this->size = size;
        adjacencyList.resize(size);
    }

    void insertEdge(int src, int dest, int weight)
    {
        adjacencyList[src].insertNode(dest, weight);
        adjacencyList[dest].insertNode(src, weight);
    }

    void BFS(int startNode)
    {
        vector<bool> visited(size, false);
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            cout << current << " ";

            Node *neighbor = adjacencyList[current].head;
            while (neighbor != nullptr)
            {
                if (!visited[neighbor->data])
                {
                    visited[neighbor->data] = true;
                    q.push(neighbor->data);
                }
                neighbor = neighbor->next;
            }
        }
        cout << endl;
    }

    void DFS(int startNode)
    {
        vector<bool> visited(size, false);
        stack<int> s;

        s.push(startNode);

        while (!s.empty())
        {
            int current = s.top();
            s.pop();

            if (!visited[current])
            {
                visited[current] = true;
                cout << current << " ";
            }

            Node *neighbor = adjacencyList[current].head;
            while (neighbor != nullptr)
            {
                if (!visited[neighbor->data])
                {
                    s.push(neighbor->data);
                }
                neighbor = neighbor->next;
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph g(5);

    g.insertEdge(0, 1, 3);
    g.insertEdge(0, 3, 5);
    g.insertEdge(0, 2, 2);
    g.insertEdge(2, 3, 1);
    g.insertEdge(2, 4, 4);

    cout << "BFS traversal starting from node 0: ";
    g.BFS(0);

    cout << "DFS traversal starting from node 0: ";
    g.DFS(0);

    return 0;
}
