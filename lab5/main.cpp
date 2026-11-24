#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <type_traits>
using namespace std;

// Шаблонный класс для хранения облака точек
template <typename T, int Dimensions>
class PointCloud {

    // Проверка допустимости типа данных
    static_assert(is_arithmetic<T>::value, "Разрешены только числовые типы");

    // Проверка количества измерений
    static_assert(Dimensions > 0, "Количество измерений должно быть больше нуля");

private:
    // Хранение всех точек облака
    vector<array<T, Dimensions>> points;

public:
    // Добавление новой точки
    void addPoint(array<T, Dimensions> point) {
        points.push_back(point);
    }

    // Получение количества точек
    int getSize() const {
        return points.size();
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

int main() {

    return 0;
}


