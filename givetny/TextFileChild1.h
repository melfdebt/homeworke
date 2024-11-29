#pragma once
#include "TextFileParent.h"
class TextFileChild1 :
    public TextFileParent
{
public:
    TextFileChild1(string path);
    virtual void display();
};

