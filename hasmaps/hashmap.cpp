#include <iostream>
#include <vector>

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Insert at the beginning of the linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Search for a value in the linked list
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Remove a value from the linked list
    void remove(int value) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            return; // Value not found
        }

        if (prev == nullptr) {
            head = current->next; // Remove the first node
        } else {
            prev->next = current->next; // Remove from the middle or end
        }

        delete current;
    }
};

// Hash table using linked list
class HashTable {
private:
    static const int tableSize = 10;
    std::vector<LinkedList> table;

    // Hash function to determine the index in the array
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTable() : table(tableSize) {}

    // Insert a value into the hash table
    void insert(int value) {
        int index = hashFunction(value);
        table[index].insert(value);
    }

    // Search for a value in the hash table
    bool search(int value) {
        int index = hashFunction(value);
        return table[index].search(value);
    }

    // Remove a value from the hash table
    void remove(int value) {
        int index = hashFunction(value);
        table[index].remove(value);
    }
};

int main() {
    HashTable hashTable;

    // Insert values into the hash table
    hashTable.insert(42);
    hashTable.insert(23);
    hashTable.insert(8);

    // Search for values
    std::cout << "Is 23 in the hash table? " << (hashTable.search(23) ? "Yes" : "No") << std::endl;
    std::cout << "Is 15 in the hash table? " << (hashTable.search(15) ? "Yes" : "No") << std::endl;

    // Remove a value
    hashTable.remove(23);

    // Search again after removal
    std::cout << "Is 23 in the hash table? " << (hashTable.search(23) ? "Yes" : "No") << std::endl;

    return 0;
}
