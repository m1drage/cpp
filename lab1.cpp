#include <iostream>
using namespace std;

void fillArray(int (&arr)[10])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
}

void printArray(int (&arr)[10])
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

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

void multiplyByTwo(int(&arr)[10])
{
    cout << "Massiv = ";
    for (int& x : arr)
    {
       x = x * 2;
       cout << x << " ";
    }
    
}


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


