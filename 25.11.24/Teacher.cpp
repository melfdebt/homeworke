#include "Teacher.h"

Teacher::Teacher(string fio, string login, string password): Human(fio,login,password)
{
}

void Teacher::changePassword(string newPassword)
{
	this->password = newPassword;
}
