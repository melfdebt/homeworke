#pragma once
#include <iostream>
class Date
{
private:
	int day, mounth, year;
public:
	Date(int day, int mounth, int year);
	void nextDay();
	void operator++();
	void operator--();
	bool operator!=(Date date);
	bool operator==(Date date);
	bool operator>(Date date);
	bool operator<(Date date);
	void operator=(Date& date);
	void operator+=(Date& date);
	void operator-=(Date& date);
	void operator()();
};
//++, -- ,
//!= , == , > , <, >> , << , =, +=, -=, ().
