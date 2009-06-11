/**
 * @file Map.h
 * Map 클래스 선언
 *
 * @author walker(jeonyb@gmail.com)
 */
#ifndef _Map_H
#define _Map_H

#include "Object.h"
#include "Car.h"

class Cell;

/**
 * @brief 맵
 * @details 맵은 게임의 공간 즉 세계이며, 셀의 2차원 집합으로 구성되어 있다.
 */
class Map : public Object {
	private:
		Cell *cells;

	public:
		/**
		 * @brief 맵의 가로 사이즈(셀의 갯수)
		 */
		const int width;
		/**
		 * @brief 맵의 세로 사이즈(셀의 갯수)
		 */
		const int height;
		/**
		 * @brief 공기저항계수
		 */
		const float airResist;

		/**
		 * @brief 가로 aWidth, 세로 aHeight만큼의 셀을 가진 맵을 생성한다.
		 * @details 맵의 크기는 맵을 생성할 때만 정할수 있다.
		 * @param aWidth 가로 사이즈
		 * @param aHeight 세로 사이즈
		 * @param aAirResist 공기저항계수
		 */
		Map(const int aWidth, const int aHeight, const float aAirResist = 0.8f);
		~Map();

		/**
		 * @brief 맵을 구성하고 있는 특정 위치의 Cell을 리턴한다.
		 * @details 리턴되는 Cell은 실제 객체의 레퍼런스이므로 Map이 소멸된 후에
		 *          사용되어서는 안된다.
		 * @param x 가로 위치 (zero based)
		 * @param y 세로 위치 (zero based)
		 * @return 해당위치의 셀
		 * @exception Exception 파라미터 x 또는 y가 out of index인 경우
		 */
		Cell& getCell(const int x, const int y);
};

#endif /* _Map_H */
