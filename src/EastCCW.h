/**
 * @file EastCCW.h
 * EastCCW 클래스 선언
 *
 * @author walker(jeonyb@gmail.com)
 */
#ifndef _EastCCW_H
#define _EastCCW_H

#include "Object.h"

class NSEW;
class PolarCW;

/**
 * @brief 동쪽을 기준으로 시계반대방향으로 쟀을 때의 각도
 */
class EastCCW : public Object
{
	private:
		float value;

	public:
		EastCCW();
		EastCCW(const EastCCW& eccw);
		explicit EastCCW(const float value);
		explicit EastCCW(const NSEW& nsew);
		explicit EastCCW(const PolarCW& pcw);

		virtual ~EastCCW();

		/**
		 * @brief float값을 리턴한다.
		 * @return EastCCW 객체의 float값
		 */
		float getValue() const;
		/**
		 * @brief radian 값을 리턴한다.
		 * @return EastCCW 객체의 float값
		 */
		float getRadian() const;

		const EastCCW operator!() const;
		bool operator==(const EastCCW& eccw) const;
		bool operator!=(const EastCCW& eccw) const;
		EastCCW& operator=(const float value);
		EastCCW& operator=(const EastCCW& eccw);
		EastCCW& operator+=(const float value);
		EastCCW& operator+=(const EastCCW& eccw);
		EastCCW& operator-=(const float value);
		EastCCW& operator-=(const EastCCW& eccw);
		EastCCW& operator*=(const float value);
		EastCCW& operator*=(const EastCCW& eccw);
		EastCCW& operator/=(const float value);
		EastCCW& operator/=(const EastCCW& eccw);
		/**
		 * @brief value만큼 시계반대방향으로 조정한다.
		 */
		EastCCW& operator<<=(const float value);
		/**
		 * @brief eccw만큼 시계반대방향으로 조정한다.
		 */
		EastCCW& operator<<=(const EastCCW& eccw);
		/**
		 * @brief value만큼 시계반향으로 조정한다.
		 */
		EastCCW& operator>>=(const float value);
		/**
		 * @brief eccw만큼 시계반향으로 조정한다.
		 */
		EastCCW& operator>>=(const EastCCW& eccw);
		const EastCCW operator+(const EastCCW& eccw) const;
		const EastCCW operator-(const EastCCW& eccw) const;

		virtual const std::string toString() const;
};

const EastCCW operator+(const EastCCW& eccw, const float value);
const EastCCW operator+(const float value, const EastCCW& eccw);
const EastCCW operator-(const EastCCW& eccw, const float value);
const EastCCW operator-(const float value, const EastCCW& eccw);
const EastCCW operator*(const EastCCW& eccw, const float value);
const EastCCW operator*(const float value, const EastCCW& eccw);
const EastCCW operator/(const EastCCW& eccw, const float value);
const EastCCW operator/(const float value, const EastCCW& eccw);
const EastCCW operator<<(const EastCCW& eccw, const float value);
const EastCCW operator<<(const float value, const EastCCW& eccw);
const EastCCW operator>>(const EastCCW& eccw, const float value);
const EastCCW operator>>(const float value, const EastCCW& eccw);

#endif /* _EastCCW_H */
