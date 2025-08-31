#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX], n = 0;

void create() {
   
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

}

void display() {
   
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
   
    cout << "Array elements: ";
   
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void insert() {
    
	int pos, val;
   
    cout << "Enter position (1-" << n + 1 << "): ";
   
    cin >> pos;
   
    while (pos < 1 || pos > n + 1) {
        cout << "Invalid position.\n";
        cout << "Enter position (1-" << n + 1 << "): ";
		cin << pos;  
    }
    cout << "Enter value: ";
   
    cin >> val;
    
    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = val;
    n++;
}

void delete_elem() {
    int pos;
    cout << "Enter position (1-" << n << "): ";
    cin >> pos;
     while (pos < 1 || pos > n + 1) {
        cout << "Invalid position.\n";
        cout << "Enter position (1-" << n + 1 << "): ";
		cin << pos;  
    }
    for (int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void linear_search() {
    int val, found = 0;
    cout << "Enter value to search: ";
    cin >> val;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << "Found at position " << i + 1 << "\n";
            found = 1;
        }
    }
    if (!found)
        cout << "Not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n---MENU---\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: delete_elem(); break;
            case 5: linear_search(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}

