#include <iostream>
using namespace std;

class Stack{
    // properties
    public:
    int top=-1;
    int size;
    int* arr;

    // Behaviour
    Stack(int size){
        top=-1;
        this->size=size;
        arr = new int[size];
    }

    void push(int data){
        if(top==size){
            cout<<"Stack is full. Pop an element to push\n";
            return;
        }

        top++;
        arr[top]=data;
        cout<<"Pushed the element: "<<data<<" at index "<<top;
        cout<<endl;
    }

    int peek(){
        if(top==-1){
            cout<<"Stack is empty. Push an element to see the top element\n";
            return -1;
        }

        return arr[top];
    }

    int pop(){

        // Check if it's empty or not
        if(top==-1){
            cout<<"Stack is empty. Push an element to pop\n";
            return -1;
        }

        int deletedNum = arr[top];
        top--;
        return deletedNum;
    }

    void display(){
        for(int i=0; i<=top; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    bool isEmpty(){
        if(top>=0){
            return false;
        }
        else{
            return true;
        }
    }
};

int main(){
    Stack* st = new Stack(5);
    cout<<st->isEmpty()<<endl;
    st->push(45);
    st->push(18);
    cout<<"Deleted the element: "<<st->pop()<<endl;
    cout<<"Element at top is: "<<st->peek()<<endl;
    st->push(7);
    st->push(17);
    cout<<st->isEmpty()<<endl;
    cout<<"Element at top is: "<<st->peek()<<endl;
    st->display();
    cout<<"Deleted the element: "<<st->pop()<<endl;
    st->display();
    return 0;
}