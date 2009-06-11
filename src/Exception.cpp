/**
 * @file Exception.cpp
 * 예외
 *
 * @author walker(jeonyb@gmail.com)
 */
#include "Exception.h"

Exception::Exception(const std::string& aFileName,
                     const std::string& aFuncName,
                     const int aLine,
                     const std::string& aMessage)
: fileName(aFileName), funcName(aFuncName), line(aLine), message(aMessage)
{
}

Exception::Exception(const Exception& ex)
: fileName(ex.fileName), funcName(ex.funcName), line(ex.line)
, message(ex.message)
{
}

Exception::~Exception()
{
}

const std::string& Exception::getFileName() const
{
	return fileName;
}

const std::string& Exception::getFuncName() const
{
	return funcName;
}

int Exception::getLine() const
{
	return line;
}

const std::string& Exception::getMessage() const
{
	return message;
}

const std::string Exception::toString() const
{
	char buf[512];
	snprintf(buf, sizeof(buf), "Exception: %s in %s at %s:%d"
			, message.c_str()
			, funcName.c_str()
			, fileName.c_str()
			, line);
	return buf;
}

