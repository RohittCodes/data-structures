#include <iostream>
#include <stack>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert postfix expression to prefix expression
string postfixToPrefix(const string& postfix) {
    stack<string> operands;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            // Operand: push onto the stack
            operands.push(string(1, ch));
        } else if (isOperator(ch)) {
            // Operator: pop operands, concatenate with operator, and push the result back
            string operand2 = operands.top();
            operands.pop();
            string operand1 = operands.top();
            operands.pop();

            string result = ch + operand1 + operand2;
            operands.push(result);
        }
    }

    return operands.top();
}

int main() {
    string postfixExpression = "35*2-8/4+";
    string prefixExpression = postfixToPrefix(postfixExpression);

    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Prefix Expression: " << prefixExpression << endl;

    return 0;
}
