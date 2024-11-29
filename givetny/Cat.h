#pragma once
#include "Pet.h"
class Cat :
    public Pet
{
private:
    string eyes, brid;
    float elegancy;
    float naglost;
public:
    Cat(string name, string eyes, string brid, float ele, float nagl);
    ~Cat();
};

