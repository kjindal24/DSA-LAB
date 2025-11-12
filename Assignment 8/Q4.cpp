#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

void inorder(Node* root, vector<int>& out) {
    if (!root) return;
    inorder(root->left, out);
    out.push_back(root->val);
    inorder(root->right, out);
}

bool isBST(Node* root) {
    vector<int> vals;
    inorder(root, vals);
    for (size_t i = 1; i < vals.size(); ++i)
        if (vals[i] <= vals[i-1]) return false;
    return true;
}

int main() {
    // Example 1: BST
    Node* r1 = new Node(50);
    r1->left = new Node(30);
    r1->right = new Node(70);
    r1->left->left = new Node(20);
    r1->left->right = new Node(40);
    r1->right->left = new Node(60);

    cout << "Tree1 is " << (isBST(r1) ? "a BST\n" : "NOT a BST\n");

    // Example 2: Not a BST
    Node* r2 = new Node(50);
    r2->left = new Node(30);
    r2->right = new Node(70);
    r2->left->right = new Node(65); // violates BST property

    cout << "Tree2 is " << (isBST(r2) ? "a BST\n" : "NOT a BST\n");

    // cleanup
    function<void(Node*)> freeTree = [&](Node* cur){
        if (!cur) return;
        freeTree(cur->left);
        freeTree(cur->right);
        delete cur;
    };
    freeTree(r1); freeTree(r2);
    return 0;
}

