#pragma once
#include "flat.h"
#include <iostream>
using namespace std;
class House
{
private:
	Flat* flats;
	int numFlats;
	int houseNum;
public:
	House();
	House(House& house);
	House(int size, int num, Flat*& flats);
	~House();
	void printInfo();
};

