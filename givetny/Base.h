#pragma once
#include <map>
using namespace std;
template <typename T>
class Base
{
protected:
	T value1, value2;
private:
	Base(T value1, T value2);
	pair<T,T> getValue();
	void setValue(T val1, T val2);
};

template<typename T>
inline pair<T, T> Base<T>::getValue()
{
	return pair <T,T > (value1,value2);
}

template<typename T>
inline void Base<T>::setValue(T val1, T val2)
{
	this->value1 = val1;
	this->value2 = val2;
}
