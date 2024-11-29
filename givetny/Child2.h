#pragma once
#include "Child1.h"
template <typename T>
class Child2 :
    public Child1<T>
{
private:
    T value5;
    T value6;
public:
    Child2(T val1, T val2, T val3, T val4, T val5, T val6);
};

template<typename T>
inline Child2<T>::Child2(T val1, T val2, T val3, T val4, T val5, T val6): Child1(val1,val2,val3,val4),value5(val5),value6(val6)
{
}
