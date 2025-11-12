#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root = nullptr;

    // Insert node in BST
    Node* insert(Node* root, int value) {
        if (!root) return new Node(value);
        if (value < root->data) root->left = insert(root->left, value);
        else if (value > root->data) root->right = insert(root->right, value);
        return root;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    // (a) Search recursive
    Node* searchRecursive(Node* root, int key) {
        if (!root || root->data == key) return root;
        if (key < root->data) return searchRecursive(root->left, key);
        return searchRecursive(root->right, key);
    }

    // (a) Search non-recursive
    Node* searchIterative(int key) {
        Node* cur = root;
        while (cur) {
            if (cur->data == key) return cur;
            if (key < cur->data) cur = cur->left;
            else cur = cur->right;
        }
        return nullptr;
    }

    // (b) Maximum element
    Node* findMax(Node* root) {
        if (!root) return nullptr;
        while (root->right) root = root->right;
        return root;
    }

    // (c) Minimum element
    Node* findMin(Node* root) {
        if (!root) return nullptr;
        while (root->left) root = root->left;
        return root;
    }

    // (d) In-order successor
    Node* inorderSuccessor(Node* root, Node* target) {
        if (target->right) return findMin(target->right);

        Node* successor = nullptr;
        Node* ancestor = root;
        while (ancestor != target) {
            if (target->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }

    // (e) In-order predecessor
    Node* inorderPredecessor(Node* root, Node* target) {
        if (target->left) return findMax(target->left);

        Node* predecessor = nullptr;
        Node* ancestor = root;
        while (ancestor != target) {
            if (target->data > ancestor->data) {
                predecessor = ancestor;
                ancestor = ancestor->right;
            } else {
                ancestor = ancestor->left;
            }
        }
        return predecessor;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    BST tree;
    vector<int> values = {50, 30, 70, 20, 40, 60, 80};

    for (int v : values) tree.insert(v);

    cout << "In-order Traversal: ";
    tree.inorder(tree.root);
    cout << "\n";

    int key = 40;
    cout << "Searching (Recursive) for " << key << ": ";
    cout << (tree.searchRecursive(tree.root, key) ? "Found\n" : "Not Found\n");

    cout << "Searching (Iterative) for " << key << ": ";
    cout << (tree.searchIterative(key) ? "Found\n" : "Not Found\n");

    cout << "Minimum Element: " << tree.findMin(tree.root)->data << "\n";
    cout << "Maximum Element: " << tree.findMax(tree.root)->data << "\n";

    Node* target = tree.searchRecursive(tree.root, 50);
    Node* succ = tree.inorderSuccessor(tree.root, target);
    Node* pred = tree.inorderPredecessor(tree.root, target);

    cout << "In-order Successor of " << target->data << ": ";
    if (succ) cout << succ->data << "\n"; else cout << "None\n";

    cout << "In-order Predecessor of " << target->data << ": ";
    if (pred) cout << pred->data << "\n"; else cout << "None\n";

    return 0;
}

