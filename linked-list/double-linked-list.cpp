#include <iostream>
using namespace std;

class Node{
    public:
    // properties
    int data;
    Node* next;
    Node* prev;

    // behaviour
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    Node* tail;
    LinkedList(){
        head=NULL;
        tail=NULL;
    }

    void insertNode(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=newNode;
            newNode->prev=NULL;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
        }
    }

    void display(){
        Node* temp = head;
        while(temp->next!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data;
        cout<<endl;
    }

    int deleteNode(int pos){
        // It's having a bug index 0 deletes the whole list
        Node* temp = head;
        int count = 1;
        while(count<pos && temp != NULL){
            temp = temp->next;
            count++;
        }
        Node* temp1 = temp->prev;
        Node* temp2 = temp->next;
        temp1->next = temp2;
        temp2->prev = temp1;
        int deletedNode = temp->data;
        delete temp;
        return deletedNode;
    }
};

int main(){
    LinkedList* list = new LinkedList();
    list->insertNode(20);
    list->insertNode(40);
    list->insertNode(60);
    list->insertNode(80);
    list->display();
    cout<<list->deleteNode(2)<<endl;
    list->display();
    return 0;
}