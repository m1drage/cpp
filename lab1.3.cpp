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

int main() {
    SafeArray myArr = createArray(5);
    cout << myArr.size << endl;

    getElement(myArr, 2) = 999;
    cout << getElement(myArr, 2) << endl;

    printSafe(myArr);

    return 0;
}