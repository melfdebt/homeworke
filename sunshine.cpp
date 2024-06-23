// sunshine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#define random(min,max) min+rand()%(max-min+1)
using namespace std;

struct Student{
    string name;
    float avg;
};

void showStudents(Student* students, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << "name: " << students[i].name << endl;
        cout << "avg: " << students[i].avg << endl;
        cout << endl;
    }
}

void addStudent(Student*& studs, int &size, string name, float avg) {
    Student* buf = new Student[size + 1];
    for (int i = 0; i < size; i++)
    {
        buf[i] = studs[i];
    }
    buf[size] = Student{ name,avg };
    delete[] studs;
    studs = buf;
    size++;
}

void deleteStudent(Student*& studs, int& size, string name) {
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (studs[i].name == name) index = i;
    }
    if (index == -1) {
        cout << "not exist" << endl;
        return;
    }
    else {
        Student* buf = new Student[size - 1];
        for (int i = 0; i < size; i++)
        {
            if (i < index) buf[i] = studs[i];
            else if (index == i) continue;
            else buf[i - 1] = studs[i];
        }
        delete[] studs;
        studs = buf;
        size--;
    }
}


void initArray(int*& array,int size) {
    for (int i = 0; i < size; i++) {
        array[i] = random(0, 9);
    }
}


void initArray(int**& array, int row,int column) {
    for (int i = 0; i < row; i++)
    {
        for (int e = 0; e < column; e++)
        {
            array[i][e] = random(0, 9);
        }
    }
}

template<typename t>
void showArray(t* array,int size) {
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }cout << endl;
}

void showArray(int** array, int row, int column) {
    for (int i = 0; i < row; i++)
    {
        for (int e = 0; e < column; e++)
        {
            cout << array[i][e] << " ";
        }
        cout << endl;
    }
}

int addElems(int* array,int size) {//сложение элементов одномерного массива
    int count=0;
    for (int i = 0; i < size; i++)
    {
        count += array[i];
    }
    return count;
}

int addElems(int** array, int row, int column) {//сложение элементов матрицы
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int e = 0; e < column; e++)
        {
            count += array[i][e];
        }
    }
    return count;
}

int max(int* array,int size) {//нахождение максимального элемента одн-ого массива
    int index;
    for (int i = 1; i < size; i++)
    {
        if (array[i] > array[i - 1]) index = i;
    }
    return index;
}
template<typename t>
void sort(t*& array, int size) {//сортировка массива типа инт и чар
    for (int i = 0; i < size; i++) {
        bool flag = true;
        for (int e = 1; e < size; e++) {
            if (array[e] < array[e - 1]) {
                swap(array[e], array[e - 1]);
                flag = false;
            }
        }
        if (flag) break;
    }
}


void transporting(int**& array, int row, int col) {
    for (int i = 0; i < row; i++)
    {
        for (int e = i; e < col; e++)
        {
            swap(array[i][e], array[e][i]);
        }
    }
}

int** multiplyMatr(int** arr1, int** arr2) {//умножение матриц
    int row2 = _msize(arr2) / sizeof(arr2[0]);
    int column1 = _msize(arr1[0]) / sizeof(arr1[0][0]);
    if (row2 == column1) {
        int row1 = _msize(arr1) / sizeof(arr1[0]);
        int column2 = _msize(arr2[0]) / sizeof(arr2[0][0]);
        int** array = new int* [row1];
        for (int i = 0; i < row1; i++)
        {
            array[i] = new int[column2];
        }
        for (int i = 0; i < row1; i++) {
            for (int e = 0; e < column2; e++) {
                array[i][e] = 0;
                for (int f = 0; f < row2; f++) {
                    array[i][e] += arr1[i][f] * arr2[f][i];
                }
            }
        }
        return array;
    }
    else {
        return 0;
    }
}

struct Point {
    int x;
    int y;
};

Point getPoint(int** array,int num) {//получение координат элемента в матрице
    Point p;
    int row = _msize(array) / sizeof(array[0]);
    for (int i = 0; i < row; i++) {
        int column = _msize(array[i]) / sizeof(array[i][0]);
        for (int e = 0; e < column; e++)
        {
            if (array[i][e] == num) {
                p = { i,e };
                return p;
            }
        }
    }
    return p = { -1,-1 };
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int size = 10;
    int* array = new int[size];
    initArray(array, size);
    showArray(array, size);
    sort(array, size);
    showArray(array, size);

    char* arrayStr = new char[size] {'t','r','w','a','f','h','q','e','j','x'};
    showArray(arrayStr, size);
    sort(arrayStr, size);
    showArray(arrayStr, size);

    Student stu1{ "Adrey",3.45 };
    int length = 1;
    Student* students = new Student[1]{ stu1 };
    showStudents(students, 1);
    addStudent(students,length, "Lucie", 4.92);
    showStudents(students, length);
    deleteStudent(students, length, "Adrey");
    showStudents(students, length);

    int** arr1 = new int* [3];
    for (int i = 0; i < 3; i++) arr1[i] = new int[2] {i+1,i+1};
    int** arr2 = new int* [2];
    for (int i = 0; i < 2; i++)arr2[i] = new int[3] {i+1,i+1,i+1};
    int** array1 = multiplyMatr(arr1, arr2);
    showArray(array1, 3, 3);
    cout << getPoint(array1, 6).x<<" "<<getPoint(array1,6).y;
    

}
