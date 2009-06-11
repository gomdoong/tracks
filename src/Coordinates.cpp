/**
 * @file Coordinates.cpp
 * Coordinates 클래스의 구현
 *
 * @author walker(jeonyb@gmail.com)
 */
#include <stdexcept>

#include "Coordinates.h"

Coordinates::Coordinates(const float aWidth, const float aHeight,
                         const float aX, const float aY)
: XYPair<float>(aX, aY), width(aWidth), height(aHeight)
{
}

Coordinates::Coordinates(const Coordinates& c)
: XYPair<float>(c.x, c.y), width(c.width), height(c.height)
{
}

Coordinates::~Coordinates()
{
}

Coordinates& Coordinates::setX(float x)
{
	if(x < 0 || x >= width) {
		throw std::out_of_range("x");
	}
	this->x = x;
	return *this;
}

Coordinates& Coordinates::setY(float y)
{
	if(y < 0 || y >= width) {
		throw std::out_of_range("y");
	}
	this->y = y;
	return *this;
}

Coordinates& Coordinates::addX(float x)
{
	this->x += x;

	if(this->x < 0) this->x = 0;
	else if(this->x > width - 0.001) this->x = width - 0.001;

	return *this;
}

Coordinates& Coordinates::addY(float y)
{
	this->y += y;

	if(this->y < 0) this->y = 0;
	else if(this->y > height - 0.001) this->y = height - 0.001;

	return *this;
}

