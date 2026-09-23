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

int main() {
    SafeArray myArr = createArray(5);
    cout << myArr.size << endl;

    getElement(myArr, 7) = 999;
    cout << getElement(myArr, 2) << endl;

    return 0;
}