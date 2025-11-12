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

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << '\n';   // repeat head at end
    }
};

int main() {
    CircularList list;
    list.insert(20);
    list.insert(100);
    list.insert(40);
    list.insert(80);
    list.insert(60);

    cout << "Circular Linked List values:\n";
    list.display();
    return 0;
}
#include <iostream>
using namespace std;
class{

	  };

int main() {
   
    return 0;
}


