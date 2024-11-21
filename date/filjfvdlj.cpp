// filjfvdlj.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include "Overcoat.h"
using namespace std;

int main()
{
    Overcoat o1("kjfs", "palto", 9.23);
    Overcoat o2;
    o2 = o1;
    cout << o2.getName();
}

