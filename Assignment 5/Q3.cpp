#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

class LinkedList {
    Node* head = nullptr;
public:
    void pushBack(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }

    int findMiddle() {
        if (!head) throw runtime_error("Empty list");
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    string toString() const {
        if (!head) return "Empty";
        stringstream ss;
        Node* cur = head;
        while (cur) {
            ss << cur->data;
            if (cur->next) ss << "->";
            cur = cur->next;
        }
        return ss.str();
    }

    ~LinkedList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedList list;
    vector<int> values = {1,2,3,4,5};
    for (int v : values) list.pushBack(v);

    cout << "Input: " << list.toString() << '\n';
    cout << "Middle: " << list.findMiddle() << '\n';
    return 0;
}
#include <iostream>
using namespace std;
class{

	  };

int main() {
   
    return 0;
}


