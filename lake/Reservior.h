#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Reservior
{
private:
	string name,type;
	float hmax, wigth, length;
public:
	Reservior();
	Reservior(string name, string type, float hmax, float wigth, float length);
	float getV();
	float getS();
	bool checkType(Reservior r2);
	string getType();
	string getname();
	bool checkS(Reservior r2);
	Reservior copy();
	void setName(string name);
	void setType(string type);
	void setH(float h);
	void setWigth(float w);
	void setLength(float l);
};
