#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string arr[] = {"banana","apple","cherry","date"};
    int n = 4;
    sort(arr, arr+n);
    cout << "Sorted strings: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}

