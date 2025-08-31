#include <iostream>
using namespace std;

int main() {
    string str = "Beautiful";
    string result = "";
    for(char c : str) {
        if(!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
             c=='A'||c=='E'||c=='I'||c=='O'||c=='U'))
            result += c;
    }
    cout << "Without vowels: " << result;
    return 0;
}

