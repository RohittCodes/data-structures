#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

// Node structure for the linked list
struct Node {
    char data;
    Node* next;

    Node(char value) : data(value), next(nullptr) {}
};

class ExpressionList {
public:
    Node* head;

    ExpressionList() : head(nullptr) {}

    // Function to append a node to the linked list
    void appendNode(char value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
};

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // For simplicity, consider other operators to have lower precedence
}

// Function to convert infix expression to postfix using a linked list
ExpressionList infixToPostfix(const string& infix) {
    ExpressionList postfixExpression;
    stack<char> operators;

    istringstream iss(infix);
    char token;
    while (iss >> token) {
        if (isalnum(token)) {
            postfixExpression.appendNode(token);
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfixExpression.appendNode(operators.top());
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                postfixExpression.appendNode(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        postfixExpression.appendNode(operators.top());
        operators.pop();
    }

    return postfixExpression;
}

int main() {
    string infixExpression = "3 + 5 * (2 - 8) / 4";
    ExpressionList postfixExpression = infixToPostfix(infixExpression);

    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Postfix Expression: ";
    Node* current = postfixExpression.head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
