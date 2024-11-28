#include "Reservior.h"

Reservior::Reservior()
{
}

Reservior::Reservior(string name, string type, float hmax, float wigth, float length):
	name(name),type(type),hmax(hmax),wigth(wigth),length(length)
{
}

float Reservior::getV()
{
	return this->hmax*this->length*this->wigth;
}

float Reservior::getS()
{
	return this->wigth*this->length;
}

bool Reservior::checkType(Reservior r2)
{
	return (this->type == r2.getType());
}

string Reservior::getType()
{
	return this->type;
}

string Reservior::getname()
{
	return this->name;
}

bool Reservior::checkS(Reservior r2)
{
	if (checkType(r2)) {
		return (this->getS() == r2.getS());
	}
	return false;
}

Reservior Reservior::copy()
{
	Reservior rc(this->name, this->type, this->hmax, this->wigth, this->length);
	return rc;
}

void Reservior::setName(string name)
{
	this->name = name;
}

void Reservior::setType(string type)
{
	this->type = type;
}

void Reservior::setH(float h)
{
	this->hmax = h;
}

void Reservior::setWigth(float w)
{
	this->wigth = w;
}

void Reservior::setLength(float l)
{
	this->length = l;
}
