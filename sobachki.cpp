// sobachki.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int size, elem,index;
	cin >> size;
	srand(time(NULL));
	int** array = new int*[size];
	for (int i = 0; i < size; i++) {
		array[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int e = 0; e < size; e++) {
			array[i][e] = rand() % 9;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int e = 0; e < size; e++) {
			cout << array[i][e] << ' ';
		}
		cout << endl;
	}

	//Добавление элемента в конец массива по индексу.
	cout << endl;
	cin >> elem >> index;
	int** buf = new int* [size];
	for (int i = 0; i < size; i++) {
		if (i == index) buf[i] = new int[size + 1];
		else buf[i] = array[i];
	}
	for (int i = 0; i < size; i++) {
		for (int e = 0; e < size; e++) {
			buf[i][e] = array[i][e];
		}
		if (i == index)buf[index][size] = elem;
	}
	delete[] array;
	array = buf;

	//Вывод ступенчатого массива.
	for (int i=0; i < size; i++) {
		int len = (_msize(array[i]) / sizeof(array[i][i]));
		for (int e = 0; e < len; e++) {
			cout << array[i][e] << ' ';
		}
		cout << endl;
	}
	cout << endl;


}


