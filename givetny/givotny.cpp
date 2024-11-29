// givotny.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "TextFileParent.h"
#include "TextFileChild1.h"
#include "TextFileChild2.h"
#include <bitset>
using namespace std;

int main()
{
	TextFileChild2 tfile("path.txt");
	tfile.display();

}

