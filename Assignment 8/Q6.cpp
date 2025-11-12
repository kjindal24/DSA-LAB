#include <bits/stdc++.h>
using namespace std;

struct MaxHeap {
    vector<int> a;
    void push(int x) {
        a.push_back(x);
        int i = a.size()-1;
        while (i > 0) {
            int p = (i-1)/2;
            if (a[p] < a[i]) { swap(a[p], a[i]); i = p; } else break;
        }
    }
    int top() const { return a.empty() ? INT_MIN : a[0]; }
    void pop() {
        if (a.empty()) return;
        a[0] = a.back();
        a.pop_back();
        if (!a.empty()) {
            int n = a.size(), i = 0;
            while (true) {
                int l = 2*i + 1, r = 2*i + 2, largest = i;
                if (l < n && a[l] > a[largest]) largest = l;
                if (r < n && a[r] > a[largest]) largest = r;
                if (largest != i) { swap(a[i], a[largest]); i = largest; } else break;
            }
        }
    }
    bool empty() const { return a.empty(); }
    int size() const { return a.size(); }
};

struct MinHeap {
    vector<int> a;
    void push(int x) {
        a.push_back(x);
        int i = a.size()-1;
        while (i > 0) {
            int p = (i-1)/2;
            if (a[p] > a[i]) { swap(a[p], a[i]); i = p; } else break;
        }
    }
    int top() const { return a.empty() ? INT_MAX : a[0]; }
    void pop() {
        if (a.empty()) return;
        a[0] = a.back();
        a.pop_back();
        if (!a.empty()) {
            int n = a.size(), i = 0;
            while (true) {
                int l = 2*i + 1, r = 2*i + 2, smallest = i;
                if (l < n && a[l] < a[smallest]) smallest = l;
                if (r < n && a[r] < a[smallest]) smallest = r;
                if (smallest != i) { swap(a[i], a[smallest]); i = smallest; } else break;
            }
        }
    }
    bool empty() const { return a.empty(); }
    int size() const { return a.size(); }
};

int main() {
    MaxHeap mh;
    mh.push(20); mh.push(5); mh.push(30); mh.push(10);
    cout << "MaxHeap top: " << mh.top() << "\n";
    mh.pop();
    cout << "MaxHeap top after pop: " << mh.top() << "\n";
    cout << "MaxHeap size: " << mh.size() << "\n";

    MinHeap nh;
    nh.push(20); nh.push(5); nh.push(30); nh.push(10);
    cout << "MinHeap top: " << nh.top() << "\n";
    nh.pop();
    cout << "MinHeap top after pop: " << nh.top() << "\n";
    cout << "MinHeap size: " << nh.size() << "\n";

    // demonstration: repeatedly pop max-heap
    cout << "Emptying MaxHeap: ";
    while (!mh.empty()) { cout << mh.top() << " "; mh.pop(); }
    cout << "\n";

    cout << "Emptying MinHeap: ";
    while (!nh.empty()) { cout << nh.top() << " "; nh.pop(); }
    cout << "\n";

    return 0;
}

