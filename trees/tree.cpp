#include <iostream>
using namespace std;

class BinaryTree
{
public:
    int a[20];
    int top;

    BinaryTree(int root)
    {
        a[0] = root;
        top = 0;
    }

    void setLeft(int rootIndex, int element)
    {
        a[(rootIndex * 2) + 1] = element;
        top += 1;
    }

    void setRight(int rootIndex, int element)
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
        for (int i = 0; i < 7; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    // Helper function to maintain the Max Heap property
    void heapifyUpMaxHeap(int index)
    {
        while (index > 0)
        {
            int parentIndex = getParentIndex(index);
            if (a[index] <= a[parentIndex])
            {
                break; // Max Heap property is satisfied
            }

            // Swap the current element with its parent
            swap(a[index], a[parentIndex]);
            index = parentIndex; // Move up to the parent index
        }
    }

    // Helper function to maintain the Min Heap property
    void heapifyUpMinHeap(int index)
    {
        while (index > 0)
        {
            int parentIndex = getParentIndex(index);
            if (a[index] >= a[parentIndex])
            {
                break; // Min Heap property is satisfied
            }

            // Swap the current element with its parent
            swap(a[index], a[parentIndex]);
            index = parentIndex; // Move up to the parent index
        }
    }

    // Insert an element into the binary tree and maintain the Max Heap property
    void insertMaxHeap(int element)
    {
        int index = top + 1;
        a[index] = element;
        top += 1;
        heapifyUpMaxHeap(index);
    }

    // Insert an element into the binary tree and maintain the Min Heap property
    void insertMinHeap(int element)
    {
        int index = top + 1;
        a[index] = element;
        top += 1;
        heapifyUpMinHeap(index);
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
        if (leftChild <= maxHeapTree->top && maxHeapTree->a[leftChild] > maxHeapTree->a[index])
        {
            largerChild = leftChild;
        }
        else
        {
            largerChild = index;
        }

        if (rightChild <= maxHeapTree->top && maxHeapTree->a[rightChild] > maxHeapTree->a[largerChild])
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

int main()
{
    BinaryTree *maxHeapTree = new BinaryTree(45);
    maxHeapTree->insertMaxHeap(34);
    maxHeapTree->insertMaxHeap(40);
    maxHeapTree->insertMaxHeap(23);
    maxHeapTree->insertMaxHeap(16);
    maxHeapTree->insertMaxHeap(22);
    maxHeapTree->insertMaxHeap(30);

    cout << "Max Heap: ";
    maxHeapTree->printTree();

    BinaryTree *minHeapTree = new BinaryTree(45);
    minHeapTree->insertMinHeap(34);
    minHeapTree->insertMinHeap(40);
    minHeapTree->insertMinHeap(23);
    minHeapTree->insertMinHeap(16);
    minHeapTree->insertMinHeap(22);
    minHeapTree->insertMinHeap(30);

    cout << "Min Heap: ";
    minHeapTree->printTree();

    cout << "Size of Max Heap: " << maxHeapTree->size() << endl;
    cout << "Parent Index for index 3 in Max Heap: " << maxHeapTree->getParentIndex(3) << endl;

    cout << "Size of Min Heap: " << minHeapTree->size() << endl;
    cout << "Parent Index for index 3 in Min Heap: " << minHeapTree->getParentIndex(3) << endl;

    cout << "Max Heap before deletion: ";
    maxHeapTree->printTree();

    int indexToDelete = 2; // Example index to delete
    // Delete an element at a specific index from the Max Heap
    maxHeapTree->deleteAtIndexFromMaxHeap(maxHeapTree, 2);

    cout << "Max Heap after deletion at index " << indexToDelete << ": ";
    maxHeapTree->printTree();

    return 0;
}