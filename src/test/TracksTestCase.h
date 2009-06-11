#ifndef _TracksTestCase_H
#define _TracksTestCase_H

#include <cppunit/extensions/HelperMacros.h>

class TracksTestCase : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TracksTestCase);
	CPPUNIT_TEST(testNSEW);
	CPPUNIT_TEST(testEastCCW);
	CPPUNIT_TEST(testTracks);
	CPPUNIT_TEST(testMap);
	CPPUNIT_TEST(testXYPair);
	CPPUNIT_TEST(testCar);
	CPPUNIT_TEST_SUITE_END();

	public:
		void testNSEW();
		void testEastCCW();
		void testTracks();
		void testMap();
		void testXYPair();
		void testCar();
};
#endif
