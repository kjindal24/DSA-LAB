#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->val) root->left = insertNode(root->left, key);
    else if (key > root->val) root->right = insertNode(root->right, key);
    // if equal, ignore (no duplicates)
    return root;
}

Node* findMinNode(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // found node to delete
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        }
        if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        }
        // two children: replace with inorder successor (smallest in right subtree)
        Node* succ = findMinNode(root->right);
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + max(l, r);
}

int minDepth(Node* root) {
    if (!root) return 0;
    // if one child is missing, we must consider the depth of the non-missing child
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = nullptr;
    while (true) {
        cout << "\nBST Menu\n";
        cout << "1. Insert (no duplicates)\n";
        cout << "2. Delete\n";
        cout << "3. In-order display\n";
        cout << "4. Maximum depth (height)\n";
        cout << "5. Minimum depth\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        int choice;
        if (!(cin >> choice)) break;

        if (choice == 0) break;

        if (choice == 1) {
            cout << "Enter integer to insert: ";
            int x; cin >> x;
            // check duplicate quickly (optional): search while inserting will ignore duplicates anyway
            Node* before = root;
            root = insertNode(root, x);
            cout << "Inserted " << x << " (duplicates ignored).\n";
        } else if (choice == 2) {
            cout << "Enter integer to delete: ";
            int x; cin >> x;
            // optional: check if exists before deleting
            root = deleteNode(root, x);
            cout << "Deleted (if existed): " << x << "\n";
        } else if (choice == 3) {
            if (!root) cout << "Tree is empty\n";
            else {
                cout << "In-order: ";
                inorder(root);
                cout << "\n";
            }
        } else if (choice == 4) {
            cout << "Maximum depth: " << maxDepth(root) << "\n";
        } else if (choice == 5) {
            cout << "Minimum depth: " << minDepth(root) << "\n";
        } else {
            cout << "Invalid choice\n";
        }
    }

    freeTree(root);
    cout << "Goodbye\n";
    return 0;
}

