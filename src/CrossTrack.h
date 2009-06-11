#ifndef _CrossTrack_H
#define _CrossTrack_H

#include "Track.h"

/**
 * @brief '+'자 모양 트랙 (직진)
 */
class CrossTrack : public Track {
	private:
		bool _allowsEntranceFrom(const NSEW& from) const;
		const NSEW _getExit(const NSEW& from) const;
};

#endif /* _CrossTrack_H */
