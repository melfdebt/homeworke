#include "MarkList.h"

void MarkList::addMark(int mark)
{
	int size = _msize(marks) / sizeof(marks[0]);
	int* buf = new int[size + 1];
	for (int i = 0; i < size; i++) {
		buf[i] = marks[i];
	}
	buf[size] = mark;
	delete[] marks;
	marks = buf;
}

MarkList::MarkList(string subject):subject(subject)
{
	this->marks = new int[0];
	exam = 0;
}

void MarkList::setExam(int exam)
{
	this->exam = exam;
}

void MarkList::show()
{
	cout << subject << endl;
	int size = _msize(marks) / sizeof(marks[0]);
	for (int i = 0; i < size; i++) {
		cout << marks[i] << ' ';
	}
	cout << endl << "Exam: " << exam << endl;
}

int MarkList::getExam()
{
	return exam;
}
