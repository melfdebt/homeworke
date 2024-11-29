#pragma once
#include <map>
#include "Base.h"
template <typename T>
class Child1 : public Base<T>
{
protected:
	T value3;
	T value4;
public:
	Child1(T value1, T val2, T val3, T val4);
};

template<typename T>
inline Child1<T>::Child1(T value1, T val2, T val3, T val4): Base(value1,val2),value3(val3),value4(val4)
{
}
