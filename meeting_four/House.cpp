#include "House.h"

House::House()
{
}

House::House(House& house)
{
	this->houseNum = house.houseNum;
	this->numFlats = house.numFlats;
	this->flats = new Flat[house.numFlats];
	for (int i = 0; i < house.numFlats; i++) {
		this->flats[i] = house.flats[i];
	}

}

House::House(int size, int num, Flat*& flats) : houseNum(num), numFlats(size)
{
	this->flats = new Flat[size];
	for (int i = 0; i < size; i++)
	{
		this->flats[i] = flats[i];
	}
}

House::~House()
{
	delete[] flats;
}

void House::printInfo()
{
	cout << "house number: " << houseNum << " number of flats: " << numFlats << endl;
	for (int i = 0; i < numFlats; i++)
	{
		cout << i+1 << ". ";
		flats[i].printInfo();
	}
}

