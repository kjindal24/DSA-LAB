#include <bits/stdc++.h>
using namespace std;

struct DblNode {
    char value;
    DblNode* prev;
    DblNode* next;
    DblNode(char v): value(v), prev(nullptr), next(nullptr) {}
};

class DoublyList {
    DblNode* head = nullptr;
    DblNode* tail = nullptr;

public:
    bool isEmpty() const { return head == nullptr; }

    void insertAsFirst(char c) {
        DblNode* n = new DblNode(c);
        if (!head) { head = tail = n; return; }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void insertAsLast(char c) {
        DblNode* n = new DblNode(c);
        if (!tail) { head = tail = n; return; }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    bool insertAfterValue(char target, char c) {
        DblNode* cur = head;
        while (cur) {
            if (cur->value == target) {
                DblNode* n = new DblNode(c);
                n->next = cur->next;
                n->prev = cur;
                if (cur->next) cur->next->prev = n;
                cur->next = n;
                if (cur == tail) tail = n;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    bool insertBeforeValue(char target, char c) {
        DblNode* cur = head;
        while (cur) {
            if (cur->value == target) {
                DblNode* n = new DblNode(c);
                n->next = cur;
                n->prev = cur->prev;
                if (cur->prev) cur->prev->next = n;
                cur->prev = n;
                if (cur == head) head = n;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    bool deleteValue(char target) {
        DblNode* cur = head;
        while (cur) {
            if (cur->value == target) {
                if (cur->prev) cur->prev->next = cur->next;
                else head = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                else tail = cur->prev;
                delete cur;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    int searchValue(char target) {
        DblNode* cur = head;
        int pos = 1;
        while (cur) {
            if (cur->value == target) return pos;
            cur = cur->next;
            ++pos;
        }
        return -1;
    }

    int size() {
        int cnt = 0;
        DblNode* cur = head;
        while (cur) { ++cnt; cur = cur->next; }
        return cnt;
    }

    bool isPalindrome() {
        if (!head) return true;
        DblNode* l = head;
        DblNode* r = tail;
        while (l != r && l->prev != r) {
            if (l->value != r->value) return false;
            l = l->next;
            r = r->prev;
        }
        return true;
    }

    string toStringChars() {
        if (!head) return "Empty";
        stringstream ss;
        DblNode* cur = head;
        bool first = true;
        while (cur) {
            if (!first) ss << " -> ";
            ss << cur->value;
            first = false;
            cur = cur->next;
        }
        return ss.str();
    }

    ~DoublyList() {
        DblNode* cur = head;
        while (cur) {
            DblNode* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = tail = nullptr;
    }
};

void doublyMenu(DoublyList &dl) {
    while (true) {
        cout << "\nDoubly List Menu\n";
        cout << "1 Insert as first\n2 Insert as last\n3 Insert after value\n4 Insert before value\n";
        cout << "5 Delete a value\n6 Search for value\n7 Size\n8 Show list\n9 Palindrome check (chars)\n0 Back\n";
        cout << "Choice: ";
        int ch; if (!(cin >> ch)) return;
        if (ch == 0) break;
        char c, target;
        bool res;
        switch (ch) {
            case 1:
                cout << "Enter character to insert as first: ";
                cin >> c;
                dl.insertAsFirst(c);
                cout << "Done\n";
                break;
            case 2:
                cout << "Enter character to insert as last: ";
                cin >> c;
                dl.insertAsLast(c);
                cout << "Done\n";
                break;
            case 3:
                cout << "Enter target character to insert after: ";
                cin >> target;
                cout << "Enter new character: ";
                cin >> c;
                res = dl.insertAfterValue(target, c);
                cout << (res ? "Inserted after target\n" : "Target not found\n");
                break;
            case 4:
                cout << "Enter target character to insert before: ";
                cin >> target;
                cout << "Enter new character: ";
                cin >> c;
                res = dl.insertBeforeValue(target, c);
                cout << (res ? "Inserted before target\n" : "Target not found\n");
                break;
            case 5:
                cout << "Enter character to delete: ";
                cin >> target;
                res = dl.deleteValue(target);
                cout << (res ? "Deleted\n" : "Character not found\n");
                break;
            case 6:
                cout << "Enter character to search: ";
                cin >> target;
                {
                    int pos = dl.searchValue(target);
                    if (pos == -1) cout << "Not found\n"; else cout << "Found at position " << pos << '\n';
                }
                break;
            case 7:
                cout << "Size: " << dl.size() << '\n';
                break;
            case 8:
                cout << dl.toStringChars() << '\n';
                break;
            case 9:
                cout << (dl.isPalindrome() ? "Palindrome\n" : "Not a palindrome\n");
                break;
            default:
                cout << "Invalid\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DoublyList dl;
    while (true) {
        cout << "\nMain Menu\n1 Work with Doubly Linked List\n0 Exit\nChoice: ";
        int ch; if (!(cin >> ch)) break;
        if (ch == 0) break;
        if (ch == 1) doublyMenu(dl);
        else cout << "Invalid choice\n";
    }
    cout << "Goodbye\n";
    return 0;
}

