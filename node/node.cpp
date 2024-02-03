#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;

    LinkedList(){
        head=NULL;
    }

    void insertNode(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = newNode;
            cout<<"Node inserted!!"<<newNode->data<<endl;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
            cout<<"Node inserted!!"<<newNode->data<<endl;
    }

    int deleteNode(int index){
        Node* temp = head;
        if(head==NULL){
            cout<<"List is still empty!!";
            return 0;
        }
        int count = 1;
        while(count!=index){
            temp=temp->next;
            count++;
        }
        Node* temp1 = temp->next;
        temp->next = temp1->next;
        int deletedValue = temp1->data;
        delete temp1;
        return deletedValue;
    }

    void display(){
        Node* temp = head;

        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList* list = new LinkedList();
    list->insertNode(20);
    list->insertNode(39);
    list->display();
    list->insertNode(40);
    list->insertNode(42);
    list->deleteNode(2);
    list->display();
    return 0;
}