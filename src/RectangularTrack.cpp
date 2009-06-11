#include "NSEW.h"
#include "RectangularTrack.h"

bool RectangularTrack::_allowsEntranceFrom(const NSEW& from) const
{
	switch(from.getValue()) {
	case NSEW::VALUE_NORTH:
	case NSEW::VALUE_EAST:
	case NSEW::VALUE_WEST:
	case NSEW::VALUE_SOUTH:
		return true;
	default:
		return false;
	}
}

const NSEW RectangularTrack::_getExit(const NSEW& from) const
{
	switch(from.getValue()) {
	case NSEW::VALUE_NORTH: return NSEW::WEST;
	case NSEW::VALUE_EAST: return NSEW::NORTH;
	case NSEW::VALUE_WEST: return NSEW::SOUTH;
	case NSEW::VALUE_SOUTH: default: return NSEW::EAST;
	}
}
