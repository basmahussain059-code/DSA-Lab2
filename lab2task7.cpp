#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of marks (1 to 10): ";
    cin >> n;
    if (n < 1 || n > 10) {
        cout << "Invalid input. n must be between 1 and 10." << endl;
        return 0;
    }
    int* marks = new int[n];  
    
    for (int i = 0; i < n; i++) {
         cout << "Enter mark of student " << (i + 1) << ": ";
        cin >> *(marks + i);  
    }
    int* newMarks = new int[n + 1];  
    // Copy old values
    for (int i = 0; i < n; i++) {
        *(newMarks + i) = *(marks + i);
    }
    // Read new mark
    cout << "Enter new mark: ";
    cin >> *(newMarks + n);
    // Release old block and update pointer
    delete[] marks;
    marks = newMarks;
    n = n + 1;
    // Display all marks
    cout << "\nAll marks:" << endl;
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
    }
    cout << endl;
    // Release final block
    delete[] marks;
    marks = nullptr;
    return 0;
}
