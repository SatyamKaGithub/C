// Write a program in c++ to print the sum of diagonal element of a matrix

#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;
    int matrix[n][n];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter element at row " << i + 1 << " and column " << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    cout << "Sum of diagonal elements: " << sum << endl;
    return 0;
}
