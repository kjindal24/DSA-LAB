#include <iostream>
using namespace std;

int main() {
    int i;
    int arr[5] = {1};
    for (i = 0; i < 5; i++)
        cout << arr[i];
    cout << "\nExplanation: First element is 1, rest are default initialized to 0.";
    return 0;
}

