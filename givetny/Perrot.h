#pragma once
#include "Pet.h"
class Perrot :
    public Pet
{
private:
    int perya;
    string brid;
    float scream;
public:
    Perrot(string name, string brid, int per, float scream);
};

