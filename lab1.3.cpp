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

int main() {
    SafeArray myArr = createArray(5);
    cout << myArr.size << endl;


    return 0;
}