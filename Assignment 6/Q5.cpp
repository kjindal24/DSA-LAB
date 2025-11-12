#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

class LinkedList {
public:
    Node* head = nullptr;

    void insert(int value) {
        Node* n = new Node(value);
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
    }

    // Make the list circular by connecting last node to head
    void makeCircular() {
        if (!head) return;
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = head;
    }

    bool isCircular() {
        if (!head) return false;
        Node* temp = head->next;
        while (temp && temp != head)
            temp = temp->next;
        return temp == head;
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Initially:\n";
    cout << (list.isCircular() ? "Circular Linked List\n" : "Not Circular\n");

    list.makeCircular();  // converting to circular

    cout << "\nAfter making circular:\n";
    cout << (list.isCircular() ? "Circular Linked List\n" : "Not Circular\n");

    return 0;
}
#include <iostream>
using namespace std;
class{

	  };

int main() {
   
    return 0;
}


