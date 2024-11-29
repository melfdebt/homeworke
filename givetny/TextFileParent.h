#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

class TextFileParent
{
protected:
	string path;
public:
	TextFileParent(string path);
	virtual void display();
};

