#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};

int evaluatePostfix(string postfix) {
    Stack s;
    for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');  // convert char to int
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string expr;
    cout << "Enter postfix expression: ";
    cin >> expr;

    cout << "Result: " << evaluatePostfix(expr) << endl;
    return 0;
}

