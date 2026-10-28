#include <iostream>
#include <cmath>
using namespace std;

class Vector3D {
private:
    double x, y, z;
    mutable int calls;          // Счетчик обращений
    static int count;           // Количество созданных векторов

public:
    // 1. Три конструктора
    explicit Vector3D(double a) : x(a), y(0), z(0), calls(0) {
        count++;
    }

    Vector3D(double a, double b, double c)
        : x(a), y(b), z(c), calls(0) {
        count++;
    }

    Vector3D() : x(0), y(0), z(0), calls(0) {
        count++;
    }

    // Деструктор
    ~Vector3D() {
        count--;
        cout << "Vector destroyed\n";
    }

    // Длина вектора
    double length() const {
        calls++;
        return sqrt(x * x + y * y + z * z);
    }

    // Вывод вектора
    void print() const {
        cout << "(" << x << ", " << y << ", " << z << ")\n";
    }

    // Унарные операторы: изменение на 1% длины
    Vector3D& operator++() {
        double k = 1.01;
        x *= k;
        y *= k;
        z *= k;
        return *this;
    }

    Vector3D operator++(int) {
        Vector3D temp = *this;
        ++(*this);
        return temp;
    }

    Vector3D& operator--() {
        x /= 1.01;
        y /= 1.01;
        z /= 1.01;
        return *this;
    }

    Vector3D operator--(int) {
        Vector3D temp = *this;
        --(*this);
        return temp;
    }

    // Арифметическое присваивание
    Vector3D& operator+=(const Vector3D& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3D& operator-=(const Vector3D& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vector3D& operator*=(double n) {
        x *= n;
        y *= n;
        z *= n;
        return *this;
    }

    Vector3D& operator/=(double n) {
        if (n != 0) {
            x /= n;
            y /= n;
            z /= n;
        }
        return *this;
    }

