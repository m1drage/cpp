#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <type_traits>
#include <windows.h>

using namespace std;

/**
 * @brief Шаблонный класс для хранения облака точек.
 *
 * Класс позволяет хранить координаты точек
 * в двумерном или трёхмерном пространстве.
 *
 * @tparam T Тип данных координат.
 * @tparam Dimensions Количество измерений.
 */
template <typename T, int Dimensions>
class PointCloud {

    static_assert(is_arithmetic<T>::value,
        "Разрешены только числовые типы");

    static_assert(Dimensions > 0,
        "Количество измерений должно быть больше нуля");

private:

    /**
     * @brief Контейнер для хранения точек.
     */
    vector<array<T, Dimensions>> points;

    /**
     * @brief Общее количество добавленных точек.
     */
    static int totalPoints;

    /**
     * @brief Дружественная функция для вывода точек.
     * @param cloud Облако точек.
     */
    template <typename U, int D>
    friend void showCloud(const PointCloud<U, D>& cloud);

public:

    /**
     * @brief Добавляет новую точку в облако.
     * @param point Массив координат точки.
     */
    void addPoint(array<T, Dimensions> point) {
        points.push_back(point);
        totalPoints++;
    }

    /**
     * @brief Возвращает количество точек.
     * @return Количество точек в облаке.
     */
    int getSize() const {
        return points.size();
    }

    /**
     * @brief Возвращает общее количество точек.
     * @return Общее количество точек.
     */
    static int getTotalPoints() {
        return totalPoints;
    }

    /**
     * @brief Возвращает точку по индексу.
     * @param index Индекс точки.
     * @return Массив координат.
     */
    array<T, Dimensions> getPoint(int index) const {
        return points[index];
    }

    /**
     * @brief Выводит все точки облака.
     */
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

/**
 * @brief Инициализация статического счётчика точек.
 */
template <typename T, int Dimensions>
int PointCloud<T, Dimensions>::totalPoints = 0;

/**
 * @brief Частичная специализация класса для трёхмерного пространства.
 * @tparam T Тип координат.
 */
template <typename T>
class PointCloud<T, 3> {

    static_assert(is_arithmetic<T>::value,
        "Разрешены только числовые типы");

private:

    /// Контейнер для хранения трёхмерных точек.
    vector<array<T, 3>> points;

    /// Общее количество трёхмерных точек.
    static int totalPoints;

    template <typename U, int D>
    friend void showCloud(const PointCloud<U, D>& cloud);

public:

    /**
     * @brief Добавляет трёхмерную точку.
     * @param point Массив из трёх координат.
     */
    void addPoint(array<T, 3> point) {
        points.push_back(point);
        totalPoints++;
    }

    /**
     * @brief Возвращает количество точек.
     */
    int getSize() const {
        return points.size();
    }

    /**
     * @brief Возвращает общее количество точек.
     */
    static int getTotalPoints() {
        return totalPoints;
    }

    /**
     * @brief Получает точку по индексу.
     */
    array<T, 3> getPoint(int index) const {
        return points[index];
    }

    /**
     * @brief Выводит трёхмерные точки.
     */
    void print() const {
        for (int i = 0; i < points.size(); i++) {
            cout << "Точка " << i + 1 << ": ";

            for (int j = 0; j < 3; j++) {
                cout << points[i][j] << " ";
            }

            cout << endl;
        }
    }

