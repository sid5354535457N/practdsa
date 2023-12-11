#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operand (alphabetical character or digit)
bool isOperand(char ch) {
    return isalnum(ch); // isalnum checks if a character is alphanumeric
}

// Function to check the precedence of an operator
int precedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return -1; // For simplicity, return -1 for unknown operators
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> s; // Use the standard C++ stack

    string postfix;
    for (char ch : infix) {
        if (isOperand(ch)) {
            postfix += ch; // Append operand to the result
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop the '(' from the stack
        } else { // Operator
            while (!s.empty() && precedence(ch) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop any remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;

    // Get the infix expression from the user
    cout << "Enter infix expression: ";
    getline(cin, infixExpression);

    // Convert infix to postfix
    string postfix = infixToPostfix(infixExpression);

    // Display the result
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
