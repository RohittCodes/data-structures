#include <iostream>
using namespace std;

class Node{
    int data;
    node* left;
    node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class Tree{
    Node *root;
    Tree(){
        root = NULL;
    }

    void insert(int val){
        Node* newNode = new Node(val);
        if(root==NULL){
            root = newNode;
            return;
        }

        if(root->left==NULL){
            root->left = newNode;
            return;
        }
        root->right=newNode;
        return;
    }
};

int main(){}