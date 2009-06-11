#ifndef _TriangularTrack_H
#define _TriangularTrack_H

#include "Track.h"

/**
 * @brief 'ㅜ'자 모양 트랙
 */
class TriangularTrack : public Track {
	private:
		bool _allowsEntranceFrom(const NSEW& from) const;
		const NSEW _getExit(const NSEW& from) const;
};

#endif /* _TriangularTrack_H */
