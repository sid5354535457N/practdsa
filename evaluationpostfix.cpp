#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
public:
    Node* top;

    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cerr << "Error: Pop from an empty stack.\n";
            exit(1);
        }

        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

        return data;
    }

    int peek() {
        if (isEmpty()) {
            cerr << "Error: Peek from an empty stack.\n";
            exit(1);
        }

        return top->data;
    }
};

int evaluatePostfix(const string& expression) {
    Stack stack;
    for (char c : expression) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            switch (c) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                default:
                    cerr << "Error: Invalid postfix expression.\n";
                    exit(1);
            }
        }
    }
    return stack.pop();
}

int evaluatePrefix(const string& expression) {
    Stack stack;
    for (int i = expression.size() - 1; i >= 0; --i) {
        char c = expression[i];
        if (isdigit(c)) {
            stack.push(c - '0');
        } else {
            int operand1 = stack.pop();
            int operand2 = stack.pop();
            switch (c) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                default:
                    cerr << "Error: Invalid prefix expression.\n";
                    exit(1);
            }
        }
    }
    return stack.pop();
}

int main() {
    // Example usage:
    string postfixExpression = "23*5+";
    int resultPostfix = evaluatePostfix(postfixExpression);
    cout << "Result of postfix expression '" << postfixExpression << "' is: " << resultPostfix << "\n";

    string prefixExpression = "+*235";
    int resultPrefix = evaluatePrefix(prefixExpression);
    cout << "Result of prefix expression '" << prefixExpression << "' is: " << resultPrefix << "\n";

    return 0;
}
