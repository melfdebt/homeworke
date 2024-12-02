#include "Academy.h"

int Academy::findGroupIndex(string name)
{
	for (int i = 0; i < groupsQuant; i++) {
		if (groups[i].getName() == name) {
			return i;
		}
	}
	return -1;
}

Academy::Academy(Teacher* teachers, Group* groups, Schedule* schedule) : teachers(teachers), groups(groups), schedule(schedule)
{
}

Academy::~Academy()
{
	delete[] teachers;
	delete[]schedule;
	delete[]groups;
}

Teacher* Academy::getTeachers()
{
	return teachers;
}

Group* Academy::getGroups()
{
	return groups;
}

Schedule* Academy::getSchedule()
{
	return schedule;
}

void Academy::changeSchedule(Schedule* newSched)
{
	delete[]schedule;
	schedule = newSched;
}

void Academy::deleteGroup(string name)
{
	if (findGroupIndex(name)!=-1){
		Group* buf;
		for (int i = 0; i < findGroupIndex(name); i++) {
			buf[i] = groups[i];
		}
		for (int i = findGroupIndex(name) + 1; i < groupsQuant; i++) {
			buf[i - 1] = groups[i];
		}
		delete[] groups;
		groups = buf;
		groupsQuant++;
	}
}
