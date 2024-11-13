#include "Flat.h"

Flat::Flat()
{
}

Flat::Flat(Flat& flat)
{
	this->flatNumber = flat.flatNumber;
	this->maxsize = flat.maxsize;
	this->size = flat.size;
	this->humans = new Human[this->size];
	for (int i = 0; i < this->size; i++) {
		this->humans[i] = flat.humans[i];
	}
}

Flat::Flat(int num, int size, int msize, float v): flatNumber(num), size(size),maxsize(msize), v(v)
{
	this->humans = new Human[this->size];
}

Flat::~Flat()
{
	delete[] this->humans;
}

void Flat::addHuman(Human& human)
{
	Human* buf = new Human[this->size+1];
	for (int i = 0; i < this->size; i++) {
		buf[i] = this->humans[i];
	}
	buf[this->size] = human;
	this->size++;
	delete[] this->humans;
	this->humans = buf;
}

void Flat::printInfo()
{
	cout << "Flat number: " << flatNumber << endl;
	cout << " volume: " << v << ' ' << "max humans: " << maxsize << endl;
	cout << "live now: " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << i+1 << ". ";
		humans[i].printInfo();
	}
}


