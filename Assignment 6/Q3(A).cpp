#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

class CircularList {
    Node* head = nullptr;

public:
    void insert(int value) {
        Node* n = new Node(value);
        if (!head) {
            head = n;
            n->next = n;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    int size() {
        if (!head) return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};

int main() {
    CircularList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Size of Circular Linked List: " << list.size() << endl;
    return 0;
}

