#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[50] = "Hello ";
    char str2[] = "World!";
    strcat(str1, str2);
    cout << "Concatenated string: " << str1;
    return 0;
}

