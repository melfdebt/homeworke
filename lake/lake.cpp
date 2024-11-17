// lake.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include "Reservior.h"
using namespace std;

void addReser(Reservior r,Reservior*& rs, int size) {
    Reservior* buf = new Reservior[size + 1];
    for (int i = 0; i < size; i++) {
        buf[i] = rs[i];
    }
    buf[size] = r;
    delete[]rs;
    rs = buf;
    size++;
}

int findR(string name, Reservior*& rs, int size) {
    for (int i = 0; i < size; i++) {
        if (rs[i].getname() == name)return i;
    }
    return -1;
}

void deleteName(string name, Reservior*& rs, int size) {
    int index = findR(name, rs, size);
    if (index != -1) {
        Reservior* buf = new Reservior[size - 1];
        for (int i = 0; i < index; i++) {
            buf[i] = rs[i];
        }
        for (int i = index + 1; i < size; i++) {
            buf[i - 1] = rs[i];
        }
        delete[]rs;
        rs = buf;
        size--;
    }
}

int main()
{
    Reservior r1("Baikal", "lake", 621.223, 344.54, 232.43);
    Reservior r2;
    r2 = r1.copy();
    int size = 2;
    Reservior* rs = new Reservior[size]{ r1,r2 };
}
