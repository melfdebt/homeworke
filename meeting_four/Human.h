#pragma once
#include<iostream>
#include <string.h>
using namespace std;
struct Pasport {
	string seria, number, date;
};
class Human
{
private:
	Pasport pasport;
	string name, surname, secondName;
	int age;
public:
	Human();
	Human(const Human& human);
	Human(string seria, string number, string date, string name, string surname, string secondName, int age);
	~Human();
	void printInfo();
	void changeAge(int newAge);
	void ChangePasport(Pasport& pasport);
};

