#pragma once
#include "TextFileChild1.h"
#include <bitset>
class TextFileChild2 :
    public TextFileChild1
{
public:
    TextFileChild2(string path);
    void display();
};

