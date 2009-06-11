/**
 * @file XYPair.h
 * XYPair 클래스의 선언
 *
 * @author walker(jeonyb@gmail.com)
 */
#ifndef _XYPair_H
#define _XYPair_H

#include <iostream>

#include "Object.h"

/**
 * @brief x, y축 값을 가지는 한쌍
 * @tparam T x, y의 타입
 */
template<typename T>
class XYPair
{
	public:
		T x;
		T y;

		XYPair();
		XYPair(const T aX, const T aY);
		XYPair(const XYPair<T>& pair);
		~XYPair();

		XYPair& operator= (const T value);
		XYPair& operator= (const XYPair& pair);
		XYPair& operator+= (const T value);
		XYPair& operator+= (const XYPair& pair);
		XYPair& operator-= (const T value);
		XYPair& operator-= (const XYPair& pair);
		XYPair& operator*= (const T value);
		XYPair& operator*= (const XYPair& pair);
		XYPair& operator/= (const T value);
		XYPair& operator/= (const XYPair& pair);

		const XYPair operator+(const XYPair& pair);
		const XYPair operator-(const XYPair& pair);
		const XYPair operator*(const XYPair& pair);
		const XYPair operator/(const XYPair& pair);
};

template<typename T>
const XYPair<T> operator+(const XYPair<T>& pair, int value);

template<typename T>
const XYPair<T> operator+(int value, const XYPair<T>& pair);

template<typename T>
const XYPair<T> operator-(const XYPair<T>& pair, int value);

template<typename T>
const XYPair<T> operator-(int value, const XYPair<T>& pair);

template<typename T>
const XYPair<T> operator*(const XYPair<T>& pair, int value);

template<typename T>
const XYPair<T> operator*(int value, const XYPair<T>& pair);

template<typename T>
const XYPair<T> operator/(const XYPair<T>& pair, int value);

template<typename T>
const XYPair<T> operator/(int value, const XYPair<T>& pair);

#include "XYPair.cpp"

#endif /* _XYPair_H */
