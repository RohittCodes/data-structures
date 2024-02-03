#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

class LinkedList{
    public:
        Node* head;
        Node* tail;
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        void insertAtHead(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                newNode->next=NULL;
                newNode->prev=NULL;
                return;
            }
            Node* temp = head;
            temp->prev = newNode;
            newNode->next = temp;
            newNode->prev = NULL;
            head = newNode;
        }

        void insertAtTail(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                newNode->next=NULL;
                newNode->prev=NULL;
                return;
            }
            Node* temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
        }

        void insertAtPosition(int val, int pos){
            Node* newNode = new Node(val);
            if(head == NULL || pos == 0){
                newNode->next = head;
                newNode->prev = NULL;
                if (head != NULL) {
                    head->prev = newNode;
                }
                head = newNode;
                return;
            }
            Node* temp = head;
            int count = 1;
            while(count!=pos){
                temp = temp->next;
                count++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
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
};

int main(){
    LinkedList* list = new LinkedList();
    list->insertAtHead(10); //10
    list->insertAtPosition(30, 0); //30 10
    list->display();
    list->insertAtTail(20); // 30 10 20
    list->insertAtTail(40); // 30 10 20 40
    list->insertAtHead(50); // 50 30 10 20 40
    list->display();
    return 0;
}