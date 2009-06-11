/**
 * @file Track.cpp
 * Track 클래스 구현
 *
 * @author walker(jeonyb@gmail.com)
 */
#include "NSEW.h"
#include "Track.h"

Track::Track(int aRotation)
: rotation(aRotation)
{
}

Track::~Track()
{
}

void Track::setRotation(int rotation)
{
	this->rotation = rotation;
}

int Track::getRotation() const
{
	return rotation;
}

void Track::turnRight()
{
	(++rotation) %= 4;
}

void Track::turnLeft()
{
	rotation = (rotation + 3) % 4;
}

bool Track::allowsEntranceFrom(const NSEW& from) const
{
	return _allowsEntranceFrom(from - rotation);
}

const NSEW Track::getExit(const NSEW& from) const
{
	return _getExit(from - rotation) + rotation;
}
