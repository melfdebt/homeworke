#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Human
{
protected:
	string FIO;
	string login;
	string password;
public:
	Human(string fio,string login,string password);
	string getFIO();
	string getLogin();
	virtual void changePassword(string newPassword)=0;
	void changeLogin(string newLogin);
	virtual ~Human();
};

