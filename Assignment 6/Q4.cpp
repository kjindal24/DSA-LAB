#include <bits/stdc++.h>
using namespace std;

struct Node {
    char value;
    Node* prev;
    Node* next;
    Node(char v) : value(v), prev(nullptr), next(nullptr) {}
};

class DoublyList {
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    void pushBack(char c) {
        Node* n = new Node(c);
        if (!head) {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    bool isPalindrome() const {
        if (!head) return true;
        Node* l = head;
        Node* r = tail;
        while (l != r && l->prev != r) {
            if (l->value != r->value) return false;
            l = l->next;
            r = r->prev;
        }
        return true;
    }

    string toString() const {
        if (!head) return "";
        string s;
        Node* cur = head;
        while (cur) {
            s.push_back(cur->value);
            cur = cur->next;
        }
        return s;
    }

    ~DoublyList() {
        Node* cur = head;
        while (cur) {
            Node* nx = cur->next;
            delete cur;
            cur = nx;
        }
        head = tail = nullptr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter a string (characters only) to check palindrome: ";
    string input;
    if (!getline(cin, input)) return 0;

    DoublyList dl;
    for (char ch : input) {
        if (ch != ' ') dl.pushBack(ch); // skip spaces so phrases like "nurses run" can be tested if desired
    }

    cout << "Doubly linked list contents: " << dl.toString() << '\n';
    cout << (dl.isPalindrome() ? "Palindrome\n" : "Not a palindrome\n");
    return 0;
}

