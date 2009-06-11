#include <stdexcept>

#include "TracksTestCase.h"
#include "NSEW.h"
#include "LinearTrack.h"
#include "CornerTrack.h"
#include "TriangularTrack.h"
#include "RectangularTrack.h"
#include "CrossTrack.h"
#include "Map.h"
#include "Cell.h"
#include "CarTrait.h"
#include "Car.h"
#include "XYPair.h"

void TracksTestCase::testNSEW()
{
	NSEW nsew = NSEW::NORTH;
	CPPUNIT_ASSERT(nsew == NSEW::NORTH);
	CPPUNIT_ASSERT(nsew != NSEW::EAST);
	CPPUNIT_ASSERT(nsew != NSEW::SOUTH);
	CPPUNIT_ASSERT(nsew != NSEW::WEST);
	CPPUNIT_ASSERT(!nsew == NSEW::SOUTH);
	CPPUNIT_ASSERT(!nsew != NSEW::NORTH);
	CPPUNIT_ASSERT(!nsew != NSEW::EAST);
	CPPUNIT_ASSERT(!nsew != NSEW::WEST);
	CPPUNIT_ASSERT(nsew << 1 == NSEW::WEST);
	CPPUNIT_ASSERT(nsew << 2 == NSEW::SOUTH);
	CPPUNIT_ASSERT(nsew << 3 == NSEW::EAST);
	CPPUNIT_ASSERT(nsew << 4 == NSEW::NORTH);
	CPPUNIT_ASSERT(nsew << 5 == NSEW::WEST);
	CPPUNIT_ASSERT(nsew >> 1 == NSEW::EAST);
	CPPUNIT_ASSERT(nsew >> 2 == NSEW::SOUTH);
	CPPUNIT_ASSERT(nsew >> 3 == NSEW::WEST);
	CPPUNIT_ASSERT(nsew >> 4 == NSEW::NORTH);
	CPPUNIT_ASSERT(nsew >> 5 == NSEW::EAST);
	CPPUNIT_ASSERT(nsew << -1 == NSEW::EAST);
	CPPUNIT_ASSERT(nsew >> -1 == NSEW::WEST);
	CPPUNIT_ASSERT(nsew.getValue() == NSEW::VALUE_NORTH);
	CPPUNIT_ASSERT(nsew.getValue() != NSEW::VALUE_EAST);
}

void TracksTestCase::testEastCCW()
{
	EastCCW e = (EastCCW) 30.0f;
	CPPUNIT_ASSERT(e + 30.0f == static_cast<EastCCW>(60.0f));
	e <<= 0.5f;
	CPPUNIT_ASSERT(e == static_cast<EastCCW>(30.5f));
}

