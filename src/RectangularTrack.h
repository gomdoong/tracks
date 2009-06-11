#ifndef _RectangularTrack_H
#define _RectangularTrack_H

#include "Track.h"

/**
 * @brief '+'자 모양 트랙
 */
class RectangularTrack : public Track {
	private:
		bool _allowsEntranceFrom(const NSEW& from) const;
		const NSEW _getExit(const NSEW& from) const;
};

#endif /* _RectangularTrack_H */
