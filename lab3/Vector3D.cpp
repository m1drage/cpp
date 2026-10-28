#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Класс трёхмерного вектора.
 * Поддерживает арифметические операции и сравнение векторов.
 */
class Vector3D {
private:
    double x, y, z;
    mutable int calls;  ///< Счётчик обращений к длине
    static int count;   ///< Количество объектов

public:
    /** @brief Создаёт вектор с одной координатой. */
    explicit Vector3D(double a) : x(a), y(0), z(0), calls(0) {
        count++;
    }

    /** @brief Создаёт вектор с тремя координатами. */
    Vector3D(double a, double b, double c)
        : x(a), y(b), z(c), calls(0) {
        count++;
    }

    /** @brief Создаёт нулевой вектор. */
    Vector3D() : x(0), y(0), z(0), calls(0) {
        count++;
    }

    /** @brief Уничтожает объект и уменьшает счётчик. */
    ~Vector3D() {
        count--;
        cout << "Vector destroyed\n";
    }

    /** @brief Вычисляет длину вектора. */
    double length() const {
        calls++;
        return sqrt(x * x + y * y + z * z);
    }

    /** @brief Выводит координаты вектора. */
    void print() const {
        cout << "(" << x << ", " << y << ", " << z << ")\n";
    }

    /** @brief Увеличивает координаты на 1% (префикс). */
    Vector3D& operator++() {
        double k = 1.01;
        x *= k;
        y *= k;
        z *= k;
        return *this;
    }

    /** @brief Увеличивает координаты на 1% (постфикс). */
    Vector3D operator++(int) {
        Vector3D temp = *this;
        ++(*this);
        return temp;
    }

    /** @brief Уменьшает координаты на 1% (префикс). */
    Vector3D& operator--() {
        x /= 1.01;
        y /= 1.01;
        z /= 1.01;
        return *this;
    }

    /** @brief Уменьшает координаты на 1% (постфикс). */
    Vector3D operator--(int) {
        Vector3D temp = *this;
        --(*this);
        return temp;
    }

    /** @brief Прибавляет другой вектор. */
    Vector3D& operator+=(const Vector3D& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    /** @brief Вычитает другой вектор. */
    Vector3D& operator-=(const Vector3D& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    /** @brief Умножает координаты на число. */
    Vector3D& operator*=(double n) {
        x *= n;
        y *= n;
        z *= n;
        return *this;
    }

    /** @brief Делит координаты на число. */
    Vector3D& operator/=(double n) {
        if (n != 0) {
            x /= n;
            y /= n;
            z /= n;
        }
        return *this;
    }

    /** @brief Складывает два вектора. */
    friend Vector3D operator+(Vector3D a, const Vector3D& b) {
        a += b;
        return a;
    }

    /** @brief Вычитает два вектора. */
    friend Vector3D operator-(Vector3D a, const Vector3D& b) {
        a -= b;
        return a;
    }

    /** @brief Умножает вектор на число. */
    friend Vector3D operator*(Vector3D a, double n) {
        a *= n;
        return a;
    }

    /** @brief Умножает число на вектор. */
    friend Vector3D operator*(double n, Vector3D a) {
        a *= n;
        return a;
    }

    /** @brief Делит вектор на число. */
    friend Vector3D operator/(Vector3D a, double n) {
        a /= n;
        return a;
    }

    /** @brief Сравнивает длины векторов. */
    bool operator<(const Vector3D& v) const {
        return length() < v.length();
    }

    /** @brief Сравнивает длины векторов. */
    bool operator>(const Vector3D& v) const {
        return length() > v.length();
    }

    /** @brief Проверяет, меньше ли или равна длина. */
    bool operator<=(const Vector3D& v) const {
        return length() <= v.length();
    }

    /** @brief Проверяет, больше ли или равна длина. */
    bool operator>=(const Vector3D& v) const {
        return length() >= v.length();
    }

    /** @brief Проверяет равенство длин векторов. */
    bool operator==(const Vector3D& v) const {
        return length() == v.length();
    }

    /** @brief Проверяет неравенство длин векторов. */
    bool operator!=(const Vector3D& v) const {
        return !(*this == v);
    }

    /** @brief Возвращает количество существующих объектов. */
    static int getCount() {
        return count;
    }

    /** @brief Возвращает количество вызовов length(). */
    int getCalls() const {
        return calls;
    }
};

/** @brief Инициализация счётчика объектов. */
int Vector3D::count = 0;

/**
 * @brief Главная функция программы.
 * Демонстрирует работу класса Vector3D и его операторов.
 * @return 0 при успешном завершении.
 */
int main() {
    Vector3D a(3, 4, 0);
    Vector3D b(1, 2, 3);
    Vector3D c;

    cout << "Vector a: ";
    a.print();

    cout << "Vector b: ";
    b.print();

    // Унарные операторы
    cout << "\nPrefix ++: ";
    (++a).print();

    cout << "Postfix ++: ";
    (a++).print();

    cout << "Prefix --: ";
    (--a).print();

    cout << "Postfix --: ";
    (a--).print();

    // Арифметические операторы
    cout << "\nAddition: ";
    (a + b).print();

    cout << "Subtraction: ";
    (a - b).print();

    cout << "Multiplication by 2: ";
    (a * 2).print();

    cout << "Division by 2: ";
    (a / 2).print();

    // Операторы присваивания
    c = a;
    c += b;
    cout << "\n+= : ";
    c.print();

    c -= b;
    cout << "-= : ";
    c.print();

    c *= 2;
    cout << "*= : ";
    c.print();

    c /= 2;
    cout << "/= : ";
    c.print();

    // Операторы сравнения
    cout << "\na < b: " << (a < b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a >= b: " << (a >= b) << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;

    // Проверка explicit
    // Vector3D v = 5; // Ошибка: explicit запрещает преобразование
    Vector3D v(5);
    cout << "\nExplicit constructor: ";
    v.print();

    // Проверка mutable
    const Vector3D fixed(3, 4, 0);
    cout << "\nLength: " << fixed.length() << endl;
    cout << "Length calls: " << fixed.getCalls() << endl;

    // Количество созданных векторов
    cout << "\nCreated vectors: " << Vector3D::getCount() << endl;

    return 0;
}



