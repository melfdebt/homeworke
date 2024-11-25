#pragma once
#include "Human.h"
#include "MarkList.h"
class Student :
    public Human
{
private:
    MarkList* markList;
public:
    Student(string fio, string login, string password);
    void changePassword(string newPassword);

};

