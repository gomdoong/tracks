/**
 * @file Object.h
 * Object 클래스 선언
 *
 * @author walker(jeonyb@gmail.com)
 */
#ifndef _Object_H
#define _Object_H

#include <string>

/** @brief 최상위 클래스
 */
class Object
{
	public:
		/**
		 * @brief 객체를 문자열로 표현해준다.
		 * @details 단, 문자열이 객체를 대신할 수 있거나 문자열을 다시 객체로
		 *          변환할 수 있는 것은 아니다. 대부분 user friendly한 출력을
		 *          위해 사용한다.
		 */
		virtual const std::string toString() const;
};

#endif /* _Object_H */
