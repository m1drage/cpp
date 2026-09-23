#include <iostream>
using namespace std;

/**
 * @brief Безопасный динамический массив.
 *
 * Содержит указатель на данные массива и его текущий размер.
 */
struct SafeArray {
    int* data;
    int size;
};

/**
 * @brief Создаёт динамический массив.
 *
 * Выделяет память для заданного количества элементов.
 *
 * @param size Размер создаваемого массива.
 * @return SafeArray Созданный массив.
 */
SafeArray createArray(int  size) {
    SafeArray arr;
    arr.data = new int[size];
    arr.size = size;
    return arr;
}

/**
 * @brief Возвращает элемент массива по индексу.
 *
 * Проверяет, находится ли индекс в допустимых пределах. При ошибочном индексе выводит сообщение об ошибке.
 *
 * @param arr Массив, с которым выполняется работа.
 * @param index Индекс нужного элемента.
 * @return int& Ссылка на элемент массива.
 */
int& getElement(SafeArray& arr, int index) {
    if(index < 0 || index >= arr.size) {
        cout << "Error" << endl;
        static int error = 0;
        return error;
    }
    return arr.data[index];
}

/**
 * @brief Выводит элементы массива на экран.
 *
 * @param arr Массив, элементы которого необходимо вывести.
 */
void printSafe(const SafeArray& arr) {
    for(int i = 0; i < arr.size; i++) {
    cout << arr.data[i] << " ";
    }
}

/**
 * @brief Изменяет размер динамического массива.
 *
 * При уменьшении размера сохраняются первые элементы массива.
 * При увеличении создаётся новый массив большего размера.
 *
 * @param arr Массив, размер которого изменяется.
 * @param M Новый размер массива.
 */
void reSizeArray(SafeArray& arr, int M) {
    int* newData = new int[M]{};
     for (int i = 0; i < M && i < arr.size; i++) {
        newData[i] = arr.data[i];
     }
     if (M < arr.size) {
        for(int i = M; i < arr.size; i++) {
            cout << arr.data[i] << " ";
        }
     }
     delete[] arr.data;
     arr.data = newData;
     arr.size = M;
}

/**
 * @brief Главная функция программы.
 *
 * Создаёт безопасный динамический массив, изменяет его элементы, выводит содержимое и проверяет изменение размера массива.
 *
 * @return 0 Если программа завершилась успешно.
 */
int main() {
    SafeArray myArr = createArray(5);

    for(int i = 0; i < myArr.size; i++) {
        myArr.data[i] = (i + 1) * 10;
    }

    getElement(myArr, 2) = 999;

    cout << "Massiv: ";
    printSafe(myArr);
    cout << endl;

    cout << "GetElement: ";
    cout << getElement(myArr, 2) << endl;

    cout << "Delete elements: ";
    reSizeArray(myArr, 3);
    cout << endl;

    cout << "After the reduction : ";
    printSafe(myArr);
    cout << endl;

    reSizeArray(myArr, 5);

    cout << "After the increase: ";
    printSafe(myArr);
    cout << endl;

    delete[] myArr.data;
    return 0;
}