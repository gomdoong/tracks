#ifndef _LinearTrack_H
#define _LinearTrack_H

#include "Track.h"

/**
 * @brief '1'자 모양 트랙
 */
class LinearTrack : public Track {
	private:
		bool _allowsEntranceFrom(const NSEW& from) const;
		const NSEW _getExit(const NSEW& from) const;
};

#endif /* _LinearTrack_H */
