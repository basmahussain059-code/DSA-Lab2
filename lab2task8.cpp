#include <iostream>
using namespace std;
int main() {
    int n = 3;
    int* values = new int[n];   // allocate 3 integers
    for (int i = 0; i < n; i++) {
        cout << "Enter value " << (i + 1) << ": ";
        cin >> *(values + i);   // pointer notation
    }
    cout << "\nEntered values:" << endl;
    for (int i = 0; i < n; i++) {
        cout << *(values + i) << " ";
    }
    cout << endl;
    delete[] values;
    values = nullptr;   // set pointer to nullptr after deletion
    return 0;
}
