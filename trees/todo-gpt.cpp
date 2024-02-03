#include <iostream>
using namespace std;

class Tasks {
public:
    int priority;
    string description;

    Tasks(int pr, string desc) {
        priority = pr;
        description = desc;
    }
};

class BinaryTree {
public:
    Tasks *task[20];
    int top;

    BinaryTree(Tasks *root) {
        task[0] = root;
        top = 0;
    }

    int getParentIndex(int childIndex) {
        return (childIndex - 1) / 2;
    }

    void setLeft(int rootIndex, Tasks *element) {
        task[(rootIndex * 2) + 1] = element;
        top += 1;
    }

    void setRight(int rootIndex, Tasks *element) {
        task[(rootIndex * 2) + 2] = element;
        top += 1;
    }

    int size() {
        return top + 1;
    }

    void printTree() {
        for (int i = 0; i < 7; i++) {
            cout << task[i]->description << " " << task[i]->priority << " " <<endl;
        }
        cout << endl;
    }

    void heapifyUpMaxHeap(int index) {
        while (index > 0) {
            int parentIndex = getParentIndex(index);
            if (task[index]->priority <= task[parentIndex]->priority) {
                break; // Max Heap property is satisfied
            }

            // Swap the current element with its parent
            swap(task[index], task[parentIndex]);
            index = parentIndex; // Move up to the parent index
        }
    }

    void insertMaxHeap(Tasks *element) {
        int index = top + 1;
        task[index] = element;
        top += 1;
        heapifyUpMaxHeap(index);
    }
};

int main() {
    Tasks *t1 = new Tasks(10, "Add two numbers");
    Tasks *t2 = new Tasks(8, "Do nothing");
    Tasks *t3 = new Tasks(4, "Do this thing");
    BinaryTree *binary = new BinaryTree(t1);
    binary->insertMaxHeap(t2);
    binary->insertMaxHeap(t3);
    binary->printTree();
    return 0;
}
