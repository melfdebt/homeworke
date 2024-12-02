#pragma once
#include "Teacher.h"
#include "Group.h"
#include "Schedule.h"
class Academy//abstruct
{
protected:
	Teacher* teachers;
	Group* groups;
	Schedule* schedule;
	int teachersQuant;
	int groupsQuant;
	int groupsQuant;
	int findGroupIndex(string name);
public:
	Academy(Teacher* teachers, Group* groups, Schedule* schedule);
	~Academy();
	Teacher* getTeachers();
	Group* getGroups();
	Schedule* getSchedule();
	void changeSchedule(Schedule* newSched);
	void deleteGroup(string name);
	Group* findGroup(string name);
	Teacher* findTeacher(string fio);
	void deleteTeacher(string name);
	void addTeacher(Teacher* teacher);
	void addGroup(Group* group);
};

