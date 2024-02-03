#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        int data;
        int weight;
        Node *next;
        Node(int data, int weight)
        {
            this->data = data;
            this->next = nullptr;
            this->weight = weight;
        }
};

// A linked list class to insert the nodes for each node of the graph
class LinkedList{
    public:
        Node* head;
        LinkedList(){
            head=NULL;
        }

        void insertNode(int data, int weight){
            Node* newNode = new Node(data, weight);
            newNode->next=head;
            head=newNode;
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

    // function to insert node into the linked list used in the the array declaration
    void insertEdge(int src, int dest, int weight){
        adjacencyList[src].insertNode(dest, weight);
        adjacencyList[dest].insertNode(src, weight);
    }
    // function traverse over the graph we have created now
    void traverseGraph(){
        for(int i=0; i<size; i++){
            cout<<"Adjacent nodes of vertex "<<i<<": ";
            Node* current = adjacencyList[i].head;
            while(current!=NULL){
                cout<<"("<<current->data<<", "<<current->weight<<") ";
                current = current->next;
            }
            cout<<endl;
        }
    }
};

int main()
{
    // Create the graph class with some size
    Graph g(5);

    // Call the insert method here with the edges for individual nodes
    g.insertEdge(0, 1, 3);
    g.insertEdge(0, 3, 5);
    g.insertEdge(0, 2, 2);
    g.insertEdge(2, 3, 1);
    g.insertEdge(2, 4, 4);

    g.traverseGraph();

    // Call the traversal method
    return 0;
}