#pragma once
#include <iostream>
#include "Student.h"
using namespace std;
class Group
{
private:
	Student** students;
	string name;
	string faculty;
	int quant;
public:
	Group(string faculty, string name, Student** students,int quant);
	~Group();
	void addStudent(Student* st);
	void deleteStudent(string name);
	int findSt(string name);
	Student** getStudents();
	string getName();
	Student* getStudent(string name);
	void showStudents();
};
