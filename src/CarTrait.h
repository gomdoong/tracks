/**
 * @file CarTrait.h
 * CarTrait 클래스의 선언
 *
 * @author walker(jeonyb@gmail.com)
 */
#ifndef _CarTrait_H
#define _CarTrait_H

/**
 * @brief 차 속성
 */
class CarTrait
{
	public:
		/**
		 * @brief 구동방식
		 */
		typedef enum _DRIVING_SYSTEM {
			FWD = 0, /**< 전륜구동 */
			RWD,     /**< 후륜구동 */
		} DRIVING_SYSTEM;

		/**
		 * @brief 구동방식
		 * @details 기본값 FWD
		 */
		DRIVING_SYSTEM drivingSystem;
		/**
		 * @brief 질량
		 * @details 기본값 1.0f
		 */
		float m;
		/**
		 * @brief 전진 구동력
		 * @details 기본값 1.0f
		 */
		float f_advance;
		/**
		 * @brief 후진 구동력
		 * @details 기본값 1.0f
		 */
		float f_reverse;
		/**
		 * @brief 타이어 마찰 계수
		 * @details 0과 1 사이의 값. 1에 가까울 수록 마찰력이 그대로 작용<BR>
		 *          작용 마찰력 = u_wheel * m * g<BR>
		 *          기본값 0.9f
		 */
		float u_wheel;
		/**
		 * @brief 무게중심
		 * @details 0과 1 사이의 값. 0에 가까울 수록 앞쪽이 무겁고
		 *          1에 가까울 수록 뒤쪽이 무겁다.<BR>
		 *          기본값 0.9f
		 */
		float balance;
		/**
		 * @brief 바퀴의 최대 회전각 (절대값)
		 * @details -wheelMaxAngle <= 바퀴의 회전각 <= wheelMaxAngle
		 */
		float wheelMaxAngle;

		CarTrait();
		CarTrait(const CarTrait& trait);
		virtual ~CarTrait();
		
};

#endif /* _CarTrait_H */
