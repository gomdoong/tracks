/**
 * @file NSEW.h
 * NSEW 클래스 선언
 *
 * @author walker(jeonyb@gmail.com)
 */
#ifndef _NSEW_H
#define _NSEW_H

#include "Object.h"

/**
 * @brief 동서남북을 표현하기 위한 클래스
 * @details 직접 생성할 수 없으며,
 *          이미 생성되어 있는 public static const 인스턴스인
 *          NSEW::NORTH, NSEW::EAST, NSEW::SOUTH, NSEW::WEST를 사용하면 된다 
 */
class NSEW : public Object
{
	public:
		typedef enum _VALUE {
			VALUE_NORTH = 0, /**< 북 */
			VALUE_EAST,      /**< 동 */
			VALUE_SOUTH,     /**< 남 */
			VALUE_WEST,      /**< 서 */
		} VALUE;

	private:
		VALUE value;

		NSEW(VALUE);

		static const char STR_NORTH[];
		static const char STR_EAST[];
		static const char STR_SOUTH[];
		static const char STR_WEST[];

	public:
		static const NSEW NORTH;
		static const NSEW EAST;
		static const NSEW SOUTH;
		static const NSEW WEST;

		NSEW(const NSEW& nsew);
		virtual ~NSEW();

		/**
		 * @brief NSEW::VALUE 타입 값을 반환한다
		 * @details enum 데이터형으로 다루고자 할때 사용한다.
		 * @code
		 * void function(NSEW nsew) {
		 *     switch(nsew.getValue()) {
		 *	       case NSEW::VALUE_NORTH:
		 *             ...
		 *             break;
		 *         case NSEW::VALUE_EAST:
		 *             ...
		 *             break;
		 *         ...
		 *     }
		 * }
		 * @endcode
		 */
		VALUE getValue() const;
		int getEastCCWInt() const;
		int getPolarCWInt() const;

		/**
		 * @brief 반대 방향의 값을 반환한다.
		 * @details 예를들어 !NSEW::NORTH는 NSEW::SOUTH이다.
		 */
		const NSEW operator!() const;
		bool operator==(const NSEW& nsew) const;
		bool operator!=(const NSEW& nsew) const;
		NSEW& operator=(const NSEW& nsew);
		/**
		 * @brief 시계방향으로 90도씩 value번 회전한다.
		 * @code
		 * NSEW nsew = NSEW::NORTH;
		 * nsew += 3; // nsew는 NSEW::WEST가 된다.
		 * @endcode
		 */
		NSEW& operator+=(int value);
		/**
		 * @brief 시계반대방향으로 90도씩 value번 회전한다.
		 * @code
		 * NSEW nsew = NSEW::NORTH;
		 * nsew -= 3; // nsew는 NSEW::EAST가 된다.
		 * @endcode
		 */
		NSEW& operator-=(int value);
		/**
		 * @brief 시계방향으로 90도씩 value번 회전한다.
		 * @details += 연산자와 같다.
		 */
		NSEW& operator>>=(int value);
		/**
		 * @brief 시계방향으로 90도씩 value번 회전한다.
		 * @details -= 연산자와 같다.
		 */
		NSEW& operator<<=(int value);
		/**
		 * @brief 시계방향으로 90도씩 회전한다.
		 * @code
		 * NSEW nsew = NSEW::NORTH;
		 * ++nsew; // nsew는 NSEW::EAST가 된다.
		 * @endcode
		 */
		NSEW& operator++();
		/**
		 * @brief 시계반대방향으로 90도씩 회전한다.
		 * @code
		 * NSEW nsew = NSEW::NORTH;
		 * --nsew; // nsew는 NSEW::WEST가 된다.
		 * @endcode
		 */
		NSEW& operator--();
		const NSEW operator++(int);
		const NSEW operator--(int);

		/* override */
		virtual const std::string toString() const;
};

const NSEW operator+(const NSEW& nsew, int value);
const NSEW operator+(int value, const NSEW& nsew);
const NSEW operator-(const NSEW& nsew, int value);
const NSEW operator>>(const NSEW& nsew, int value);
const NSEW operator<<(const NSEW& nsew, int value);

#endif /* _NSEW_H */
