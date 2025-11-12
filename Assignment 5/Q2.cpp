#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

class List {
    Node* head = nullptr;
public:
    void pushBack(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }

    pair<int, int> countAndDeleteAll(int key) {
        int count = 0;
        while (head && head->data == key) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            ++count;
        }
        Node* cur = head;
        while (cur && cur->next) {
            if (cur->next->data == key) {
                Node* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
                ++count;
            } else {
                cur = cur->next;
            }
        }
        return {count, (head ? 1 : 0)};
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

    ~List() {
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

    List list;
    vector<int> values = {1,2,1,2,1,3,1};
    for (int v : values) list.pushBack(v);

    cout << "Original Linked List: " << list.toString() << '\n';
    int key = 1;
    auto [count, nonEmpty] = list.countAndDeleteAll(key);
    cout << "Count: " << count << '\n';
    cout << "Updated Linked List: " << list.toString() << '\n';
    return 0;
}
#include <iostream>
using namespace std;
class{

	  };

int main() {
   
    return 0;
}


