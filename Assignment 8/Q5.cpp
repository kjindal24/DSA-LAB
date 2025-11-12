#include <bits/stdc++.h>
using namespace std;

void heapifyMax(vector<int>& a, int n, int i) {
    int largest = i;
    while (true) {
        int l = 2*i + 1, r = 2*i + 2;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest != i) { swap(a[i], a[largest]); i = largest; } else break;
    }
}

void heapifyMin(vector<int>& a, int n, int i) {
    int smallest = i;
    while (true) {
        int l = 2*i + 1, r = 2*i + 2;
        if (l < n && a[l] < a[smallest]) smallest = l;
        if (r < n && a[r] < a[smallest]) smallest = r;
        if (smallest != i) { swap(a[i], a[smallest]); i = smallest; } else break;
    }
}

vector<int> heapSortIncreasing(vector<int> a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; --i) heapifyMax(a, n, i);
    for (int end = n-1; end > 0; --end) {
        swap(a[0], a[end]);
        heapifyMax(a, end, 0);
    }
    return a;
}

vector<int> heapSortDecreasing(vector<int> a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; --i) heapifyMin(a, n, i);
    for (int end = n-1; end > 0; --end) {
        swap(a[0], a[end]);
        heapifyMin(a, end, 0);
    }
    return a;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Original: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    auto inc = heapSortIncreasing(arr);
    cout << "Heapsort (increasing): ";
    for (int x : inc) cout << x << " ";
    cout << "\n";

    auto dec = heapSortDecreasing(arr);
    cout << "Heapsort (decreasing): ";
    for (int x : dec) cout << x << " ";
    cout << "\n";

    return 0;
}

