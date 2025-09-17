#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    unordered_map<char, int> freq;
    queue<char> q;

    for (char c : str) {
        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s = "aabc";
    cout << "Input: " << s << endl;
    cout << "Output: ";
    firstNonRepeating(s);
    return 0;
}

