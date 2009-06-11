/**
 * @file PolarCW.h
 * PolarCW 클래스 선언
 *
 * @author walker(jeonyb@gmail.com)
 */
#ifndef _PolarCW_H
#define _PolarCW_H

#include "Object.h"

class NSEW;
class EastCCW;

/**
 * @brief 북쪽을 기준으로 시계방향으로 쟀을 때의 각도
 */
class PolarCW : public Object
{
	private:
		float value;

	public:
		PolarCW();
		PolarCW(const PolarCW& pcw);
		explicit PolarCW(const float value);
		explicit PolarCW(const NSEW& nsew);
		explicit PolarCW(const EastCCW& eccw);

		virtual ~PolarCW();

		/**
		 * @brief float값을 리턴한다.
		 * @return EastCCW 객체의 float값
		 */
		float getValue() const;

		const PolarCW operator!() const;
		bool operator==(const PolarCW& pcw) const;
		bool operator!=(const PolarCW& pcw) const;
		PolarCW& operator=(const float value);
		PolarCW& operator=(const PolarCW& pcw);
		PolarCW& operator+=(const float value);
		PolarCW& operator+=(const PolarCW& pcw);
		PolarCW& operator-=(const float value);
		PolarCW& operator-=(const PolarCW& pcw);
		PolarCW& operator*=(const float value);
		PolarCW& operator*=(const PolarCW& pcw);
		PolarCW& operator/=(const float value);
		PolarCW& operator/=(const PolarCW& pcw);
		/**
		 * @brief value만큼 시계반대방향으로 조정한다.
		 */
		PolarCW& operator<<=(const float value);
		/**
		 * @brief eccw만큼 시계반대방향으로 조정한다.
		 */
		PolarCW& operator<<=(const PolarCW& eccw);
		/**
		 * @brief value만큼 시계반향으로 조정한다.
		 */
		PolarCW& operator>>=(const float value);
		/**
		 * @brief eccw만큼 시계반향으로 조정한다.
		 */
		PolarCW& operator>>=(const PolarCW& eccw);
		const PolarCW operator+(const PolarCW& pcw) const;
		const PolarCW operator-(const PolarCW& pcw) const;

		/* override */
		virtual const std::string toString() const;
};

const PolarCW operator+(const PolarCW& pcw, const float value);
const PolarCW operator+(const float value, const PolarCW& pcw);
const PolarCW operator-(const PolarCW& pcw, const float value);
const PolarCW operator-(const float value, const PolarCW& pcw);
const PolarCW operator*(const PolarCW& pcw, const float value);
const PolarCW operator*(const float value, const PolarCW& pcw);
const PolarCW operator/(const PolarCW& pcw, const float value);
const PolarCW operator/(const float value, const PolarCW& pcw);
const PolarCW operator<<(const PolarCW& eccw, const float value);
const PolarCW operator<<(const float value, const PolarCW& eccw);
const PolarCW operator>>(const PolarCW& eccw, const float value);
const PolarCW operator>>(const float value, const PolarCW& eccw);

#endif /* _PolarCW_H */
