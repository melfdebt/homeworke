#pragma once
#include "Human.h"
#include "MarkList.h"
class Student :
    public Human
{
private:
    MarkList** markLists;
    int subjects;
public:
    Student(string fio, string login, string password);
    void changePassword(string newPassword);
    MarkList* getList(string subgect);

};

