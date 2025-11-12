#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> a) {
    for (int i = 0; i < a.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < a.size(); j++)
            if (a[j] < a[minIndex]) minIndex = j;
        swap(a[i], a[minIndex]);
    }
    cout << "Selection Sort: ";
    for (int x : a) cout << x << " ";
    cout << "\n";
}

void insertionSort(vector<int> a) {
    for (int i = 1; i < a.size(); i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    cout << "Insertion Sort: ";
    for (int x : a) cout << x << " ";
    cout << "\n";
}

void bubbleSort(vector<int> a) {
    for (int i = 0; i < a.size() - 1; i++)
        for (int j = 0; j < a.size() - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
    cout << "Bubble Sort: ";
    for (int x : a) cout << x << " ";
    cout << "\n";
}

void merge(vector<int>& a, int l, int m, int r) {
    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size())
        a[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    while (i < left.size()) a[k++] = left[i++];
    while (j < right.size()) a[k++] = right[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    selectionSort(arr);
    insertionSort(arr);
    bubbleSort(arr);

    vector<int> mergeArr = arr;
    mergeSort(mergeArr, 0, mergeArr.size() - 1);
    cout << "Merge Sort: ";
    for (int x : mergeArr) cout << x << " ";
    cout << "\n";

    vector<int> quickArr = arr;
    quickSort(quickArr, 0, quickArr.size() - 1);
    cout << "Quick Sort: ";
    for (int x : quickArr) cout << x << " ";
    cout << "\n";

    return 0;
}

