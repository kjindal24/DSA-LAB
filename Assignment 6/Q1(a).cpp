#include <bits/stdc++.h>
using namespace std;

struct CircNode {
    int value;
    CircNode* next;
    CircNode(int v): value(v), next(nullptr) {}
};

class CircularList {
    CircNode* head = nullptr;

public:
    bool isEmpty() const { return head == nullptr; }

    void insertAsFirst(int v) {
        CircNode* n = new CircNode(v);
        if (!head) {
            n->next = n;
            head = n;
            return;
        }
        CircNode* tail = head;
        while (tail->next != head) tail = tail->next;
        n->next = head;
        tail->next = n;
        head = n;
    }

    void insertAsLast(int v) {
        if (!head) { insertAsFirst(v); return; }
        CircNode* n = new CircNode(v);
        CircNode* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = n;
        n->next = head;
    }

    bool insertAfterValue(int target, int v) {
        if (!head) return false;
        CircNode* cur = head;
        do {
            if (cur->value == target) {
                CircNode* n = new CircNode(v);
                n->next = cur->next;
                cur->next = n;
                return true;
            }
            cur = cur->next;
        } while (cur != head);
        return false;
    }

    bool insertBeforeValue(int target, int v) {
        if (!head) return false;
        if (head->value == target) { insertAsFirst(v); return true; }
        CircNode* prev = head;
        CircNode* cur = head->next;
        while (cur != head && cur->value != target) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == head) return false;
        CircNode* n = new CircNode(v);
        prev->next = n;
        n->next = cur;
        return true;
    }

    bool deleteValue(int target) {
        if (!head) return false;
        if (head->next == head) {
            if (head->value == target) { delete head; head = nullptr; return true; }
            return false;
        }
        if (head->value == target) {
            CircNode* tail = head;
            while (tail->next != head) tail = tail->next;
            CircNode* tmp = head;
            head = head->next;
            tail->next = head;
            delete tmp;
            return true;
        }
        CircNode* prev = head;
        CircNode* cur = head->next;
        while (cur != head && cur->value != target) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == head) return false;
        prev->next = cur->next;
        delete cur;
        return true;
    }

    int searchValue(int target) {
        if (!head) return -1;
        CircNode* cur = head;
        int pos = 1;
        do {
            if (cur->value == target) return pos;
            cur = cur->next;
            ++pos;
        } while (cur != head);
        return -1;
    }

    void displayRepeatHead() {
        if (!head) { cout << "List is empty\n"; return; }
        CircNode* cur = head;
        do {
            cout << cur->value << " ";
            cur = cur->next;
        } while (cur != head);
        cout << head->value << '\n';
    }

    int size() {
        if (!head) return 0;
        int cnt = 0;
        CircNode* cur = head;
        do { ++cnt; cur = cur->next; } while (cur != head);
        return cnt;
    }

    string toString() {
        if (!head) return "Empty";
        stringstream ss;
        CircNode* cur = head;
        bool first = true;
        do {
            if (!first) ss << " -> ";
            ss << cur->value;
            first = false;
            cur = cur->next;
        } while (cur != head);
        return ss.str();
    }

    ~CircularList() {
        if (!head) return;
        CircNode* cur = head->next;
        while (cur != head) {
            CircNode* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        delete head;
        head = nullptr;
    }
};

void circularMenu(CircularList &cl) {
    while (true) {
        cout << "\nCircular List Menu\n";
        cout << "1 Insert as first\n2 Insert as last\n3 Insert after value\n4 Insert before value\n";
        cout << "5 Delete a value\n6 Search for value\n7 Display list (repeat head at end)\n8 Size\n9 Show compact representation\n0 Back\n";
        cout << "Choice: ";
        int ch; if (!(cin >> ch)) return;
        if (ch == 0) break;
        int v, target;
        bool res;
        switch (ch) {
            case 1:
                cout << "Enter integer to insert as first: ";
                cin >> v;
                cl.insertAsFirst(v);
                cout << "Done\n";
                break;
            case 2:
                cout << "Enter integer to insert as last: ";
                cin >> v;
                cl.insertAsLast(v);
                cout << "Done\n";
                break;
            case 3:
                cout << "Enter target value to insert after: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> v;
                res = cl.insertAfterValue(target, v);
                cout << (res ? "Inserted after target\n" : "Target not found\n");
                break;
            case 4:
                cout << "Enter target value to insert before: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> v;
                res = cl.insertBeforeValue(target, v);
                cout << (res ? "Inserted before target\n" : "Target not found\n");
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> target;
                res = cl.deleteValue(target);
                cout << (res ? "Deleted value\n" : "Value not found\n");
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> target;
                {
                    int pos = cl.searchValue(target);
                    if (pos == -1) cout << "Not found\n"; else cout << "Found at position " << pos << '\n';
                }
                break;
            case 7:
                cl.displayRepeatHead();
                break;
            case 8:
                cout << "Size: " << cl.size() << '\n';
                break;
            case 9:
                cout << cl.toString() << '\n';
                break;
            default:
                cout << "Invalid\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    CircularList cl;
    while (true) {
        cout << "\nMain Menu\n1 Work with Circular Linked List\n0 Exit\nChoice: ";
        int ch; if (!(cin >> ch)) break;
        if (ch == 0) break;
        if (ch == 1) circularMenu(cl);
        else cout << "Invalid choice\n";
    }
    cout << "Goodbye\n";
    return 0;
}

