/**
 * @file PolarCW.cpp
 * PolarCW 클래스 구현
 *
 * @author walker(jeonyb@gmail.com)
 */
#include <stdio.h>

#include "NSEW.h"
#include "PolarCW.h"
#include "EastCCW.h"

PolarCW::PolarCW()
: value(0)
{
}

PolarCW::PolarCW(const PolarCW& pcw)
: value(pcw.value)
{
}

PolarCW::PolarCW(const float aValue)
: value(aValue)
{
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
}

PolarCW::PolarCW(const NSEW& nsew)
: value(nsew.getPolarCWInt())
{
}

PolarCW::PolarCW(const EastCCW& eccw)
{
	value = eccw.getValue() * -1  + 90;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
}

PolarCW::~PolarCW()
{
}

float PolarCW::getValue() const
{
	return value;
}

const PolarCW PolarCW::operator!() const
{
	return PolarCW(value + 180);
}

bool PolarCW::operator==(const PolarCW& pcw) const
{
	return value == pcw.value;
}

bool PolarCW::operator!=(const PolarCW& pcw) const
{
	return value != pcw.value;
}

PolarCW& PolarCW::operator=(const float aValue)
{
	value = aValue;
	return *this;
}

PolarCW& PolarCW::operator=(const PolarCW& pcw)
{
	value = pcw.value;
	return *this;
}

PolarCW& PolarCW::operator+=(const PolarCW& pcw)
{
	value += pcw.value;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

PolarCW& PolarCW::operator+=(const float aValue)
{
	value += aValue;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

PolarCW& PolarCW::operator-=(const PolarCW& pcw)
{
	value -= pcw.value;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

PolarCW& PolarCW::operator-=(const float aValue)
{
	value -= aValue;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

PolarCW& PolarCW::operator*=(const float aValue)
{
	value *= aValue;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

PolarCW& PolarCW::operator*=(const PolarCW& pcw)
{
	value *= pcw.value;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

PolarCW& PolarCW::operator/=(const float aValue)
{
	value /= aValue;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

PolarCW& PolarCW::operator/=(const PolarCW& pcw)
{
	value /= pcw.value;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

PolarCW& PolarCW::operator<<=(const float aValue)
{
	value -= aValue;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

PolarCW& PolarCW::operator<<=(const PolarCW& eccw)
{
	value -= eccw.value;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

PolarCW& PolarCW::operator>>=(const float aValue)
{
	value += aValue;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

PolarCW& PolarCW::operator>>=(const PolarCW& eccw)
{
	value += eccw.value;
	while(value < 0) value += 360;
	while(value >= 360) value -= 360;
	return *this;
}

const PolarCW PolarCW::operator+(const PolarCW& pcw) const
{
	return PolarCW(value + pcw.value);
}

const PolarCW PolarCW::operator-(const PolarCW& pcw) const
{
	return PolarCW(value - pcw.value);
}

/* override */
const std::string PolarCW::toString() const
{
	static char buf[32] = "";
	snprintf(buf, 32, "PolarCW(%.0f)", value);
	return buf;
}

const PolarCW operator+(const PolarCW& pcw, const float value)
{
	return PolarCW(pcw.getValue() + value);
}

const PolarCW operator+(const float value, const PolarCW& pcw)
{
	return PolarCW(value + pcw.getValue());
}

const PolarCW operator-(const PolarCW& pcw, const float value)
{
	return PolarCW(pcw.getValue() - value);
}

const PolarCW operator-(const float value, const PolarCW& pcw)
{
	return PolarCW(value - pcw.getValue());
}

const PolarCW operator*(const PolarCW& pcw, const float value)
{
	return PolarCW(pcw.getValue() * value);
}

const PolarCW operator*(const float value, const PolarCW& pcw)
{
	return PolarCW(value * pcw.getValue());
}

const PolarCW operator/(const PolarCW& pcw, const float value)
{
	return PolarCW(pcw.getValue() / value);
}

const PolarCW operator/(const float value, const PolarCW& pcw)
{
	return PolarCW(value / pcw.getValue());
}

const PolarCW operator<<(const PolarCW& eccw, const float value)
{
	return PolarCW(eccw.getValue() - value);
}

const PolarCW operator<<(const float value, const PolarCW& eccw)
{
	return PolarCW(value - eccw.getValue());
}

const PolarCW operator>>(const PolarCW& eccw, const float value)
{
	return PolarCW(eccw.getValue() + value);
}

const PolarCW operator>>(const float value, const PolarCW& eccw)
{
	return PolarCW(value + eccw.getValue());
}

