#pragma once
#include "Pet.h"
class Dog :
    public Pet
{
private:
    string brid, colour;
    float barking;
public:
    Dog(string name, string brid, string colour, float bark);
};

