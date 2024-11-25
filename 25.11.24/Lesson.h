#pragma once
#include "Teacher.h"
#include "Group.h"
#include <Time.h>
#include <string.h>
using namespace std;
class Lesson
{
private:
	Teacher* teacher;
	Group* group;
	string subject;
	time_t time;
	time_t timeEnd;
public:
	Lesson(Teacher* teacher, Group* group, string subject, time_t time1, time_t time2);
};
