#include <stdexcept>

#include "NSEW.h"
#include "LinearTrack.h"

bool LinearTrack::_allowsEntranceFrom(const NSEW& from) const
{
	switch(from.getValue()) {
	case NSEW::VALUE_SOUTH:
	case NSEW::VALUE_NORTH:
		return true;
	default:
		return false;
	}
}

const NSEW LinearTrack::_getExit(const NSEW& from) const
{
	switch(from.getValue()) {
	case NSEW::VALUE_SOUTH: return NSEW::NORTH;
	case NSEW::VALUE_NORTH: return NSEW::SOUTH;
	default: throw std::invalid_argument("from");
	}
}

