#include "TextFileParent.h"

TextFileParent::TextFileParent(string path): path(path)
{
}

void TextFileParent::display()
{
	fstream file(this->path);
	if (!file.is_open()) {
		cout << "unsuccesful" << endl;
		return;
	}
	else {
		string str;
		while (getline(file, str)) {
			cout << str << endl;
		}
	}
	file.close();
}
