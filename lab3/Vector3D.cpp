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

    // Бинарные операторы через операторы присваивания
    friend Vector3D operator+(Vector3D a, const Vector3D& b) {
        a += b;
        return a;
    }

    friend Vector3D operator-(Vector3D a, const Vector3D& b) {
        a -= b;
        return a;
    }

    friend Vector3D operator*(Vector3D a, double n) {
        a *= n;
        return a;
    }

    friend Vector3D operator*(double n, Vector3D a) {
        a *= n;
        return a;
    }

    friend Vector3D operator/(Vector3D a, double n) {
        a /= n;
        return a;
    }

    // Сравнение длин векторов
    bool operator<(const Vector3D& v) const {
        return length() < v.length();
    }

    bool operator>(const Vector3D& v) const {
        return length() > v.length();
    }

    bool operator<=(const Vector3D& v) const {
        return length() <= v.length();
    }

    bool operator>=(const Vector3D& v) const {
        return length() >= v.length();
    }

    bool operator==(const Vector3D& v) const {
        return length() == v.length();
    }

    bool operator!=(const Vector3D& v) const {
        return !(*this == v);
    }

    // Статический метод для подсчета векторов
    static int getCount() {
        return count;
    }

    // Демонстрация mutable
    int getCalls() const {
        return calls;
    }
    // Бинарные операторы через операторы присваивания
    friend Vector3D operator+(Vector3D a, const Vector3D& b) {
        a += b;
        return a;
    }

    friend Vector3D operator-(Vector3D a, const Vector3D& b) {
        a -= b;
        return a;
    }

    friend Vector3D operator*(Vector3D a, double n) {
        a *= n;
        return a;
    }

    friend Vector3D operator*(double n, Vector3D a) {
        a *= n;
        return a;
    }

    friend Vector3D operator/(Vector3D a, double n) {
        a /= n;
        return a;
    }

    // Сравнение длин векторов
    bool operator<(const Vector3D& v) const {
        return length() < v.length();
    }

    bool operator>(const Vector3D& v) const {
        return length() > v.length();
    }

    bool operator<=(const Vector3D& v) const {
        return length() <= v.length();
    }

    bool operator>=(const Vector3D& v) const {
        return length() >= v.length();
    }

    bool operator==(const Vector3D& v) const {
        return length() == v.length();
    }

    bool operator!=(const Vector3D& v) const {
        return !(*this == v);
    }

    // Статический метод для подсчета векторов
    static int getCount() {
        return count;
    }

    // Демонстрация mutable
    int getCalls() const {
        return calls;
    }
};

// Инициализация статического поля
int Vector3D::count = 0;

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
    // Vector3D v = 5; /Ошибка: explicit запрещает преобразование
    Vector3D v(5);
    cout << "\nExplicit constructor: ";
    v.print();

    // Проверка mutable в const-объекте
    const Vector3D fixed(3, 4, 0);
    cout << "\nLength: " << fixed.length() << endl;
    cout << "Length calls: " << fixed.getCalls() << endl;

    // Количество созданных векторов
    cout << "\nCreated vectors: " << Vector3D::getCount() << endl;

    return 0;
}
