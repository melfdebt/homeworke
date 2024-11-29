#include "TextFileChild1.h"

TextFileChild1::TextFileChild1(string path): TextFileParent(path)
{
}

void TextFileChild1::display()
{
	fstream file(this->path);
	if (!file.is_open()) {
		cout << "unsuccesful" << endl;
		return;
	}
	else {
		string str;
		while (getline(file, str)) {
			for (char it : str) {
				cout << int(it) << ' ';
			}
			cout << endl;
		}
	}
	file.close();
}
