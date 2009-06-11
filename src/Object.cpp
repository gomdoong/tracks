/**
 * @file Object.cpp
 * Object 클래스 구현
 *
 * @author walker(jeonyb@gmail.com)
 */
#include <stdio.h>
#include <typeinfo>

#include "Object.h"

const std::string Object::toString() const
{
	char buf[256];
	snprintf(buf, sizeof(buf), "%s(%p)", typeid(*this).name(), this);
	return buf;
}
