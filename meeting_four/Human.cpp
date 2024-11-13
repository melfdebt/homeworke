#include "Human.h"

Human::Human()
{
}

Human::Human(const Human& human)
{
	this->pasport.seria = human.pasport.seria;
	this->pasport.number = human.pasport.number;
	this->pasport.date = human.pasport.date;
	this->name = human.name;
	this->surname = human.surname;
	this->secondName = human.secondName;
	this->age = human.age;
}

Human::Human(string seria, string number, string date, string name, string surname, string secondName, int age)
	: name(name),surname(surname),secondName(secondName),age(age)
{
	Pasport pasport{ seria,number,date };
	this->pasport = pasport;
}

Human::~Human()
{
}

void Human::printInfo()
{
	cout << name << ' ' << surname << ' ' << secondName << endl;
	cout << "age: " << age << endl;
	cout << "pasport info: " << pasport.seria << ' ' << pasport.number << ' ' << pasport.date << endl;
}

void Human::changeAge(int newAge)
{
	this->age = newAge;
}

void Human::ChangePasport(Pasport& pasport)
{
	this->pasport = pasport;
}
