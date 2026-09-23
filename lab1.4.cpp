#include <iostream>
using namespace std;

/**
 * @brief Выделяет память для двумерного динамического массива.
 *
 * Создаёт матрицу с заданным количеством строк и столбцов.
 *
 * @param rows Количество строк матрицы.
 * @param cols Количество столбцов матрицы.
 * @return int** Указатель на созданную матрицу.
 */
int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];

    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

/**
 * @brief Заполняет матрицу с клавиатуры.
 *
 * Пользователь вводит значения всех элементов матрицы.
 *
 * @param matrix Матрица для заполнения.
 * @param rows Количество строк матрицы.
 * @param cols Количество столбцов матрицы.
 */
void fillMatrix(int** matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

/**
 * @brief Выводит матрицу на экран.
 *
 * Может отображать границы матрицы и заданный заголовок.
 *
 * @param matrix Матрица для вывода.
 * @param rows Количество строк матрицы.
 * @param cols Количество столбцов матрицы.
 * @param showBorders Показывать ли границы матрицы.
 * @param title Заголовок матрицы.
 */
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

/**
 * @brief Освобождает память, выделенную для матрицы.
 *
 * Удаляет строки матрицы, а затем освобождает память самого массива указателей.
 *
 * @param matrix Матрица, занимающая динамическую память.
 * @param rows Количество строк матрицы.
 */
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

/**
 * @brief Главная функция программы.
 *
 * Создаёт матрицу оценок размером 3 на 3, заполняет её с клавиатуры и выводит в нескольких вариантах.
 *
 * @return 0 Если программа завершилась успешно.
 */
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