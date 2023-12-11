#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Node structure for the linked list
struct Node {
    char data;
    Node* next;

    Node(char value) : data(value), next(nullptr) {}
};

// Stack ADT using a singly linked list
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cerr << "Error: Stack underflow" << endl;
            return '\0'; // Assuming '\0' is not a valid character in the expression
        }

        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

        return value;
    }

    char peek() const {
        if (isEmpty()) {
            cerr << "Error: Stack is empty" << endl;
            return '\0'; // Assuming '\0' is not a valid character in the expression
        }

        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

// Function to check if a character is an operand (alphabetical character or digit)
bool isOperand(char ch) {
    return (isalpha(ch) || isdigit(ch));
}

// Function to check the precedence of an operator
int precedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return -1;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    Stack stack;
    string postfix;

    for (char ch : infix) {
        if (isOperand(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Pop the '(' from the stack
        } else { // Operator
            while (!stack.isEmpty() && precedence(ch) <= precedence(stack.peek())) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }

    // Pop any remaining operators from the stack
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

// Function to convert infix expression to prefix expression
string infixToPrefix(const string& infix) {
    // Reverse the infix expression, swap '(' with ')' and vice versa
    string reversedInfix;
    for (char ch : infix) {
        if (ch == '(') reversedInfix += ')';
        else if (ch == ')') reversedInfix += '(';
        else reversedInfix += ch;
    }

    // Get the postfix expression of the reversed infix
    string reversedPostfix = infixToPostfix(reversedInfix);

    // Reverse the postfix expression to get the prefix expression
    string prefix(reversedPostfix.rbegin(), reversedPostfix.rend());

    return prefix;
}

int main() {
    string infixExpression;

    // Get the infix expression from the user
    cout << "Enter infix expression: ";
    getline(cin, infixExpression);

    // Convert infix to postfix and prefix
    string postfix = infixToPostfix(infixExpression);
    string prefix = infixToPrefix(infixExpression);

    // Display the results
    cout << "Postfix expression: " << postfix << endl;
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
