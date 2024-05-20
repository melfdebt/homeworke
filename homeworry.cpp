// homeworry.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#define random rand()%9;
using namespace std;

int strNum(string way) {
	ifstream in(way);
	int count=0;
	if (in.is_open()) {
		string str;
		while (getline(in, str)) {
			count++;
		}
	}
	in.close();
	return count;
}

int main()
{
	int size;
	cin >> size;
	ifstream in;
	in.open("baobab.txt");
	if (in.is_open()) {
		ofstream out;
		out.open("emptyfail.txt", ios::app);
		string str;
		int len = strNum("baobab.txt");
		for (int i = 0; i < len; i++)
		{
			string str;
			getline(in, str);
			if (str.length() < size) {
				out << str << endl;
			}
		}
		out.close();
	}
}




