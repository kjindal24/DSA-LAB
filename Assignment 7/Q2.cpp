#include <bits/stdc++.h>
using namespace std;

void improvedSelectionSort(vector<int>& a) {
    int start = 0, end = a.size() - 1;

    while (start < end) {
        int minIndex = start, maxIndex = end;
        for (int i = start; i <= end; i++) {
            if (a[i] < a[minIndex]) minIndex = i;
            if (a[i] > a[maxIndex]) maxIndex = i;
        }

        swap(a[start], a[minIndex]);

        if (maxIndex == start) maxIndex = minIndex;

        swap(a[end], a[maxIndex]);

        start++;
        end--;
    }
}

int main() {
    vector<int> arr = {29, 10, 14, 37, 13, 5, 9, 30};
    improvedSelectionSort(arr);
    cout << "Improved Selection Sort: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
    return 0;
}

