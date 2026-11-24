#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <type_traits>
using namespace std;

// Шаблонный класс для хранения облака точек//использовать только арифметические типы данных
template <typename T, int Dimensions>
class PointCloud {

    static_assert(is_arithmetic<T>::value,
        "Ошибка: разрешены только числовые типы данных");

    static_assert(Dimensions > 0,
        "Ошибка: количество измерений должно быть больше нуля");

private:

    // Хранение точек облака
    vector<array<T, Dimensions>> points;

};