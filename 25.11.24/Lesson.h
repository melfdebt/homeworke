#pragma once
#include "Teacher.h"
#include "Group.h"
#include <Time.h>
#include <string.h>
#include <map>
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
	Group* getGroup();
	Teacher* getTeacher();
	string getSubject();
	pair<time_t, time_t> getTime();
	void setTeacher(Teacher* teach);
	void setTime(time_t time1, time_t time2);
};
