#include <iostream>
using namespace std;

struct SafeArray {
    int* data;
    int size;
};

SafeArray createArray(int  size) {
    SafeArray arr;
    arr.data = new int[size];
    arr.size = size;
    return arr;
}

int& getElement(SafeArray& arr, int index) {
    if(index < 0 || index >= arr.size) {
        cout << "Error" << endl;
        static int error = 0;
        return error;
    }
    return arr.data[index];
}

void printSafe(const SafeArray& arr) {
    for(int i = 0; i < arr.size; i++) {
    cout << arr.data[i] << " ";
    }
}

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

int main() {
    SafeArray myArr = createArray(5);
    getElement(myArr, 0) = 10;
    getElement(myArr, 1) = 20;
    getElement(myArr, 2) = 30;
    getElement(myArr, 3) = 40;
    getElement(myArr, 4) = 50;

    printSafe(myArr);
    cout << endl;

    reSizeArray(myArr, 3);
    cout << endl;

    printSafe(myArr);

    delete[] myArr.data;

    return 0;
}