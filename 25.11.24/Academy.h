#pragma once
#include "Teacher.h"
#include "Group.h"
#include "Schedule.h"
class Academy//abstruct
{
protected:
	Teacher* teachers;
	Group* groups;
	Schedule schedule;
};

