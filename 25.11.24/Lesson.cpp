#include "Lesson.h"



Lesson::Lesson(Teacher* teacher, Group* group, string subject, time_t time1, time_t time2):teacher(teacher),group(group), subject(subject),time(time1),timeEnd(time2)
{
}

Group* Lesson::getGroup()
{
	return this->group;
}

Teacher* Lesson::getTeacher()
{
	return this->teacher;
}

string Lesson::getSubject()
{
	return this->subject;
}

pair<time_t, time_t> Lesson::getTime()
{
	return pair<time_t, time_t>(time,timeEnd);
}

void Lesson::setTeacher(Teacher* teach)
{
	delete[] this->teacher;
	this->teacher = teach;
}

void Lesson::setTime(time_t time1, time_t time2)
{
	this->time = time1;
	this->timeEnd = time2;
}
