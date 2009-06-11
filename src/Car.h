/**
 * @file Car.h
 * Car 클래스의 선언
 *
 * @author walker(jeonyb@gmail.com)
 */
#ifndef _Car_H
#define _Car_H

#include "Object.h"
#include "XYPair.h"
#include "CarTrait.h"
#include "EastCCW.h"

/**
 * @brief 차
 */
class Car : public Object
{
	public:
		const CarTrait trait;

		EastCCW bodyHeading;

		/**
		 * @brief 앞바퀴 각도
		 * @details 양수이면 우회전각, 음수이면 좌회전각
		 */
		float wheelAngle;
		bool  reverseDriving;

		XYPair<float> location;
		XYPair<float> velocity;

		Car(const CarTrait& aTrait);
		virtual ~Car();

		/**
		 * @brief x,y축의 가속도를 구한다.
		 */
		XYPair<float> getAcceleration();
};

#endif /* _Car_H */