void TracksTestCase::testTracks()
{
	LinearTrack lt;
	lt.turnRight();
	CPPUNIT_ASSERT(lt.getRotation() == 1);
	CPPUNIT_ASSERT(lt.allowsEntranceFrom(NSEW::NORTH) == false);
	CPPUNIT_ASSERT(lt.allowsEntranceFrom(NSEW::SOUTH) == false);
	CPPUNIT_ASSERT(lt.allowsEntranceFrom(NSEW::EAST) == true);
	CPPUNIT_ASSERT(lt.allowsEntranceFrom(NSEW::WEST) == true);
	CPPUNIT_ASSERT_THROW(lt.getExit(NSEW::NORTH), std::invalid_argument);
	CPPUNIT_ASSERT_THROW(lt.getExit(NSEW::SOUTH), std::invalid_argument);
	CPPUNIT_ASSERT(lt.getExit(NSEW::EAST) == NSEW::WEST);
	CPPUNIT_ASSERT(lt.getExit(NSEW::WEST) == NSEW::EAST);

	CornerTrack ct;
	ct.turnLeft();
	CPPUNIT_ASSERT(ct.getRotation() == 3);
	CPPUNIT_ASSERT(ct.allowsEntranceFrom(NSEW::NORTH) == false);
	CPPUNIT_ASSERT(ct.allowsEntranceFrom(NSEW::SOUTH) == true);
	CPPUNIT_ASSERT(ct.allowsEntranceFrom(NSEW::EAST) == true);
	CPPUNIT_ASSERT(ct.allowsEntranceFrom(NSEW::WEST) == false);
	CPPUNIT_ASSERT_THROW(ct.getExit(NSEW::NORTH), std::invalid_argument);
	CPPUNIT_ASSERT(ct.getExit(NSEW::SOUTH) == NSEW::EAST);
	CPPUNIT_ASSERT(ct.getExit(NSEW::EAST) == NSEW::SOUTH);
	CPPUNIT_ASSERT_THROW(ct.getExit(NSEW::WEST), std::invalid_argument);

	TriangularTrack tt;
	tt.setRotation(2);
	CPPUNIT_ASSERT(tt.getRotation() == 2);
	CPPUNIT_ASSERT(tt.allowsEntranceFrom(NSEW::NORTH) == true);
	CPPUNIT_ASSERT(tt.allowsEntranceFrom(NSEW::SOUTH) == false);
	CPPUNIT_ASSERT(tt.allowsEntranceFrom(NSEW::EAST) == true);
	CPPUNIT_ASSERT(tt.allowsEntranceFrom(NSEW::WEST) == true);
	CPPUNIT_ASSERT(tt.getExit(NSEW::NORTH) == NSEW::WEST);
	CPPUNIT_ASSERT_THROW(tt.getExit(NSEW::SOUTH), std::invalid_argument);
	CPPUNIT_ASSERT(tt.getExit(NSEW::EAST) == NSEW::NORTH);
	CPPUNIT_ASSERT(tt.getExit(NSEW::WEST) == NSEW::EAST);

	RectangularTrack rt;
	rt.turnRight();
	rt.turnLeft();
	rt.turnLeft();
	CPPUNIT_ASSERT(rt.getRotation() == 3);
	CPPUNIT_ASSERT(rt.allowsEntranceFrom(NSEW::NORTH) == true);
	CPPUNIT_ASSERT(rt.allowsEntranceFrom(NSEW::SOUTH) == true);
	CPPUNIT_ASSERT(rt.allowsEntranceFrom(NSEW::EAST) == true);
	CPPUNIT_ASSERT(rt.allowsEntranceFrom(NSEW::WEST) == true);
	CPPUNIT_ASSERT(rt.getExit(NSEW::NORTH) == NSEW::WEST);
	CPPUNIT_ASSERT(rt.getExit(NSEW::SOUTH) == NSEW::EAST);
	CPPUNIT_ASSERT(rt.getExit(NSEW::EAST) == NSEW::NORTH);
	CPPUNIT_ASSERT(rt.getExit(NSEW::WEST) == NSEW::SOUTH);

	CrossTrack st;
	st.turnRight();
	st.turnRight();
	CPPUNIT_ASSERT(st.getRotation() == 2);
	CPPUNIT_ASSERT(st.allowsEntranceFrom(NSEW::NORTH) == true);
	CPPUNIT_ASSERT(st.allowsEntranceFrom(NSEW::SOUTH) == true);
	CPPUNIT_ASSERT(st.allowsEntranceFrom(NSEW::EAST) == true);
	CPPUNIT_ASSERT(st.allowsEntranceFrom(NSEW::WEST) == true);
	CPPUNIT_ASSERT(st.getExit(NSEW::NORTH) == NSEW::SOUTH);
	CPPUNIT_ASSERT(st.getExit(NSEW::SOUTH) == NSEW::NORTH);
	CPPUNIT_ASSERT(st.getExit(NSEW::EAST) == NSEW::WEST);
	CPPUNIT_ASSERT(st.getExit(NSEW::WEST) == NSEW::EAST);
}

void TracksTestCase::testMap()
{
	Map map(10,10);
	CPPUNIT_ASSERT_THROW(map.getCell(10,10), std::out_of_range);
	Cell& cell = map.getCell(9,9);
	CPPUNIT_ASSERT(cell.getAdjacentCell(NSEW::NORTH) == &map.getCell(9,8));
	CPPUNIT_ASSERT(cell.getAdjacentCell(NSEW::SOUTH) == NULL);
	CPPUNIT_ASSERT(cell.getAdjacentCell(NSEW::EAST) == NULL);
	CPPUNIT_ASSERT(cell.getAdjacentCell(NSEW::WEST) == &map.getCell(8,9));
}

void TracksTestCase::testXYPair()
{
	XYPair<float> a(2.2f, 4);
	CPPUNIT_ASSERT(a.x == 2.2f);
	CPPUNIT_ASSERT(a.y == 4.0f);

	XYPair<float> b = a;
	CPPUNIT_ASSERT(b.x == 2.2f);
	CPPUNIT_ASSERT(b.y == 4.0f);

	b += 1;
	CPPUNIT_ASSERT(b.x == 3.2f);
	CPPUNIT_ASSERT(b.y == 5.0f);

	b *= 2;
	CPPUNIT_ASSERT(b.x == 6.4f);
	CPPUNIT_ASSERT(b.y == 10.0f);

	b -= 1;
	CPPUNIT_ASSERT(b.x == 5.4f);
	CPPUNIT_ASSERT(b.y == 9.0f);

	b /= 2;
	CPPUNIT_ASSERT(b.x == 2.7f);
	CPPUNIT_ASSERT(b.y == 4.5f);

	CPPUNIT_ASSERT((b - a).x == 0.5f);
	CPPUNIT_ASSERT((b + a).y == 8.5f);

	a = 3;
	CPPUNIT_ASSERT((b * a).x == 8.1f);
	CPPUNIT_ASSERT((b / a).y == 1.5f);
}

void TracksTestCase::testCar()
{
	CarTrait trait;
	trait.f_advance = 2;
	Car car(trait);
	car.bodyHeading = 0;
	XYPair<float> acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x == 2);
	CPPUNIT_ASSERT(acc.y == 0);
	XYPair<float> before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;

	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x < before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;

	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y < before.y);
	before = acc;

	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
	car.bodyHeading += 10;
	acc = car.getAcceleration();
	CPPUNIT_ASSERT(acc.x > before.x);
	CPPUNIT_ASSERT(acc.y > before.y);
	before = acc;
}
