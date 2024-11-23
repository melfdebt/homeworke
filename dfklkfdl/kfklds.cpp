// kfklds.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;



template <typename T>
T findMax(T* arr, int size) {
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
T findMin(T* arr, int size) {
    T min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

template <typename T>
void sort(T* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
int search(T* arr, int size, T value) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        else if (arr[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

template <typename T>
void replace(T* arr, int size, T oldValue, T newValue) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == oldValue) {
            arr[i] = newValue;
        }
    }
}

int main() {
    int* arr =new int[6] { 5, 3, 8, 1, 7, 2 };
    int size = 6;

    cout <<  findMax(arr, size) << endl;
    cout << findMin(arr, size) << endl;

    sort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout<< search(arr, size, 7);
    

    replace(arr, size, 8, 10);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


}




