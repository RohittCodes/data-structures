#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int num){
            this->data = num;
            this->next = NULL;
        }
};

class LinkedList{
    public:
            // pointing the head pointer towards NULL
        Node* head;

        LinkedList(){
            head = NULL;
        }

        void insertNode(int data){
            // Creating a new node
            Node* newNode = new Node(data);

            // pointing the head pointer towards the newly created node if the head was NULL initially
            if(head==NULL){
                head = newNode;
                return;
            }

            // Traverse till the end to know if the node is the last node, so that we could replace the next pointer for the previous from NULL to this node
            
            // using a temp node to move to the current first node and then use an iterator to move forward until next==NULL
            Node* temp = head;
            while(temp->next!=NULL){
                // Initialize temp to the next node by pointing the next pointer of the current node in the iteration which is actually not null
                temp = temp->next;
            }

            // While we reach a node whose next pointer is NULL we initialize the next from NULL to our new node
            temp->next = newNode;
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
};

int main(){
    LinkedList* link = new LinkedList();
    link->insertNode(4);
    link->insertNode(7);
    link->insertNode(3);
    link->insertNode(6);
    link->display();
    cout<<"Deleted: "<<link->deleteNode(3)<<endl;
    link->display();
    return 0;
}