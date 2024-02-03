#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head=NULL;
    }
    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        else{
            Node* temp = head;
            newNode->next = temp;
            head = newNode;
        }
    }

    void insertAtTale(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = newNode;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    void insertAtIndex(int val, int n) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        } else {
            if (n == 0) {
                // Special case for inserting at the beginning
                newNode->next = head;
                head = newNode;
                return;
            }

            Node* temp = head;
            int count = 0;
            while (count < n - 1 && temp->next != NULL) {
                temp = temp->next;
                count++;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    int deleteNode(int n){
            Node* temp = head;
            int count=1;
            if(head==NULL){
                cout<<"Linked list is empty";
                return 0;
            }
            while(count!=n){ // n=2
                temp = temp->next; //0 1 2
                count++;
            }
            Node* temp1 = temp->next;
            temp->next = temp1->next;
            int data = temp1->data;
            delete temp1;
            return data;
        }

    void display(){
            Node* temp = head;
            if(head==NULL){
                cout<<"Linked list is empty"<<endl;
                return;
            }
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp -> next;
            }
            cout<<endl;
        }
};

int main(){
    LinkedList* list = new LinkedList();
    list->insertAtHead(20);
    list->insertAtHead(30);
    list->display();
    list->insertAtTale(40);
    list->insertAtIndex(50, 3);
    cout<<list->deleteNode(1)<<endl;
    list->display();
    return 0;
}