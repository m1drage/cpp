#include <iostream>
using namespace std;

/**
 * @brief Обрабатывает динамический массив.
 *
 * Находит первый отрицательный элемент,
 * удаляет его и все последующие элементы.
 * Размер массива изменяется.
 *
 * @param arr Ссылка на указатель динамического массива.
 * @param size Ссылка на размер массива.
 */

void process(int*& arr, int& size)
{
    for(int i{}; i < size; i++)
    {
        if(arr[i] < 0)
        {
            int* arr1 = new int[i]{};
            for(int d{}; d < i; d++)
            {
                arr1[d] = arr[d]; 
            }
            delete[] arr;
            arr = arr1;
            size = i;

            return;
        }
        
    }
}

/**
 * @brief Главная функция программы.
 *
 * Считывает размер и элементы динамического массива,
 * вызывает функцию обработки и выводит результат.
 * После завершения освобождает выделенную память.
 *
 * @return 0 Если программа завершилась успешно.
 */

int main()
{
    int N;
    cin >> N;

    int* arr = new int[N]{};

    for(int i{}; i < N; i++)
    cin >> arr[i];
    
    process(arr, N);
    for (int i{}; i < N; i++)
    cout << arr[i] << " ";

    delete[] arr;
    arr = nullptr;

    cout << "\narr = " << arr << endl;
    
    return 0;
}