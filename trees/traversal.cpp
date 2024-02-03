#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Function to insert a value into the BST
    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }

        return root;
    }

    // Function for Inorder Traversal
    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    // Function for Preorder Traversal
    void preorderTraversal(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    // Function for Postorder Traversal
    void postorderTraversal(Node* root) {
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->data << " ";
        }
    }

    // Function to insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }
};

int main() {
    BST bst;

    // Inserting elements into the BST
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);

    cout << "Inorder Traversal: ";
    bst.inorderTraversal(bst.root);
    cout << endl;

    cout << "Preorder Traversal: ";
    bst.preorderTraversal(bst.root);
    cout << endl;

    cout << "Postorder Traversal: ";
    bst.postorderTraversal(bst.root);
    cout << endl;

    return 0;
}
