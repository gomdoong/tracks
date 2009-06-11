#include <stdexcept>

#include "NSEW.h"
#include "CornerTrack.h"

bool CornerTrack::_allowsEntranceFrom(const NSEW& from) const
{
	switch(from.getValue()) {
	case NSEW::VALUE_SOUTH:
	case NSEW::VALUE_WEST:
		return true;
	default:
		return false;
	}
}

const NSEW CornerTrack::_getExit(const NSEW& from) const
{
	switch(from.getValue()) {
	case NSEW::VALUE_SOUTH: return NSEW::WEST;
	case NSEW::VALUE_WEST: return NSEW::SOUTH;
	default: throw std::invalid_argument("from");
	}
}
