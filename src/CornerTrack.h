#ifndef _CornerTrack_H
#define _CornerTrack_H

#include "Track.h"

/**
 * @brief 'ㄱ'자 모양 트랙
 */
class CornerTrack : public Track {
	private:
		bool _allowsEntranceFrom(const NSEW& from) const;
		const NSEW _getExit(const NSEW& from) const;
};

#endif /* _CornerTrack_H */
