#include "Human.h"

Human::Human(string fio, string login, string password):FIO(fio),login(login),password(password)
{
}

string Human::getFIO()
{
	return this->FIO;
}

string Human::getLogin()
{
	return this->login;
}

void Human::changeLogin(string newLogin)
{
	this->login = newLogin;
}

Human::~Human()
{
}
