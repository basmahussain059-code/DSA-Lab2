#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    // input rows and columns
    cout << "Enter number of students: ";
    cin >> rows;
    cout << "Enter number of subjects: ";
    cin >> cols;
    // check 
    if (rows <= 0 || cols <= 0) {
        cout << "Invalid input " << endl;
        return 0;
    }

    // Dynamic allocation
    int** marks = new int*[rows];
    for (int i = 0; i < rows; i++) {
        marks[i] = new int[cols];
    }

    // Input marks using pointer 
    cout << "Enter marks (0-100):" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) { 
            cout << "Student " << (r+1) << ", Mark in Subject " << (c+1) << ": ";
            cin >> *(*(marks + r) + c); 
        }
    }
    // Display matrix
    cout << "\nMarks Matrix:" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << marks[r][c] << " ";
        }
        cout << endl;
    }

    // Calculate totals and find top student
    int bestTotal = -1;
    int bestStudent = -1;
    cout << "\nTotals:" << endl;
    for (int r = 0; r < rows; r++) {
        int total = 0;
        for (int c = 0; c < cols; c++) {
            total += marks[r][c];
        }
        cout << "Student " << (r+1) << ": " << total << endl;

        if (total > bestTotal) {
            bestTotal = total;
            bestStudent = r + 1; 
        }
    }
    cout << "Top student: " << bestStudent 
         << " with total " << bestTotal << endl;
    for (int i = 0; i < rows; i++) {
        delete[] marks[i];   // delete each row
    }
    delete[] marks;          // delete row pointers
    marks = nullptr;
    return 0;
}
