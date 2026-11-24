#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <type_traits>
using namespace std;

// Шаблонный класс для хранения облака точек
template <typename T, int Dimensions>
class PointCloud {

    static_assert(is_arithmetic<T>::value, "Разрешены только числовые типы");

    static_assert(Dimensions > 0, "Количество измерений должно быть больше нуля");

private:
    // Хранение всех точек облака
    vector<array<T, Dimensions>> points;

    // Общее количество точек во всех облаках
    static int totalPoints;

public:
    // Добавление новой точки
    void addPoint(array<T, Dimensions> point) {
        points.push_back(point);
        totalPoints++;
    }

    // Получение количества точек
    int getSize() const {
        return points.size();
    }

    // Получение общего количества точек
    static int getTotalPoints() {
        return totalPoints;
    }

    // Вывод всех точек
    void print() const {
        for (int i = 0; i < points.size(); i++) {
            cout << "Точка " << i + 1 << ": ";

            for (int j = 0; j < Dimensions; j++) {
                cout << points[i][j] << " ";
            }

            cout << endl;
        }
    }

    // Получение точки по номеру
    array<T, Dimensions> getPoint(int index) const {
        return points[index];
    }
};

// Инициализация статического счётчика
template <typename T, int Dimensions>
int PointCloud<T, Dimensions>::totalPoints = 0;

// Шаблонная функция вычисления центроида
template <typename T, int Dimensions>
array<double, Dimensions> calculateCentroid(
    const PointCloud<T, Dimensions>& cloud) {

    array<double, Dimensions> center = {};

    if (cloud.getSize() == 0) {
        return center;
    }

    // Суммирование координат всех точек
    for (int i = 0; i < cloud.getSize(); i++) {
        auto point = cloud.getPoint(i);

        for (int j = 0; j < Dimensions; j++) {
            center[j] += point[j];
        }
    }

    // Вычисление среднего значения координат
    for (int j = 0; j < Dimensions; j++) {
        center[j] /= cloud.getSize();
    }

    return center;
}

// Специализация класса для трёхмерного пространства
template <typename T>
class PointCloud<T, 3> {

    static_assert(is_arithmetic<T>::value,
        "Разрешены только числовые типы");

private:

    // Хранение трёхмерных точек
    vector<array<T, 3>> points;

    // Общее количество точек
    static int totalPoints;

public:

    // Добавление точки
    void addPoint(array<T, 3> point) {
        points.push_back(point);
        totalPoints++;
    }

    // Получение количества точек
    int getSize() const {
        return points.size();
    }

    // Получение общего количества точек
    static int getTotalPoints() {
        return totalPoints;
    }

    // Получение точки по номеру
    array<T, 3> getPoint(int index) const {
        return points[index];
    }

    // Вывод точек
    void print() const {
        for (int i = 0; i < points.size(); i++) {
            cout << "Точка " << i + 1 << ": ";

            for (int j = 0; j < 3; j++) {
                cout << points[i][j] << " ";
            }

            cout << endl;
        }
    }

    // Вычисление векторного произведения двух точек
    array<T, 3> crossProduct(
        array<T, 3> a, array<T, 3> b) {

        return {
            a[1] * b[2] - a[2] * b[1],
            a[2] * b[0] - a[0] * b[2],
            a[0] * b[1] - a[1] * b[0]
        };
    }
};
// Инициализация счётчика для трёхмерного облака
template <typename T> 
int PointCloud<T, 3>::totalPoints = 0;

int main() {

    return 0;
}


