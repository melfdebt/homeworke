// abuabu.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int size;
    cin >> size;
    int* array = new int[size];
    cout << array << endl;
    for (int i = 0; i < size; i++) {
        array[i] = 1 + rand() % 9;
        cout << array[i] << " ";
    }
}

