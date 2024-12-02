#pragma once
#include "Human.h"
#include "Group.h"

class Teacher :
    public Human
{
private:
    int quant;
public:
    Teacher(string fio, string login, string password);
    void changePassword(string newPassword);
};


