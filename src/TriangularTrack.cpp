#include <stdexcept>

#include "NSEW.h"
#include "TriangularTrack.h"

bool TriangularTrack::_allowsEntranceFrom(const NSEW& from) const
{
	switch(from.getValue()) {
	case NSEW::VALUE_EAST:
	case NSEW::VALUE_WEST:
	case NSEW::VALUE_SOUTH:
		return true;
	default:
		return false;
	}
}

const NSEW TriangularTrack::_getExit(const NSEW& from) const
{
	switch(from.getValue()) {
	case NSEW::VALUE_EAST: return NSEW::WEST;
	case NSEW::VALUE_WEST: return NSEW::SOUTH;
	case NSEW::VALUE_SOUTH: return NSEW::EAST;
	default: throw std::invalid_argument("from");
	}
}

