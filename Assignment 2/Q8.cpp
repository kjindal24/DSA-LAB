#include <iostream>
#include <set>
using namespace std;

int main() {
    int arr[] = {1,2,2,3,4,4,5};
    int n = 7;
    set<int> s(arr, arr+n);
    cout << "Total distinct elements: " << s.size();
    return 0;
}

