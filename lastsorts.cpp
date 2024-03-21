// roksberg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int array[10],min=1,max=10;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        array[i] = min + rand() % (max - min + 1);
        cout << array[i] << " "; 
    }
    cout << endl;

    //bubble sort
    //bool flag = true;
    //for (int i = 0; i < 10; i++) {
    //    for (int e = 0; e < 10 -1- i; e++) {
    //        if (array[e] > array[e + 1]) {
    //            swap(array[e], array[e + 1]);
    //            flag = false;
    //        }
    //    }
    //    if (flag)break;
    //}
    //cout<<"bubble sort" << endl;
    //for (int i = 0; i < 10; i++)cout << array[i] << " ";
    // 
    // 
    // 
    // 
    ////selection sort
    //for (int i = 0; i < 10; i++) {
    //    max = 0;
    //    for (int e = 0; e < 10 - i - 1; e++) {
    //        if (array[max] < array[e])max = e;
    //    }
    //    if (array[max] > array[10 - 1 - i])swap(array[max], array[10 - 1 - i]);
    //}
    //cout << "selection sort" << endl;
    //for (int i = 0; i < 10; i++)cout << array[i] << " ";


    //shake sort
    //bool flag = true;
    //for (int i = 0; i < 10/2; i++) {
    //    for (int e = 0; e < 10-i-1; e++) {
    //        if (array[e] > array[e + 1]) {
    //            swap(array[e], array[e + 1]);
    //            flag = false;
    //        }
    //    }
    //    for (int f = 10 -i-1; f !=0 ; f--) {
    //        if (array[f] < array[f - 1]) swap(array[f], array[f - 1]);
    //    }
    //    if (flag)break;
    //}
    //for (int i = 0; i < 10; i++) cout << array[i] << " ";
    // 
    // 
    // 
    //вставками sort
    //int buf;
    //for (int i = 1;i< 10; i++) {
    //    if (array[i] < array[i - 1]) {
    //        buf = array[i];
    //        for (int j = i;j>=0; j--) {
    //            if (array[j - 1] > buf) {
    //                array[j] = array[j - 1];
    //            }
    //            else {
    //                array[j] = buf;
    //                break;
    //            }
    //        }
    //    }
    //}
    //for (int i = 0; i < 10; i++) cout << array[i] << " ";

    // count sort 
    int arr[10]{};
    for (int i = 0; i < 10; i++) {
        arr[array[i]-min]++;
    }
    for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
    cout << endl;
    int a = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] > 0) {
            for (int f = 0; f < arr[i]; f++) {
                array[a] = i+min;
                for (int e = 0; e < 10; e++) cout << array[e] << " ";
                cout << endl;
                a++;
            }
        }
        else continue;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) cout << array[i] << ' ';
}



