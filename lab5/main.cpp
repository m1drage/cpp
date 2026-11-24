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

    // Получение количества точек в облаке
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
};

// Инициализация статического счётчика
template <typename T, int Dimensions>
int PointCloud<T, Dimensions>::totalPoints = 0;

int main() {

    return 0;
}