/**
 * @file NSEW.cpp
 * NSEW 클래스 구현
 *
 * @author walker(jeonyb@gmail.com)
 */
#include <stdexcept>

#include "NSEW.h"

NSEW::NSEW(VALUE aValue)
: value(aValue)
{
}

NSEW::~NSEW()
{
}

NSEW::NSEW(const NSEW& nsew)
{
	value = nsew.value;
}

const char NSEW::STR_NORTH[] = "NORTH";
const char NSEW::STR_EAST[] = "EAST";
const char NSEW::STR_SOUTH[] = "SOUTH";
const char NSEW::STR_WEST[] = "WEST";

const NSEW NSEW::NORTH = NSEW(VALUE_NORTH);
const NSEW NSEW::EAST = NSEW(VALUE_EAST);
const NSEW NSEW::SOUTH = NSEW(VALUE_SOUTH);
const NSEW NSEW::WEST = NSEW(VALUE_WEST);

NSEW::VALUE NSEW::getValue() const
{
	return value;
}

int NSEW::getEastCCWInt() const
{
	switch(value) {
		case VALUE_NORTH: return 90;
		case VALUE_EAST: return 0;
		case VALUE_SOUTH: return 270;
		case VALUE_WEST: default: return 180;
	}
}

int NSEW::getPolarCWInt() const
{
	switch(value) {
		case VALUE_NORTH: return 0;
		case VALUE_EAST: return 90;
		case VALUE_SOUTH: return 180;
		case VALUE_WEST: default: return 270;
	}
}

const NSEW NSEW::operator!() const
{
	switch(value) {
		case VALUE_NORTH: return SOUTH;
		case VALUE_EAST: return WEST;
		case VALUE_SOUTH: return NORTH;
		case VALUE_WEST: default: return EAST;
	}
}

bool NSEW::operator==(const NSEW& nsew) const
{
	return value == nsew.value;
}

bool NSEW::operator!=(const NSEW& nsew) const
{
	return value != nsew.value;
}

NSEW& NSEW::operator=(const NSEW& nsew)
{
	value = nsew.value;
	return *this;
}

NSEW& NSEW::operator+=(int aValue)
{
	if(aValue < 0) {
		return (*this) -= -aValue;
	} else  {
		while(aValue-- > 0) ++(*this);
		return *this;
	}
}

NSEW& NSEW::operator-=(int aValue)
{
	if(aValue < 0) {
		return (*this) += -aValue;
	} else  {
		while(aValue-- > 0) --(*this);
		return *this;
	}
}

NSEW& NSEW::operator>>=(int aValue)
{
	if(aValue < 0) {
		return (*this) <<= -aValue;
	} else  {
		while(aValue-- > 0) ++(*this);
		return *this;
	}
}

NSEW& NSEW::operator<<=(int aValue)
{
	if(aValue < 0) {
		return (*this) >>= -aValue;
	} else  {
		while(aValue-- > 0) --(*this);
		return *this;
	}
}

NSEW& NSEW::operator++()
{
	switch(value) {
		case VALUE_NORTH: value = VALUE_EAST; break;
		case VALUE_EAST: value = VALUE_SOUTH; break;
		case VALUE_SOUTH: value = VALUE_WEST; break;
		case VALUE_WEST: value = VALUE_NORTH; break;
	}
	return *this;
}

NSEW& NSEW::operator--()
{
	switch(value) {
		case VALUE_NORTH: value = VALUE_WEST; break;
		case VALUE_EAST: value = VALUE_NORTH; break;
		case VALUE_SOUTH: value = VALUE_EAST; break;
		case VALUE_WEST: value= VALUE_SOUTH; break;
	}
	return *this;
}

const NSEW NSEW::operator++(int)
{
	const NSEW old = *this;
	++(*this);
	return old;
}

const NSEW NSEW::operator--(int)
{
	const NSEW old = *this;
	--(*this);
	return old;
}

const std::string NSEW::toString() const
{
	switch(value) {
		case VALUE_NORTH: return STR_NORTH;
		case VALUE_EAST: return STR_EAST;
		case VALUE_SOUTH: return STR_SOUTH;
		case VALUE_WEST: return STR_WEST;
	}
}

const NSEW operator+(const NSEW& nsew, int aValue)
{
	if(aValue < 0) {
		return nsew - (-aValue);
	} else {
		NSEW r = nsew;
		while(aValue-- > 0) ++r;
		return r;
	}
}

const NSEW operator+(int aValue, const NSEW& nsew)
{
	if(aValue < 0) {
		return nsew - (-aValue);
	} else {
		NSEW r = nsew;
		while(aValue-- > 0) ++r;
		return r;
	}
}

const NSEW operator-(const NSEW& nsew, int aValue)
{
	if(aValue < 0) {
		return nsew + (-aValue);
	} else {
		NSEW r = nsew;
		while(aValue-- > 0) --r;
		return r;
	}
}

const NSEW operator>>(const NSEW& nsew, int aValue)
{
	if(aValue < 0) {
		return nsew << (-aValue);
	} else {
		NSEW r = nsew;
		while(aValue-- > 0) ++r;
		return r;
	}
}

const NSEW operator<<(const NSEW& nsew, int aValue)
{
	if(aValue < 0) {
		return nsew >> (-aValue);
	} else {
		NSEW r = nsew;
		while(aValue-- > 0) --r;
		return r;
	}
}
