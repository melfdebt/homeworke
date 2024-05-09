// meow.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define random (rand()%9);
using namespace std;
void init(int** arr,int row,int column) {
	for (int i = 0; i < row; i++) {
		arr[i] = new int[column];
	}
	for (int i = 0; i < row; i++)
	{
		for (int e = 0; e < column; e++)
		{
			arr[i][e] = random;
		}
	}
}

void init(int* arr, int length) {
	for (int i = 0; i < length; i++)
	{
		arr[i] = random;
	}
}
template<typename t>
void show(t** &arr){
	int row = _msize(arr) / sizeof(arr[0]);
	for (int i = 0; i < row; i++)
	{
		int column = _msize(arr[i]) / sizeof(arr[i][0]);
		for (int e = 0; e < column; e++)
		{
			cout << arr[i][e] << ' ';
		}
		cout << endl;
	}
}

template<typename t>
void show(t* arr) {
	int length = _msize(arr) / sizeof(arr[0]);
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void addArray(int**& arr, int* arr2, int rowIndex, int columnIndex) {
	int length = _msize(arr[rowIndex]) / sizeof(arr[rowIndex][0]);
	int len = _msize(arr2) / sizeof(arr2[0]);
	int* buf = new int[length+len];
	for (int i = 0; i < length+len; i++) {
		if (i < columnIndex) buf[i] = arr[rowIndex][i];
		else if (i == columnIndex or (i > columnIndex and i < columnIndex + len)) buf[i] = arr2[i - columnIndex];
		else buf[i] = arr[rowIndex][i - len];
	}
	delete[] arr[rowIndex];
	arr[rowIndex] = buf;
}
void addArray(int**& arr, int* array,int rowIndex) {
	int row = _msize(arr) / sizeof(arr[0]);
	int**buf =new int* [row + 1];
	for (int i = 0; i < row; i++)
	{
		if (i < rowIndex) buf[i] = arr[i];
		else if (i == rowIndex) buf[i] = array;
		else buf[i] = arr[i - 1];
	}
	delete[] arr;
	arr = buf;
}
void deleteArray(int**& arr, int rowIndex) {
	int row = _msize(arr) / sizeof(arr[0]);
	int** buf = new int* [row - 1];
	for (int i = 0; i < row; i++)
	{
		if (i < rowIndex)buf[i] = arr[i];
		else if (i == rowIndex)continue;
		else buf[i - 1] = arr[i];
	}
	delete[] arr[rowIndex];
	delete[] arr;
	arr = buf;
}

void addElem(int** &arr,int elem,int rowIndex,int columnIndex) {
	int length = _msize(arr[rowIndex]) / sizeof(arr[rowIndex][0]);
	int* buf = new int[length +1];
	for (int i = 0; i < length; i++) {
		if (i < columnIndex) buf[i] = arr[rowIndex][i];
		else if (i == columnIndex) buf[i] = elem;
		else buf[i] = arr[rowIndex][i - 1];
	}
	delete[] arr[rowIndex];
	arr[rowIndex] = buf;
}
void deleteElem(int**& arr, int rowIndex, int columnIndex) {
	int length = _msize(arr[rowIndex]) / sizeof(arr[rowIndex][0]);
	int* buf = new int[length - 1];
	for (int i = 0; i < length; i++)
	{
		if (i < columnIndex) buf[i] = arr[rowIndex][i];
		else if (i == columnIndex)continue;
		else buf[i - 1] = arr[rowIndex][i];
	}
	delete[] arr[rowIndex];
	arr[rowIndex] = buf;
}
void delElemByNum(int**& arr, int elem) {
	int row= _msize(arr) / sizeof(arr[0]);
	int rowIndex = -1;
	int columnIndex = -1;
	for (int i = 0; i < row; i++) {
		int column = _msize(arr[i]) / sizeof(arr[i][0]);
		for (int e = 0; e < column; e++)
		{
			if (arr[i][e] == elem) {
				rowIndex = i;
				columnIndex = e;
			}
		}
	}
	if (rowIndex > -1) deleteElem(arr, rowIndex, columnIndex);
	else return;
}
int main()
{
	int row, column;
	cin >> row >> column;
	int** array = new int* [row];
	init(array,row,column);
	show(array);
	
}
