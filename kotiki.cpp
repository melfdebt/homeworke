// kotiki.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
void show(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
void initialize(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 9;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int size;
    cin>> size;
    int* array = new int[size];
    initialize(array, size);
    show(array,size);

    //extra array
 /*   int* newAr = new int[size];
    initialize(newAr, size);
    show(newAr, size);*/


    //добавление массива в конец другого
    //int* buf = new int[size + size];
    //for (int i = 0; i < size + size; i++) {
    //    if (i < size) buf[i] = array[i];
    //    else buf[i] = newAr[i - size];
    //}
    //size += size;
    //delete[] array;
    //array = buf;
    //show(array, size);

    //добавление массива по индексу в другой массив
    //int index;
    //cin >> index;
    //int* buf = new int[size+size];
    //for (int i = 0; i < index; i++) {
    //    buf[i] = array[i];
    //}
    //for (int i = 0; i < size; i++) {
    //    buf[i+index] = newAr[i];
    //}
    //for (int i =index+size; i < size+size; i++) {
    //    buf[i] = array[i-size];
    //}
    //delete[] array;
    //array = buf;
    //size+=size;
    //show(array, size);
    

    //Удаление элемента из массива по занчению по первому вхождению
    int num;
    cin >> num;
    int index; 
    int* buf = new int[size - 1];
    for (int i = 0; i < size; i++) {
        if (array[i] == num) {
            index = i;
            break;
        }
        else index = -1;
    }
    if (index >= 0) {
        for (int i = 0; i < size; i++) {
            if (i == index) continue;
            else if (i < index)buf[i] = array[i];
            else buf[i - 1] = array[i];
            
        }
        delete[] array;
        array = buf;
        size--;
        show(array, size);
    }
    else cout << "number not found";
}


