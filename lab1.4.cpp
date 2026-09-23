#include <iostream>
using namespace std;

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];

    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void fillMatrix(int** matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, string title = "Matrix") 
{
    cout << title << endl;
    if (showBorders) {
        for (int i = 0; i < cols * 3; i++) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++) {
        if (showBorders) {
            cout << "* ";
        }

        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }

        if (showBorders) {
            cout << "*";
        }
        cout << endl;
    }
    if (showBorders) {
        for (int i = 0; i < cols * 3; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows = 3;
    int cols = 3;

    int** matrix = allocateMatrix(rows, cols);

    cout << "Enter grades(9):" << endl;

    fillMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols, true, "Grades");
    printMatrix(matrix, rows, cols, false, "Student grades");

    freeMatrix(matrix, rows);
    return 0;
}