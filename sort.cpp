// roksberg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    //bubble sort
    int array[10],min=1,max=10;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        array[i] = min + rand() % (max - min + 1);
        cout << array[i] << " "; 
    }
    cout << endl;
    bool flag = true;
    for (int i = 0; i < 10; i++) {
        for (int e = 0; e < 10 -1- i; e++) {
            if (array[e] > array[e + 1]) {
                swap(array[e], array[e + 1]);
                flag = false;
            }
        }
        if (flag)break;
    }
    cout<<"bubble sort" << endl;
    for (int i = 0; i < 10; i++)cout << array[i] << " ";
    //selection sort
    for (int i = 0; i < 10; i++) {
        max = 0;
        for (int e = 0; e < 10 - i - 1; e++) {
            if (array[max] < array[e])max = e;
        }
        if (array[max] > array[10 - 1 - i])swap(array[max], array[10 - 1 - i]);
    }
    cout << "selection sort" << endl;
    for (int i = 0; i < 10; i++)cout << array[i] << " ";
}



