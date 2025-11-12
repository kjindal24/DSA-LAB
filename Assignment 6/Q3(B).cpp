#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int v) : data(v), prev(nullptr), next(nullptr) {}
};

class DoublyList {
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    void insert(int value) {
        Node* n = new Node(value);
        if (!head) {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyList list;
    list.insert(5);
    list.insert(15);
    list.insert(25);

    cout << "Size of Doubly Linked List: " << list.size() << endl;
    return 0;
}

