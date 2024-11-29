#include "TextFileChild2.h"

TextFileChild2::TextFileChild2(string path):TextFileChild1(path)
{
}

void TextFileChild2::display()
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
				cout << bitset<8>(int(it)) << ' ';
			}
			cout << endl;
		}
	}
	file.close();
}
