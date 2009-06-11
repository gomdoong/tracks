/**
 * @file Track.h
 * Track 클래스 선언
 *
 * @author walker(jeonyb@gmail.com)
 */
#ifndef _Track_H
#define _Track_H

#include "Object.h"

class NSEW;

/**
 * @brief 모든 트랙의 상위 클래스
 */
class Track : public Object {

	private:
		virtual bool _allowsEntranceFrom(const NSEW& from) const = 0;
		virtual const NSEW _getExit(const NSEW& from) const = 0;

	protected:
		int rotation;

	public:
		Track(int rotation = 0);
		virtual ~Track();

		/**
		 * @brief 트랙을 90도씩 rotation번 회전된 상태로 만든다.
		 * @details rotation이 양수이면 시계방향으로
		 *          음수이면 시계반대방향으로 회전한다.
		 *          단, turnRight() 메소드와 달리 현재 회전되어있는 상태는
		 *          무시하고, 회전되어있지 않은 상태에서 회전을 시작한다.
		 * @param rotation 회전 값, 90도 단위
		 */
		void setRotation(int rotation);
		/**
		 * @brief 현재 rotation 값을 되돌린다.
		 * @details rotation 값의 의미는 트랙이 90도씩 rotation번 회전되어
		 *          있음을 뜻한다.
		 *          rotation이 양수이면 시계방향으로
		 *          음수이면 시계반대방향으로 회전된 상태이다.
		 *          예를들어 rotation이 3이면 시계방향으로 270도만큼 회전된
		 *          상태이다.
		 */
		int getRotation() const;
		/**
		 * @brief 트랙을 현재 상태에서 시계방향으로 90도만큼 추가 회전한다.
		 * @details 이 메소드를 세번 호출했을 경우 setRotation(3)을 한것과 같다.
		 */
		void turnRight();
		/**
		 * @brief 트랙을 현재 상태에서 시계반대방향으로 90도만큼 추가 회전한다.
		 * @details 이 메소드를 세번 호출했을 경우 setRotation(-3)을 한것과
		 *          같다.
		 */
		void turnLeft();

		/**
		 * @brief from 방향에서 해당 트랙에 들어올 수 있는지를 확인한다.
		 * @details 서브클래스에서는 이 메소드를 override 하는 대신
		 *          private 메소드인 _allowsEntranceFrom(const NSEW&) 메소드
		 *          (이하 _allows...)를 구현하되,
		 *          이때 rotation 값은 고려하지 않고, 즉 회전되어있지
		 *          않다는 가정에서 결과를 리턴하도록 하면된다.<BR>
		 *          allows... 메소드는 실질적으로 _allows... 메소드의
		 *          래퍼함수이며 _allows... 메소드의 호출 전후에서
		 *          rotation 값에 따라 추가적인 처리를 해준다.
		 * @param from 들어오는 방향
		 * @return 들어올수 있으면 true, 그외는 false
		 */
		bool allowsEntranceFrom(const NSEW& from) const;
		/**
		 * @brief from 방향에서 해당 트랙에 들어왔을 때 출구 방향을 리턴한다.
		 * @details 서브클래스에서는 이 메소드를 override 하는 대신
		 *          private 메소드인 _getExit(const NSEW&) 메소드를 구현하되,
		 *          이때 rotation 값은 고려하지 않고, 즉 회전되어있지
		 *          않다는 가정에서 결과를 리턴하도록 하면된다.<BR>
		 *          getExit 메소드는 실질적으로 _getExit 메소드의
		 *          래퍼함수이며 _getExit 메소드의 호출 전후에서
		 *          rotation 값에 따라 추가적인 처리를 해준다.
		 * @param from 들어오는 방향
		 * @return 들어올수 있으면 true, 그외는 false
		 */
		const NSEW getExit(const NSEW& from) const;
};

#endif /* _Track_H */
