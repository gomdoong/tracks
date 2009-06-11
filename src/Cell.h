/**
 * @file Cell.h
 * Cell 클래스 선언
 *
 * @author walker(jeonyb@gmail.com)
 */
#ifndef _Cell_H
#define _Cell_H

#include "Track.h"

/**
 * @brief 셀
 * @details Map을 구성하는 단위.
 *          트랙,건물 등의 오브젝트를 넣을 수 있다.
 */
class Cell : public Object {
	private:
		const Track* pTrack;
		const Cell* northern;
		const Cell* southern;
		const Cell* eastern;
		const Cell* western;

	public:
		Cell();
		virtual ~Cell();

		/**
		 * @brief 셀에 트랙을 넣는다.
		 * @param track 트랙
		 * @see removeTrack()
		 */
		void setTrack(const Track& track);
		/**
		 * @brief 셀에 있는 트랙을 리턴한다.
		 * @details 셀에 트랙이 없으면 예외를 발생시킨다
		 * @return 트랙
		 * @exception std::bad_exception 셀에 트랙이 없을 경우
		 */
		const Track& getTrack();
		/**
		 * @brief 셀에 트랙이 있는지 확인한다.
		 * @details 셀에 트랙이 있는지 확실치 않다면 getTrack()하기전에 트랙이
		 *          있는지 확인하여야 한다.
		 * @return  트랙이 있으면 true, 없으면 false
		 */
		bool hasTrack();
		/**
		 * @brief 셀이 가지고 있는 트랙에 대한 참조를 초기화한다.
		 * @details 셀에 넣은 트랙을 소멸시키기 전에 removeTrack()을 먼저
		 *          해주어야 한다. 그렇지 않으면 getTrack() 메소드가
		 *          소멸된 트랙의 레퍼런스를 리턴할 것이다.
		 */
		void removeTrack();
		/**
		 * @brief 동서남북 방향으로 인접한 셀을 등록한다.
		 */
		void setAdjacentCells(const Cell* const aNorthern,
		                      const Cell* const aSouthern,
		                      const Cell* const aEastern,
		                      const Cell* const aWestern);
		/**
		 * @brief where 방향에 인접한 셀을 리턴한다.
		 * @param where 방향
		 * @return 셀, 없을 경우 NULL.
		 */
		const Cell* getAdjacentCell(const NSEW& where);
};

#endif /* _Cell_H */
