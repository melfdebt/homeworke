// homeworry.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define random rand()%9;
using namespace std;

template<typename t>
void quicksort(t* arr, int right, int left = 0) {
	if (left > right) return;
	int swapMaker = left - 1;
	for (int i = 0; i <=right; i++)
	{
		if (arr[i] <= arr[right]) {
			swapMaker++;
			if (i > swapMaker) swap(arr[i], arr[swapMaker]);
		}
	}
	quicksort(arr, swapMaker - 1, left);
	quicksort(arr, right, swapMaker + 1);
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int size;
	cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = random;
	}
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
	quicksort(array, size);
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
}



