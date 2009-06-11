/**
 * @file EastCCW.cpp
 * EastCCW 클래스 구현
 *
 * @author walker(jeonyb@gmail.com)
 */
#include <math.h>
#include <stdio.h>

#include "NSEW.h"
#include "EastCCW.h"
#include "PolarCW.h"

EastCCW::EastCCW()
: value(0)
{
}

EastCCW::EastCCW(const EastCCW& eccw)
: value(eccw.value)
{
}

EastCCW::EastCCW(const float aValue)
: value(aValue)
{
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
}

EastCCW::EastCCW(const NSEW& nsew)
: value(nsew.getEastCCWInt())
{
}

EastCCW::EastCCW(const PolarCW& pcw)
{
	value = pcw.getValue() * -1  - 90;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
}

EastCCW::~EastCCW()
{
}

float EastCCW::getValue() const
{
	return value;
}

float EastCCW::getRadian() const
{
	return value * M_PI /180;
}

const EastCCW EastCCW::operator!() const
{
	return EastCCW(value + 180);
}

bool EastCCW::operator==(const EastCCW& eccw) const
{
	return value == eccw.value;
}

bool EastCCW::operator!=(const EastCCW& eccw) const
{
	return value != eccw.value;
}

EastCCW& EastCCW::operator=(const float aValue)
{
	value = aValue;
	return *this;
}

EastCCW& EastCCW::operator=(const EastCCW& eccw)
{
	value = eccw.value;
	return *this;
}

EastCCW& EastCCW::operator+=(const EastCCW& eccw)
{
	value += eccw.value;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

EastCCW& EastCCW::operator+=(const float aValue)
{
	value += aValue;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

EastCCW& EastCCW::operator-=(const EastCCW& eccw)
{
	value -= eccw.value;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

EastCCW& EastCCW::operator-=(const float aValue)
{
	value -= aValue;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

EastCCW& EastCCW::operator*=(const float aValue)
{
	value *= aValue;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

EastCCW& EastCCW::operator*=(const EastCCW& eccw)
{
	value *= eccw.value;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

EastCCW& EastCCW::operator/=(const float aValue)
{
	value /= aValue;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

EastCCW& EastCCW::operator/=(const EastCCW& eccw)
{
	value /= eccw.value;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

EastCCW& EastCCW::operator<<=(const float aValue)
{
	value += aValue;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

EastCCW& EastCCW::operator<<=(const EastCCW& eccw)
{
	value += eccw.value;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

EastCCW& EastCCW::operator>>=(const float aValue)
{
	value -= aValue;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

EastCCW& EastCCW::operator>>=(const EastCCW& eccw)
{
	value -= eccw.value;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

const EastCCW EastCCW::operator+(const EastCCW& eccw) const
{
	return EastCCW(value + eccw.value);
}

const EastCCW EastCCW::operator-(const EastCCW& eccw) const
{
	return EastCCW(value - eccw.value);
}

/* override */
const std::string EastCCW::toString() const
{
	static char buf[32] = "";
	snprintf(buf, 32, "EastCCW(%.0f)", value);
	return buf;
}

const EastCCW operator+(const EastCCW& eccw, const float value)
{
	return EastCCW(eccw.getValue() + value);
}

const EastCCW operator+(const float value, const EastCCW& eccw)
{
	return EastCCW(value + eccw.getValue());
}

const EastCCW operator-(const EastCCW& eccw, const float value)
{
	return EastCCW(eccw.getValue() - value);
}

const EastCCW operator-(const float value, const EastCCW& eccw)
{
	return EastCCW(value - eccw.getValue());
}

const EastCCW operator*(const EastCCW& eccw, const float value)
{
	return EastCCW(eccw.getValue() * value);
}

const EastCCW operator*(const float value, const EastCCW& eccw)
{
	return EastCCW(value * eccw.getValue());
}
const EastCCW operator/(const EastCCW& eccw, const float value)
{
	return EastCCW(eccw.getValue() / value);
}

const EastCCW operator/(const float value, const EastCCW& eccw)
{
	return EastCCW(value / eccw.getValue());
}

const EastCCW operator<<(const EastCCW& eccw, const float value)
{
	return EastCCW(eccw.getValue() + value);
}

const EastCCW operator<<(const float value, const EastCCW& eccw)
{
	return EastCCW(value + eccw.getValue());
}

const EastCCW operator>>(const EastCCW& eccw, const float value)
{
	return EastCCW(eccw.getValue() - value);
}

const EastCCW operator>>(const float value, const EastCCW& eccw)
{
	return EastCCW(value - eccw.getValue());
}
