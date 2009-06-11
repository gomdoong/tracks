/**
 * @file CarTrait.h
 * CarTrait 클래스의 구현
 *
 * @author walker(jeonyb@gmail.com)
 */
#include "CarTrait.h"

CarTrait::CarTrait()
: drivingSystem(FWD), m(1.0f)
, f_advance(1.0f), f_reverse(1.0f)
, u_wheel(0.9f), balance(0.5f), wheelMaxAngle(45)
{
}

CarTrait::CarTrait(const CarTrait& trait)
: drivingSystem(trait.drivingSystem)
, m(trait.m)
, f_advance(trait.f_advance)
, f_reverse(trait.f_reverse)
, u_wheel(trait.u_wheel)
, balance(trait.balance)
, wheelMaxAngle(trait.wheelMaxAngle)
{
}

CarTrait::~CarTrait()
{
}
