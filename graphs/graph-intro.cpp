#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
    int a[5][5];
    int size;

    Graph(int size)
    {
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                a[i][j] = 0;
            }
        }
    }

    void insertEdge(int startPoint, int endPoint)
    {
        a[startPoint][endPoint] = 1;
        a[endPoint][startPoint] = 1;
    }

    vector<int> getAdjancentNodes(int Node)
    {
        vector<int> adjNodes;

        for (int i = 0; i < this->size; i++)
        {
            if (a[Node][i] == 1)
            {
                adjNodes.push_back(i);
            }
        }
        return adjNodes;
    }

    void printMatrix()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    //create an adjacent matrix to store the data to decrease the space complexity
};

int main(int argc, char const *argv[])
{
    Graph g(5);
    g.insertEdge(0, 1);
    g.insertEdge(0, 3);
    g.insertEdge(0, 2);
    g.insertEdge(2, 3);
    g.insertEdge(2, 4);
    g.printMatrix();
    vector<int> an = g.getAdjancentNodes(2);
    for (int i = 0; i < an.size(); i++)
    {
        cout << " " << an[i];
    }
    return 0;
}