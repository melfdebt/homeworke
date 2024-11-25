// melfdebt.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include <map>
#include <fstream>
#include <string.h>
#include<Windows.h>
#include <string>

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	ifstream in("r-e.txt");
	string str, rstr;
	map<string, string> m;
	if (!in.is_open()) {
		return - 1;
	}
	while (getline(in, str, ':')) {
		getline(in, rstr);
		m.insert(pair<string, string>(str, rstr));
	}
	for (pair<string, string> i : m) {
		cout << i.first << ' ' << i.second << endl;
	}
	in.close();
	fstream file("russian.txt", ios::app);
	fstream filee("english.txt");
	if (!file.is_open()) {
		return -1;
	}
	while (getline(filee, str,' ')) {
		cout << str << endl;
		cout << m[str] << endl; //cjjksdjlsdjdjdjkdjkdjkddjk
		file << m[str] << ' ';
	}
	file.close();
	filee.close();
	
}
