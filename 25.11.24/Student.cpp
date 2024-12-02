#include "Student.h"

Student::Student(string fio, string login, string password): Human(fio,login,password)
{
	markLists = nullptr;
}



void Student::changePassword(string newPassword)
{
	cout << "are you sure?" << endl;
	string yesNO;
	cin >> yesNO;
	if (yesNO == "Yes") {
		this->password = newPassword;
	}
	else { return; }
}

MarkList* Student::getList(string subject)
{
	for (int i = 0; i < subjects; i++) {
		if (markLists[i]->getSubject() == subject) {
			return  markLists[i];
		}
	}
	return nullptr;
}



