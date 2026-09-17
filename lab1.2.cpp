#include <iostream>
using namespace std;

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