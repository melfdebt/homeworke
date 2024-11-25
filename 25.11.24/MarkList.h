#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class MarkList
{
private:
	string subject;
	int* marks;
	int exam;
	void addMark(int mark);
public:
	MarkList(string subject);
	void setExam(int exam);
	void show();
	int getExam();

};