    /**
     * @brief Вычисляет векторное произведение двух векторов.
     * @param a Первый вектор.
     * @param b Второй вектор.
     * @return Результат векторного произведения.
     */
    array<T, 3> crossProduct(array<T, 3> a, array<T, 3> b) {
        return {
            a[1] * b[2] - a[2] * b[1],
            a[2] * b[0] - a[0] * b[2],
            a[0] * b[1] - a[1] * b[0] };
    }
};

/**
 * @brief Инициализация счётчика для трёхмерного облака.
 */
template <typename T>
int PointCloud<T, 3>::totalPoints = 0;

/**
 * @brief Вычисляет центроид облака точек.
 * @tparam T Тип координат.
 * @tparam Dimensions Количество измерений.
 * @param cloud Облако точек.
 * @return Массив координат центроида.
 */
template <typename T, int Dimensions>
array<double, Dimensions> calculateCentroid(
    const PointCloud<T, Dimensions>& cloud) {

    array<double, Dimensions> center = {};

    if (cloud.getSize() == 0) {
        return center;
    }

    for (int i = 0; i < cloud.getSize(); i++) {
        auto point = cloud.getPoint(i);

        for (int j = 0; j < Dimensions; j++) {
            center[j] += point[j];
        }
    }

    for (int j = 0; j < Dimensions; j++) {
        center[j] /= cloud.getSize();
    }

    return center;
}

/**
 * @brief Выводит координаты центроида.
 * @tparam T Тип координат.
 * @tparam Dimensions Количество измерений.
 * @param cloud Облако точек.
 */
template <typename T, int Dimensions>
void printCentroid(const PointCloud<T, Dimensions>& cloud) {

    auto center = calculateCentroid(cloud);

    cout << "Центроид: ";

    for (int i = 0; i < Dimensions; i++) {
        cout << center[i] << " ";
    }

    cout << endl;
}

/**
 * @brief Специализация вывода центроида для целых чисел в 2D.
 * @param cloud Двумерное облако точек.
 */
template <>
void printCentroid<int, 2>(const PointCloud<int, 2>& cloud) {

    auto center = calculateCentroid(cloud);

    cout << "Центроид двумерного облака: ";

    for (int i = 0; i < 2; i++) {
        cout << center[i] << " ";
    }

    cout << endl;
}

/**
 * @brief Дружественная функция для вывода закрытых данных.
 * @tparam T Тип координат.
 * @tparam Dimensions Количество измерений.
 * @param cloud Облако точек.
 */
template <typename T, int Dimensions>
void showCloud(const PointCloud<T, Dimensions>& cloud) {

    cout << "Облако точек:" << endl;

    for (int i = 0; i < cloud.points.size(); i++) {
        cout << "Точка " << i + 1 << ": ";

        for (int j = 0; j < Dimensions; j++) {
            cout << cloud.points[i][j] << " ";
        }

        cout << endl;
    }
}

/**
 * @brief Главная функция программы.
 *
 * Загружает точки из файла, вычисляет центроид,
 * выполняет векторное произведение и сохраняет результат.
 * @return Код завершения программы.
 */
int main() {

    // Настройка русского языка в консоли Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    /// Создание трёхмерного облака.
    PointCloud<double, 3> cloud;

    /// Открытие файла с исходными данными.
    ifstream file("points.txt");

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    double x, y, z;

    /// Чтение точек из файла.
    while (file >> x >> y >> z) {
        cloud.addPoint({x, y, z});
    }

    file.close();

    cout << "Количество загруженных точек: "
         << cloud.getSize() << endl;

    /// Вывод всех точек.
    showCloud(cloud);

    /// Вычисление центроида.
    printCentroid(cloud);

    /// Вычисление векторного произведения.
    if (cloud.getSize() >= 2) {
        auto result = cloud.crossProduct(
            cloud.getPoint(0),
            cloud.getPoint(1)
        );

        cout << "Векторное произведение: ";

        for (int i = 0; i < 3; i++) {
            cout << result[i] << " ";
        }

        cout << endl;
    }

    cout << "Всего точек: "
         << PointCloud<double, 3>::getTotalPoints()
         << endl;

    /// Создание двумерного облака.
    PointCloud<int, 2> cloud2D;

    cloud2D.addPoint({2, 4});
    cloud2D.addPoint({6, 8});

    /// Проверка специализации функции.
    printCentroid(cloud2D);

    /// Сохранение точек в файл.
    ofstream output("result.txt");

    for (int i = 0; i < cloud.getSize(); i++) {
        auto point = cloud.getPoint(i);

        output << point[0] << " "
               << point[1] << " "
               << point[2] << endl;
    }

    output.close();

    cout << "Результаты сохранены в result.tx" << endl;
    return 0;
}



