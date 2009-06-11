/**
 * @file XYPair.cpp
 * XYPair 클래스의 구현
 *
 * @author walker(jeonyb@gmail.com)
 */

#include "XYPair.h"

template<typename T>
XYPair<T>::XYPair()
: x(0), y(0)
{
}

template<typename T>
XYPair<T>::XYPair(const T aX, const T aY)
: x(aX), y(aY)
{
}

template<typename T>
XYPair<T>::XYPair(const XYPair<T>& pair)
: x(pair.x), y(pair.y)
{
}

template<typename T>
XYPair<T>::~XYPair()
{
}

template<typename T>
XYPair<T>& XYPair<T>::operator= (const T value)
{
	x = value;
	y = value;
	return *this;
}

template<typename T>
XYPair<T>& XYPair<T>::operator= (const XYPair<T>& pair)
{
	x = pair.x;
	y = pair.y;
	return *this;
}

template<typename T>
XYPair<T>& XYPair<T>::operator+= (const T value)
{
	x += value;
	y += value;
	return *this;
}

template<typename T>
XYPair<T>& XYPair<T>::operator+= (const XYPair<T>& pair)
{
	x += pair.x;
	y += pair.y;
	return *this;
}

template<typename T>
XYPair<T>& XYPair<T>::operator-= (const T value)
{
	x -= value;
	y -= value;
	return *this;
}

template<typename T>
XYPair<T>& XYPair<T>::operator-= (const XYPair<T>& pair)
{
	x -= pair.x;
	y -= pair.y;
	return *this;
}

template<typename T>
XYPair<T>& XYPair<T>::operator*= (const T value)
{
	x *= value;
	y *= value;
	return *this;
}

template<typename T>
XYPair<T>& XYPair<T>::operator*= (const XYPair<T>& pair)
{
	x *= pair.x;
	y *= pair.y;
	return *this;
}

template<typename T>
XYPair<T>& XYPair<T>::operator/= (const T value)
{
	x /= value;
	y /= value;
	return *this;
}

template<typename T>
XYPair<T>& XYPair<T>::operator/= (const XYPair<T>& pair)
{
	x /= pair.x;
	y /= pair.y;
	return *this;
}

template<typename T>
const XYPair<T> XYPair<T>::operator+(const XYPair<T>& pair)
{
	return XYPair<T>(x + pair.x, y + pair.y);
}

template<typename T>
const XYPair<T> XYPair<T>::operator-(const XYPair<T>& pair)
{
	return XYPair<T>(x - pair.x, y - pair.y);
}

template<typename T>
const XYPair<T> XYPair<T>::operator*(const XYPair<T>& pair)
{
	return XYPair<T>(x * pair.x, y * pair.y);
}

template<typename T>
const XYPair<T> XYPair<T>::operator/(const XYPair<T>& pair)
{
	return XYPair<T>(x / pair.x, y / pair.y);
}

template<typename T>
const XYPair<T> operator+(const XYPair<T>& pair, int value)
{
	return XYPair<T>(pair.x + value, pair.y + value);
}

template<typename T>
const XYPair<T> operator+(int value, const XYPair<T>& pair)
{
	return XYPair<T>(pair.x + value, pair.y + value);
}

template<typename T>
const XYPair<T> operator-(const XYPair<T>& pair, int value)
{
	return XYPair<T>(pair.x - value, pair.y - value);
}

template<typename T>
const XYPair<T> operator-(int value, const XYPair<T>& pair)
{
	return XYPair<T>(value - pair.x, value - pair.y);
}

template<typename T>
const XYPair<T> operator*(const XYPair<T>& pair, int value)
{
	return XYPair<T>(pair.x * value, pair.y * value);
}

template<typename T>
const XYPair<T> operator*(int value, const XYPair<T>& pair)
{
	return XYPair<T>(value * pair.x, value * pair.y);
}

template<typename T>
const XYPair<T> operator/(const XYPair<T>& pair, int value)
{
	return XYPair<T>(pair.x / value, pair.y / value);
}

template<typename T>
const XYPair<T> operator/(int value, const XYPair<T>& pair)
{
	return XYPair<T>(value / pair.x, value / pair.y);
}

