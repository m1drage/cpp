#include <iostream>
using namespace std;

/**
 * @brief Заполняет массив с клавиатуры.
 *
 * Пользователь вводит 10 целых чисел,
 * которые сохраняются в массив.
 *
 * @param arr Массив из 10 элементов.
 */

void fillArray(int (&arr)[10])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
}

/**
 * @brief Выводит элементы массива на экран.
 *
 * @param arr Массив из 10 элементов.
 */

void printArray(int (&arr)[10])
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

/**
 * @brief Меняет местами два элемента массива.
 *
 * Пользователь вводит индексы двух элементов,
 * после чего их значения меняются местами.
 *
 * @param arr Массив из 10 элементов.
 */

void swapElements(int(&arr)[10]) 
{
    int index1{};
    cout << "Vvedite index 1 element = ";
    cin >> index1;
    int index2{};
    cout << "Vvedite index 2 element = ";
    cin >> index2;
    int yama{};
    yama = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = yama;
    
}

/**
 * @brief Умножает каждый элемент массива на 2.
 *
 * Изменяет значения элементов массива
 * и выводит полученный массив на экран.
 *
 * @param arr Массив из 10 элементов.
 */

void multiplyByTwo(int(&arr)[10])
{
    cout << "Massiv = ";
    for (int& x : arr)
    {
       x = x * 2;
       cout << x << " ";
    }
    
}

/**
 * @brief Главная функция программы.
 *
 * Заполняет массив, выводит его,
 * меняет местами два элемента,
 * а затем умножает все элементы на 2.
 *
 * @return 0 Если программа завершилась успешно.
 */

int main()
{
    int massiv[10];
    fillArray(massiv);
    printArray(massiv);
    swapElements(massiv);
    printArray(massiv);
    multiplyByTwo(massiv);
    return 0;
}


