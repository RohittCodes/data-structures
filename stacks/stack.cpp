#include <iostream>
#include <stack>
using namespace std;

// stack using stl Standard template library

int main(){
    // stack creation
    stack<int> s;

    // push operation
    s.push(2);
    s.push(4);

    // pop operation
    s.pop();

    s.push(5);

    // Check if stack is empty
    if(s.empty()){
        cout<<"stack is empty \n";
    }
    else{
        // Print top element
        cout<<"Top element is: "<<s.top()<<endl;
        // Print size of stack
        cout<<"The size of the stack: "<<s.size()<<endl;
    }

    return 0;
}