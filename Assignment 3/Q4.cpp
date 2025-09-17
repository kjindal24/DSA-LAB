#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    void push(char c) { arr[++top] = c; }
    char pop() { return (isEmpty()) ? '\0' : arr[top--]; }
    char peek() { return (isEmpty()) ? '\0' : arr[top]; }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // remove '('
        } else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty())
        postfix += s.pop();

    return postfix;
}

int main() {
    string expr;
    cout << "Enter infix expression: ";
    cin >> expr;

    cout << "Postfix: " << infixToPostfix(expr) << endl;
    return 0;
}

