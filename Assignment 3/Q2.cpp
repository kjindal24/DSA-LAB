#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(char c) {
        if (isFull()) return;
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) return '\0';
        return arr[top--];
    }
};

string reverseString(string str) {
    Stack s;
    for (char c : str)
        s.push(c);

    string rev = "";
    while (!s.isEmpty())
        rev += s.pop();

    return rev;
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    cout << "Reversed: " << reverseString(str) << endl;
    return 0;
}

