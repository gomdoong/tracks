#include "NSEW.h"
#include "CrossTrack.h"

bool CrossTrack::_allowsEntranceFrom(const NSEW& from) const
{
	switch(from.getValue()) {
	case NSEW::VALUE_SOUTH:
	case NSEW::VALUE_NORTH:
	case NSEW::VALUE_EAST:
	case NSEW::VALUE_WEST:
		return true;
	default:
		return false;
	}
}

const NSEW CrossTrack::_getExit(const NSEW& from) const
{
	switch(from.getValue()) {
	case NSEW::VALUE_SOUTH: return NSEW::NORTH;
	case NSEW::VALUE_NORTH: return NSEW::SOUTH;
	case NSEW::VALUE_EAST: return NSEW::WEST;
	case NSEW::VALUE_WEST: default: return NSEW::EAST;
	}
}
