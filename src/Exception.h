/**
 * @file Exception.h
 * 예외
 *
 * @author walker(jeonyb@gmail.com)
 */
#ifndef _Exception_H
#define _Exception_H

#include "Object.h"

/**
 * @brief 예외
 */
class Exception : public Object {
	private:
		const std::string fileName;
		const std::string funcName;
		const int line;
		const std::string message;

	public:
		/**
		 * @brief 예외 생성자
		 * @details 예외가 발생한 지점의 파일명, 함수명, 줄번호를 예외 메시지와
		 *          함께 입력하여 생성한다.<BR>
		 *          _Exception(message) 매크로를 사용하여 예외 발생 지점에 대한
		 *          정보를 자동 입력하도록 할수 있다.
		 */
		Exception(const std::string& aFileName,
		          const std::string& aFuncName,
		          const int aLine,
		          const std::string& aMessage);
		Exception(const Exception& ex);
		virtual ~Exception();

		/**
		 * @brief 예외가 발생한 지점의 파일명을 리턴한다.
		 * @return 파일명
		 */
		const std::string& getFileName() const;
		/**
		 * @brief 예외가 발생한 지점의 함수명을 리턴한다.
		 * @return 함수명
		 */
		const std::string& getFuncName() const;
		/**
		 * @brief 예외가 발생한 지점의 줄번호를 리턴한다.
		 * @return 줄번호
		 */
		int getLine() const;
		/**
		 * @brief 예외 메시지를 리턴한다.
		 * @return 메시지
		 */
		const std::string& getMessage() const;
		const std::string toString() const;
};

/**
 * @brief Exception 생성자에 대한 편의 매크로
 */
#define _Exception(message) Exception(__FILE__, __FUNCTION__, __LINE__, (message))

#endif /* _Exception_H */
