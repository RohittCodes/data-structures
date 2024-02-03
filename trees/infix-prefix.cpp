#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // For simplicity, consider other operators to have lower precedence
}

// Function to reverse a string
string reverseString(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            // Operand: append to the postfix expression
            postfix += ch;
        } else if (ch == '(') {
            // Left parenthesis: push onto the stack
            operators.push(ch);
        } else if (ch == ')') {
            // Right parenthesis: pop and append operators until a left parenthesis is encountered
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else if (isOperator(ch)) {
            // Operator: pop and append operators with higher or equal precedence
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Pop any remaining operators
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to convert infix expression to prefix expression
string infixToPrefix(const string& infix) {
    string reversedInfix = reverseString(infix);
    string postfix = infixToPostfix(reversedInfix);
    return reverseString(postfix);
}

int main() {
    string infixExpression = "3 + 5 * (2 - 8) / 4";
    string prefixExpression = infixToPrefix(infixExpression);

    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Prefix Expression: " << prefixExpression << endl;

    return 0;
}
