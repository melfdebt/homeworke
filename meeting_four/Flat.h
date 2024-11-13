#pragma once
#include "Human.h"
#include <iostream>
using namespace std;
class Flat
{
private:
	int maxsize;
	int size;
	Human* humans;
	int flatNumber;
	float v;
public:
	Flat();
	Flat(Flat& flat);
	Flat(int num, int size,int msize,float v);
	~Flat();
	void addHuman(Human& human);
	void printInfo();
};

