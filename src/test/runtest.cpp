#include <cppunit/ui/text/TestRunner.h>

#include "TracksTestCase.h"

int main(int, char **)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TracksTestCase::suite());
	bool wasSuccessful = runner.run();
	return !wasSuccessful;
}
