#include "Date.h"
#include <iostream>
using namespace std;
Date::Date(int day, int mounth, int year):day(day),mounth(mounth),year(year)
{
}

void Date::nextDay()
{
	this->day++;
	if (day == 31 and this->mounth % 2 == 0 and mounth!=2) {
		this->day = 1;
		this->mounth++;
	}
	else if (day == 32 and this->mounth % 2 == 1) {
		this->day = 1;
		this->mounth++;
	}
	else if (day == 29 and mounth == 2) {
		this->day = 1;
		this->mounth++;
	}
	if (mounth > 12) {
		mounth = 1;
		year++;
	}
}

void Date::operator++()
{
	this->year++;
}

void Date::operator--()
{
	this->year--;
}

bool Date::operator!=(Date date)
{
	return (this->day!=date.day || this->mounth!=date.mounth||this->year!=date.year);
}

bool Date::operator==(Date date)
{
	return (this->day == date.day && this->mounth == date.mounth && this->year == date.year);
}

bool Date::operator>(Date date)
{
	if (this->day > date.day && this->mounth == date.mounth && this->year == date.year) {
		return true;
	}
	else if (this->mounth > date.mounth && this->year == date.year) {
		return true;
	}
	else if (this->year > date.year) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator<(Date date)
{
	if (this->day < date.day && this->mounth == date.mounth && this->year == date.year) {
		return true;
	}
	else if (this->mounth < date.mounth && this->year == date.year) {
		return true;
	}
	else if (this->year < date.year) {
		return true;
	}
	else {
		return false;
	}
}

void Date::operator=(Date& date)
{
	this->day = date.day;
	this->mounth = date.mounth;
	this->year = date.mounth;
}

void Date::operator+=(Date& date)
{
	for (int i = 0; i < date.day; i++) {
		nextDay();
	}
	this->mounth += date.mounth;
	if (this->mounth > 12) {
		this->mounth = this->mounth - 12;
		this->year++;
	}
	this->year += date.year;
}

void Date::operator-=(Date& date)
{
	this->day -= date.day;
	if (this->day <= 0) {
		this->mounth--;
		if (this->mounth % 2 == 0 and this->mounth != 2) {
			this->day = 30 + this->day;
		}
		else if (this->mounth % 2 == 1) {
			this->day = 31 + this->day;
		}
		else if (this->mounth == 2) {
			this->day = 28 + this->day;
		}
	}
	this->mounth-=date.mounth;
	if (this->mounth <= 0) {
		this->year--;
		this->mounth = 12 + this->mounth;
	}
	this->year -= date.year;
}
void Date::operator()()
{
	cout << day << '.' << mounth << '.' << year << endl;
}