/**
 * @file Car.cpp
 * Car 클래스의 구현
 *
 * @author walker(jeonyb@gmail.com)
 */
#include <math.h>

#include "Car.h"

Car::Car(const CarTrait& aTrait)
: trait(aTrait)
, bodyHeading(0)
, wheelAngle(0)
, reverseDriving(false)
, location(0.0f, 0.0f)
, velocity(0.0f, 0.0f)
{
}

Car::~Car()
{
}

XYPair<float> Car::getAcceleration()
{
	const float f = reverseDriving ? trait.f_reverse : trait.f_advance;
	const EastCCW wheelHeading = bodyHeading >> wheelAngle;
/*
	printf("f_advance:%.4f\n", trait.f_advance);
	printf("f        :%.4f\n", f);
	printf("wh       :%.4f\n", wheelHeading.getValue());
	printf("fx       :%.4f\n", f * cos(wheelHeading.getRadian()));
	printf("fy       :%.4f\n", f * sin(wheelHeading.getRadian()));
*/
	return XYPair<float>(f * cos(wheelHeading.getRadian()),
	                     f * sin(wheelHeading.getRadian()));
}
