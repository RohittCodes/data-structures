#include <iostream>
using namespace std;
class Task
{
public:
    string desc;
    int pTask;
    Task(string desc, int pTask)
    {
        this->desc = desc;
        this->pTask = pTask;
    }
};
class BinaryTree
{
public:
    Task *a[20];
    int top;
    BinaryTree(Task *root)
    {
        a[0] = root;
        top = 0;
    }
    void setLeft(int rootIndex, Task *element)
    {
        a[(rootIndex * 2) + 1] = element;
        top += 1;
    }
    void setRight(int rootIndex, Task *element)
    {
        a[(rootIndex * 2) + 2] = element;
        top += 1;
    }
    int size()
    {
        return top + 1;
    }
    int getParentIndex(int childIndex)
    {
        return (childIndex - 1) / 2;
    }
    void printTree()
    {
        for (int i = 0; i < 6; i++)
        {
            cout << a[i]->desc << "-->" << a[i]->pTask << endl;
        }
    }

    void insert(Task *element)
    {
        top++;
        int index = top;
        a[index] = element;
        int pi = getParentIndex(index);
        while (index > 0)
        {
            int pi = getParentIndex(index);
            if (a[pi]->pTask < a[index]->pTask)
            {
                swap(a[pi],a[index]);
                index = pi;
            }
            else{
                break;
            }
        }
    }
    void swap(Task *&a, Task *&b)
    {
        Task *temp = a;
        a = b;
        b = temp;
    }
    void deleteAtIndexFromMaxHeap(BinaryTree *maxHeapTree, int indexToDelete)
{
    if (indexToDelete < 0 || indexToDelete > maxHeapTree->top)
    {
        cout << "Invalid index to delete." << endl;
        return;
    }

    // Replace the element at the given index with the last element
    maxHeapTree->a[indexToDelete] = maxHeapTree->a[maxHeapTree->top];
    maxHeapTree->top -= 1;

    // Perform heapify to restore the Max Heap property
    int index = indexToDelete;
    int leftChild, rightChild, largerChild;

    while (true)
    {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;

        // Find the larger child
        if (leftChild <= maxHeapTree->top && maxHeapTree->a[leftChild]->pTask > maxHeapTree->a[index]->pTask)
        {
            largerChild = leftChild;
        }
        else
        {
            largerChild = index;
        }

        if (rightChild <= maxHeapTree->top && maxHeapTree->a[rightChild]->pTask > maxHeapTree->a[largerChild]->pTask)
        {
            largerChild = rightChild;
        }

        // If the larger child is the current index, break
        if (largerChild == index)
        {
            break;
        }

        // Swap the current element with the larger child
        swap(maxHeapTree->a[index], maxHeapTree->a[largerChild]);
        index = largerChild;
    }
}
};

int main(int argc, char const *argv[])
{
    Task *t1 = new Task("Go to market", 8);
    Task *t2 = new Task("Do laundry", 2);
    Task *t3 = new Task("Do cpp", 1);
    Task *t4 = new Task("Mfcs", 10);
    Task *t5 = new Task("Linked lIst ", 9);
    Task *t6 = new Task("satc lIst ", 4);
    BinaryTree *b = new BinaryTree(t4);
    b->setLeft(0, t1);
    b->setRight(0, t5);
    b->insert(t2);
    b->insert(t3);
    b->insert(t6);
    b->printTree();
    cout<<"*****************";
    b->deleteAtIndexFromMaxHeap(b, 3);
    b->printTree();

    return 0;
}