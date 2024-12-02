#include "Group.h"

Group::Group(string faculty, string name, Student** students,int quant): faculty(faculty),name(name),students(students),quant(quant)
{

}

Group::~Group()
{
	for (int i = 0; i < quant; i++) {
		delete[] students[i];
	}
	delete[]students;
}

void Group::addStudent(Student* st)
{
	Student** buf=new Student*[quant+1];
	for (int i = 0; i < quant; i++) {
		buf[i] = students[i];
	}
	buf[quant] = st;
	delete[]students;
	students = buf;
	quant++;

}

void Group::deleteStudent(string name)
{
	if (findSt(name) != -1) {
		Student** buf = new Student * [quant - 1];
		for (int i = 0; i < findSt(name); i++) {
			buf[i] = students[i];
		}
		for (int i = findSt(name) + 1; i < quant; i++) {
			buf[i - 1] = students[i];
		}
		delete[]students;
		students = buf;
		quant--;
	}
}

int Group::findSt(string name)
{
	
	for (int i = 0; i < quant; i++) {
		if (students[i]->getFIO() == name) {
			return i;
		}
	}
	return -1;
}

Student** Group::getStudents()
{
	return students;
}

string Group::getName()
{
	return name;
}

Student* Group::getStudent(string name)
{
	for (int i = 0; i < quant; i++) {
		if (students[i]->getFIO() == name) {
			return students[i];
		}
	}
	return nullptr;
}

void Group::showStudents()
{
	for (int i = 0; i < quant; i++) {
		cout <<i<<". "<< students[i]->getFIO() << endl;
	}
}

