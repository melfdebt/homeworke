// abuabu.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
void show(int array[][3], int row, int column) {//вывод массива
    for (int i = 0; i < column; i++) {
        for (int e = 0; e < row; e++) {
            cout << array[i][e] << " ";
        }
        cout << endl;
    }
}
void show( char array[][3], int row, int column) {
    for (int i = 0; i < column; i++) {
        for (int e = 0; e < row; e++) {
            cout << array[i][e] << " ";
        }
        cout << endl;
    }
}
void show(double array[][3], int row, int column) {
    for (int i = 0; i < column; i++) {
        for (int e = 0; e < row; e++) {
            cout << array[i][e] << " ";
        }
        cout << endl;
    }
}
template<typename T>
T max(T array[][3], int row, int column) {//поиск максимального элемента
    T maximum = 0;
    for (int i = 0; i < row; i++) {
        if (array[i][i] > maximum)maximum = array[i][i];
    }
    return maximum;
}
template<typename T>
T min(T array[][3], int row, int column) {//поиск минимального элемента
    T minimum = array[0][0];
    for (int i = 0; i < row; i++) {
        if (array[i][i] < minimum)minimum = array[i][i];
    }
    return minimum;
}
template<typename T> // поиск минимального и максимального
void maxAndMin(T array[][3], int row, int column) {
    T min = array[0][0], max = array[0][0];
    for (int i = 1; i < column; i++) {
        if (array[i][i] < min)min = array[i][i];
        if (array[i][i] > max)max = array[i][i];
    }
    cout << max << " " << min << endl;
}

 void sort(int array[][3], int row, int column) {//сортировка построчно 
    for (int i = 0; i < column; i++) {
        for (int e = 0; e < row; e++) {
            bool flag = true;
            for (int g = 1; g < row; g++) {
                if (array[i][g] < array[i][g - 1]) {
                    swap(array[i][g], array[i][g - 1]);
                    flag = false;
                }                 
            }
            if (flag)break;
        }        
    }
}
 void sort(double array[][3], int row, int column) {
    for (int i = 0; i < column; i++) {
        for (int e = 0; e < row; e++) {
            bool flag = true;
            for (int g = 1; g < row; g++) {
                if (array[i][g] < array[i][g - 1]) {
                    swap(array[i][g], array[i][g - 1]);
                    flag = false;
                }                 
            }
            if (flag)break;
        }        
    }
}
 void sort(char array[][3], int row, int column) {
    for (int i = 0; i < column; i++) {
        for (int e = 0; e < row; e++) {
            bool flag = true;
            for (int g = 1; g < row; g++) {
                if (array[i][g] < array[i][g - 1]) {
                    swap(array[i][g], array[i][g - 1]);
                    flag = false;
                }                 
            }
            if (flag)break;
        }        
    }
}


 void matr(int array[][3], int row, int column) {//инициализация массивов
    for (int i = 0; i < column; i++) {
        for (int e = 0; e < row; e++) {
            array[i][e] = rand() % 10;
        }
    }
}
 void matr(char array[][3], int row, int column) {
    for (int i = 0; i < column; i++) {
        for (int e = 0; e < row; e++) {
            array[i][e] = 65+rand() % 26;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    const int row = 3, column = 3;
    int array[column][row];
    matr(array, row, column);
    show(array, row, column);
    maxAndMin(array, row, column);
    cout << max(array, row, column)<<" "<<min(array,row,column)<<endl;
    sort(array, row, column);
    show(array, row, column);
    cout<<max(array, row, column)<<" "<<min(array,row,column)<<endl;
    //минимальное и максимальное в одну не получиломь потому что 2 значения не возвращает
    // но я еще через void сделаль
}

