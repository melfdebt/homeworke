// meeting_four.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "House.h"
#include "Flat.h"
#include "Human.h"
#include <string.h>
using namespace std;

int main()
{
	Human human("923423", "8344", "12.34.56", "andrey", "chesnok", "jkdsdj", 18);
	Human human1(human);
	Human human2("938394", "3434", "12.34.21", "gosha", "krash", "jkds", 99);
	Human human3(human2);
	Flat flat(13, 0, 4, 100);
	Flat flat2(14, 0, 45, 9893);
	flat.addHuman(human);
	flat.addHuman(human1);
	flat2.addHuman(human2);
	flat2.addHuman(human3);
	Flat flat1(flat);
	Flat* flats = new Flat[2]{ flat,flat2 };
	House house(2, 34, flats);
	house.printInfo();
}
