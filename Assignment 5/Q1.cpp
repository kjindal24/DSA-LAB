#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head = nullptr;

    Node* findNode(int value) {
        Node* cur = head;
        while (cur) {
            if (cur->data == value) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

public:
    void insertAtBeginning(int value) {
        Node* n = new Node(value);
        n->next = head;
        head = n;
    }

    void insertAtEnd(int value) {
        Node* n = new Node(value);
        if (!head) {
            head = n;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }

    bool insertBefore(int target, int value) {
        if (!head) return false;
        if (head->data == target) {
            insertAtBeginning(value);
            return true;
        }
        Node* prev = nullptr;
        Node* cur = head;
        while (cur && cur->data != target) {
            prev = cur;
            cur = cur->next;
        }
        if (!cur) return false;
        Node* n = new Node(value);
        prev->next = n;
        n->next = cur;
        return true;
    }

    bool insertAfter(int target, int value) {
        Node* cur = findNode(target);
        if (!cur) return false;
        Node* n = new Node(value);
        n->next = cur->next;
        cur->next = n;
        return true;
    }

    bool deleteFromBeginning() {
        if (!head) return false;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }

    bool deleteFromEnd() {
        if (!head) return false;
        if (!head->next) {
            delete head;
            head = nullptr;
            return true;
        }
        Node* prev = nullptr;
        Node* cur = head;
        while (cur->next) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = nullptr;
        delete cur;
        return true;
    }

    bool deleteNode(int value) {
        if (!head) return false;
        if (head->data == value) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            return true;
        }
        Node* prev = nullptr;
        Node* cur = head;
        while (cur && cur->data != value) {
            prev = cur;
            cur = cur->next;
        }
        if (!cur) return false;
        prev->next = cur->next;
        delete cur;
        return true;
    }

    int searchValue(int value) {
        Node* cur = head;
        int pos = 1;
        while (cur) {
            if (cur->data == value) return pos;
            cur = cur->next;
            ++pos;
        }
        return -1;
    }

    void displayAll() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << '\n';
    }

    ~SinglyLinkedList() {
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

    SinglyLinkedList list;
    int choice = 0;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before a value\n";
        cout << "4. Insert after a value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific value\n";
        cout << "8. Search for a value (position from head)\n";
        cout << "9. Display all nodes\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) break;

        if (choice == 0) break;

        int val, target;
        bool result;
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                list.insertAtBeginning(val);
                cout << "Inserted " << val << " at beginning\n";
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                list.insertAtEnd(val);
                cout << "Inserted " << val << " at end\n";
                break;
            case 3:
                cout << "Enter target value to insert before: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> val;
                result = list.insertBefore(target, val);
                if (result) cout << "Inserted " << val << " before " << target << '\n';
                else cout << "Target " << target << " not found\n";
                break;
            case 4:
                cout << "Enter target value to insert after: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> val;
                result = list.insertAfter(target, val);
                if (result) cout << "Inserted " << val << " after " << target << '\n';
                else cout << "Target " << target << " not found\n";
                break;
            case 5:
                result = list.deleteFromBeginning();
                if (result) cout << "Deleted node from beginning\n";
                else cout << "List is empty\n";
                break;
            case 6:
                result = list.deleteFromEnd();
                if (result) cout << "Deleted node from end\n";
                else cout << "List is empty\n";
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> val;
                result = list.deleteNode(val);
                if (result) cout << "Deleted node with value " << val << '\n';
                else cout << "Value " << val << " not found\n";
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> val;
                {
                    int pos = list.searchValue(val);
                    if (pos == -1) cout << "Value not found\n";
                    else cout << "Value found at position " << pos << " from head\n";
                }
                break;
            case 9:
                list.displayAll();
                break;
            default:
                cout << "Invalid choice\n";
        }
    }

    cout << "Exiting. Goodbye.\n";
    return 0;
}

